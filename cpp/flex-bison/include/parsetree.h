#pragma once

#include <variant>
#include <vector>
#include <memory>
#include <functional>
#include <string>
#include <map>
#include "token.h"

namespace calc {
  struct ParseTree {
    enum Type { E, T, F };
    Type type;
    static const char *strtype(Type type);
    typedef std::shared_ptr < ParseTree > Ptr;
    typedef std::variant < Token::Ptr , Ptr > Sub;
    std::vector < Sub > subs;

    typedef std::map < std::string , double > Vars;
    typedef std::function < double (const ParseTree &,Vars &) > Evaluator;
    Evaluator evaluator;
    double eval(Vars &vars) const;

    ParseTree(Type _type, Evaluator _evaluator);
    ParseTree(Type _type, Evaluator _evaluator,Sub sub0);
    ParseTree(Type _type, Evaluator _evaluator,Sub sub0, Sub sub1);
    ParseTree(Type _type, Evaluator _evaluator,Sub sub0, Sub sub1, Sub sub2);

    static Ptr e_add(Sub e,Sub add,Sub t);
    static Ptr e_t(Sub t);
    static Ptr t_f(Sub f);
    static Ptr f_num(Sub num);
  };
}
