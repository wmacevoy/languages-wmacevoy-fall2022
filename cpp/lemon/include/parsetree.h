#pragma once

#include <variant>
#include <vector>
#include <memory>
#include "token.h"

namespace calc {
  struct ParseTree {
    enum Type { E, T, F };
    Type type;
    typedef std::shared_ptr < ParseTree > Ptr;
    typedef std::variant < Token::Ptr , Ptr > Sub;
    std::vector < Sub > subs;
    ParseTree(Type _type);
    ParseTree(Type _type, Sub sub0);
    ParseTree(Type _type, Sub sub0, Sub sub1);
    ParseTree(Type _type, Sub sub0, Sub sub1, Sub sub2);

    static Ptr e_add(Sub e,Sub add,Sub t);
    static Ptr e_t(Sub t);
    static Ptr t_f(Sub f);
    static Ptr f_num(Sub num);
  };
}
