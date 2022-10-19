#include <cassert>
#include "parsetree.h"

namespace calc {

  const char *ParseTree::strtype(Type type) {
    switch(type) {
    case E: return "E";
    case T: return "T";
    case F: return "F";
    default: return "?";
    }
  }
  
  double ParseTree::eval(Vars &vars) const { return evaluator(*this,vars); }
  
  ParseTree::ParseTree(Type _type, Evaluator _evaluator)
    : type(_type), evaluator(_evaluator), subs(0)
  {
  }

  ParseTree::ParseTree(Type _type, Evaluator _evaluator, Sub sub0)
    : type(_type), evaluator(_evaluator), subs(1)
  {
    subs.at(0)=sub0;
  }  
  ParseTree::ParseTree(Type _type, Evaluator _evaluator, Sub sub0, Sub sub1)
    : type(_type), evaluator(_evaluator), subs(2)
  {
    subs.at(0)=sub0;
    subs.at(1)=sub1;
  }  

  ParseTree::ParseTree(Type _type, Evaluator _evaluator, Sub sub0, Sub sub1, Sub sub2)
    : type(_type), evaluator(_evaluator), subs(3)
  {
    subs.at(0)=sub0;
    subs.at(1)=sub1;
    subs.at(2)=sub2;
  }

  // E->E+T
  ParseTree::Ptr ParseTree::e_add(Sub e, Sub add, Sub t) {
    auto evaluator = [](const ParseTree &pt, Vars &vars) {
		       // extract sub-tree components
		       int i=0;
		       auto &e = std::get<ParseTree::Ptr>(pt.subs[i++]);
		       auto &add = std::get<Token::Ptr>(pt.subs[i++]);
		       auto &t = std::get<ParseTree::Ptr>(pt.subs[i++]);

		       assert(e->type == ParseTree::E);
		       assert(add->type == Token::ADD);
		       assert(t->type == ParseTree::T);

		       return e->eval(vars) + t->eval(vars);
		     };

    return Ptr(new ParseTree(E,evaluator,e,add,t));
  }

  // E->T
  ParseTree::Ptr ParseTree::e_t(Sub t) {
    auto evaluator = [](const ParseTree &pt, Vars &vars) {
		       // extract sub-tree components
		       int i=0;
		       auto &t = std::get<ParseTree::Ptr>(pt.subs[i++]);

		       // validate types
		       assert(t->type == ParseTree::T);

		       return t->eval(vars);
		     };
    return Ptr(new ParseTree(E,evaluator,t));
  }

  // T->F
  ParseTree::Ptr ParseTree::t_f(Sub f) {
    auto evaluator = [](const ParseTree &pt, Vars &vars) {
		       // extract sub-tree components
		       int i=0;
		       auto &f = std::get<ParseTree::Ptr>(pt.subs[i++]);

		       // validate types
		       assert(f->type == ParseTree::F);

		       return f->eval(vars);
		     };
    return Ptr(new ParseTree(T,evaluator,f));
  }

  // F->num
  ParseTree::Ptr ParseTree::f_num(Sub num) {
    auto evaluator = [](const ParseTree &pt, Vars &vars) {
		       // extract sub-tree components
		       int i=0;
		       auto &num = std::get<Token::Ptr>(pt.subs[i++]);

		       // validate types
		       assert(num->type == Token::NUM);

		       return num->num();
		     };
    return Ptr(new ParseTree(F,evaluator,num));
  }
  
}
