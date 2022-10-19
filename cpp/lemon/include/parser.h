#pragma once

#include <vector>
#include "token.h"
#include "lexer.h"

namespace calc {
  struct Parser {
    Lexer::Ptr lexer;

    Lexer(const std::string &_file);
    ~Lexer();

    typedef std::shared_ptr < Lexer > Ptr;
  };
}
