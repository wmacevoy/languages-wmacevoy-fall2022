%define api.value.type {calc::ParseTree::Sub}
%define api.pure full
%define api.push-pull push
%parse-param  { calc::Parser *me }

%{
#include <iostream>
#include <sstream>
#include "token.h"
#include "parsetree.h"
#include "parser.h"

using namespace calc;

 void yyerror(Parser *me, const char *msg) {
   std::ostringstream oss;
   oss << me->lexer->file << " " << me->lexer->line << " " << me->lexer->column << ": " << msg;
   throw std::range_error(oss.str());
 }
%}


%token ADD SUB MUL DIV LP RP NUM ID EOL

%left ADD SUB
%left MUL DIV

%%
program
  : program EOL statement
  | statement
  ;

statement
  : /* empty */
  | e { ParseTree::Vars vars; auto E = std::get<ParseTree::Ptr>($1); std::cout << E->eval(vars) << std::endl; }
  ;

e : e ADD t { $$ = ParseTree::e_add($1,$2,$3); }
  | t       { $$ = ParseTree::e_t($1); }
  ;

t : t MUL f { $$ = ParseTree::t_mul($1,$2,$3); }
  | f       { $$ = ParseTree::t_f($1); }
  ;

f : NUM     { $$ = ParseTree::f_num($1); }
  | ID      { $$ = ParseTree::f_id($1); }
  | LP e RP { $$ = ParseTree::f_e($1,$2,$3); }
  ;

%%

namespace calc {
  
  Parser::Parser(Lexer::Ptr _lexer) : lexer(_lexer) {
    yyps = (void*) yypstate_new();
  }

  Parser::~Parser() {
    yypstate_delete((yypstate*)(yyps));
  }
  
  ParseTree::Ptr Parser::parse() {
    int status;
    result = nullptr;
    do {
      auto token = lexer->next();
      ParseTree::Sub stoken(token);
      status = yypush_parse ((yypstate*)(yyps), token->type, &stoken, this);
    } while (status == YYPUSH_MORE);

    return result;
  }
}
