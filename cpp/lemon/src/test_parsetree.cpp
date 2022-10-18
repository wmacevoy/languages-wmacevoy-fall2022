#include "parsetree.h"
#include "gtest/gtest.h"

TEST(ParseTree,EAdd) {
  calc::Token::Ptr tkTwo = calc::Token::num("2");
  calc::Token::Ptr tkAdd = calc::Token::add();
  calc::Token::Ptr tkFive = calc::Token::num("5");
  
  calc::ParseTree::Ptr ptFTwo = calc::ParseTree::f_num(tkTwo);
  calc::ParseTree::Ptr ptTTwo = calc::ParseTree::t_f(ptFTwo);
  calc::ParseTree::Ptr ptETwo = calc::ParseTree::e_t(ptETwo);
  calc::ParseTree::Ptr ptFFive = calc::ParseTree::f_num(tkFive);
  calc::ParseTree::Ptr ptTFive = calc::ParseTree::t_f(ptFFive);
  calc::ParseTree::Ptr ptETwoPlusFive = calc::ParseTree::e_add(ptETwo,tkAdd,ptTFive);
}
