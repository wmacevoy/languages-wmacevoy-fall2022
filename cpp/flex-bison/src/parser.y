%define api.value.type {calc::ParseTree::Sub}
%define api.pure full
%define api.push-pull push
%parse-param  { calc::Parser *me }

%{
#include "token.h"
#include "parsetree.h"
#include "parser.h"

using namespace calc;

 void yyerror(Parser *me, const char *msg) {
   throw std::range_error(msg);
 }
%}


%token ADD SUB MUL DIV LP RP NUM EOL END

%left ADD SUB
%left MUL DIV

%%
s : e { me->result = std::get<ParseTree::Ptr>($1); }
  ;

e : e ADD t { $$ = ParseTree::e_add($1,$2,$3); }
  | t       { $$ = ParseTree::e_t($1); }
  ;

t : f       { $$ = ParseTree::t_f($1); }
  ;

f : NUM     { $$ = ParseTree::f_num($1); }
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
      ParseTree::Sub value(token);
      status = yypush_parse ((yypstate*)(yyps), token->type, &value, this);
    } while (status == YYPUSH_MORE);

    return result;
  }
}
