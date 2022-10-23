#include <iostream>
#include "token.h"
#include "lexer.h"
#include "parser.h"
#include "gtest/gtest.h"

TEST(Parser,Example1) {
  calc::Lexer::Ptr lexer(new calc::Lexer("example1.calc"));
  calc::Parser::Ptr parser(new calc::Parser(lexer));

  calc::ParseTree::Ptr parsetree = parser->parse();

  calc::ParseTree::Vars vars;

  vars["X"] = 10.0;

  ASSERT_EQ(parsetree->eval(vars), 3.0);
}
