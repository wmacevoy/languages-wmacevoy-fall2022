#include <iostream>
#include "token.h"
#include "lexer.h"
#include "gtest/gtest.h"

TEST(Lexer,Example1) {
  calc::Lexer::Ptr lexer(new calc::Lexer("example1.calc"));
  ASSERT_EQ(lexer->next()->type,calc::Token::NUM);
  ASSERT_EQ(lexer->next()->type,calc::Token::ADD);
  ASSERT_EQ(lexer->next()->type,calc::Token::NUM);
  ASSERT_EQ(lexer->next()->type,calc::Token::EOL);
  ASSERT_EQ(lexer->next()->type,calc::Token::END);
}
