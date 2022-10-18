#include <cassert>
#include "parsetree.h"

namespace calc {
  ParseTree::ParseTree(Type _type)
    : type(_type), subs(0)
  {
  }

  ParseTree::ParseTree(Type _type, Sub sub0)
    : type(_type), subs(1)
  {
    subs.at(0)=sub0;
  }  
  ParseTree::ParseTree(Type _type, Sub sub0, Sub sub1)
    : type(_type), subs(2)
  {
    subs.at(0)=sub0;
    subs.at(1)=sub1;
  }  

  ParseTree::ParseTree(Type _type, Sub sub0, Sub sub1, Sub sub2)
    : type(_type), subs(3)
  {
    subs.at(0)=sub0;
    subs.at(1)=sub1;
    subs.at(2)=sub2;
  }  
  
  // E->E+T
  ParseTree::Ptr ParseTree::e_add(Sub e, Sub add, Sub t) {
    assert(std::get<ParseTree::Ptr>(e)->type == E);
    assert(std::get<Token::Ptr>(add)->type == Token::ADD);
    assert(std::get<ParseTree::Ptr>(t)->type == T);
      
    return Ptr(new ParseTree(E,e,add,t));
  }

  // E->T
  ParseTree::Ptr ParseTree::e_t(Sub t) {
    assert(std::get<ParseTree::Ptr>(t)->type == T);
      
    return Ptr(new ParseTree(E,t));
  }

  // T->F
  ParseTree::Ptr ParseTree::t_f(Sub f) {
    assert(std::get<ParseTree::Ptr>(f)->type == F);
      
    return Ptr(new ParseTree(T,f));
  }

  // F->num
  ParseTree::Ptr ParseTree::f_num(Sub num) {
    assert(std::get<Token::Ptr>(num)->type == Token::NUM);
      
    return Ptr(new ParseTree(F,num));
  }
  
}
