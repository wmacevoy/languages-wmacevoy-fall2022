#include "token.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Token, Types) {
  ASSERT_EQ(calc::Token::unknown("$")->type,calc::Token::UNKNOWN);
  ASSERT_EQ(calc::Token::add()->type,calc::Token::ADD);
  ASSERT_EQ(calc::Token::sub()->type,calc::Token::SUB);
  ASSERT_EQ(calc::Token::mul()->type,calc::Token::MUL);
  ASSERT_EQ(calc::Token::div()->type,calc::Token::DIV);
  ASSERT_EQ(calc::Token::lp()->type,calc::Token::LP);
  ASSERT_EQ(calc::Token::rp()->type,calc::Token::RP);
  ASSERT_EQ(calc::Token::num("33.3")->type,calc::Token::NUM);
  ASSERT_EQ(calc::Token::eol()->type,calc::Token::EOL);
  ASSERT_EQ(calc::Token::end()->type,calc::Token::END);
}

TEST(Token,Number) {
  calc::Token::Ptr tk = calc::Token::num("33.3");
  ASSERT_NEAR(tk->num(),33.3,1e-12);
}
