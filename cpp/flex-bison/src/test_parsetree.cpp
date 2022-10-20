#include "parsetree.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
using namespace calc;

#define TEST_TREE(BUILD,TYPE,VALUE) \
  {									\
    calc::ParseTree::Vars vars; vars["X"]=10;				\
    ASSERT_EQ(strcmp(calc::ParseTree::strtype(calc::ParseTree::TYPE),#TYPE),0); \
    ASSERT_EQ(calc::ParseTree::BUILD->type,calc::ParseTree::TYPE);	\
    ASSERT_EQ(calc::ParseTree::BUILD->eval(vars),VALUE); \
  }


TEST(ParseTree,f_num) {
  auto tk3=Token::num("3");
  TEST_TREE(f_num(tk3),F,3.0);
}

TEST(ParseTree,f_id) {
  auto tkX=Token::id("X");
  TEST_TREE(f_id(tkX),F,10.0);
}

TEST(ParseTree,t_f) {
  auto tk3=Token::num("3");
  auto f3=ParseTree::f_num(tk3);
  TEST_TREE(t_f(f3),T,3.0);
}

TEST(ParseTree,e_t) {
  auto tk3=Token::num("3");
  auto f3=ParseTree::f_num(tk3);
  auto t3=ParseTree::t_f(f3);
  TEST_TREE(e_t(t3),E,3.0);
}

TEST(ParseTree,f_e) {
  auto tk3=Token::num("3");
  auto f3=ParseTree::f_num(tk3);
  auto t3=ParseTree::t_f(f3);
  auto e3=ParseTree::e_t(t3);
  auto tkLp=Token::lp();
  auto tkRp=Token::rp();
  TEST_TREE(f_e(tkLp,e3,tkRp),F,3.0);
}

TEST(ParseTree,e_add) {
  auto tk3=Token::num("3");
  auto f3=ParseTree::f_num(tk3);
  auto t3=ParseTree::t_f(f3);
  auto e3=ParseTree::e_t(t3);

  auto tkX=Token::id("X");
  auto fX=ParseTree::f_id(tkX);
  auto tX=ParseTree::t_f(fX);
  auto eX=ParseTree::e_t(tX);

  auto add=Token::add();

  TEST_TREE(e_add(e3,add,tX),E,13.0);
}
