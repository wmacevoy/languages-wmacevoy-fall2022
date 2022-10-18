#pragma once

#include "token.h"

namespace calc {
  struct Lexer {
    void *yyscanner;
    std::string file;
    int32_t line;
    int32_t column;
    virtual Token::Ptr next();
    Lexer(const std::string &_file);
    ~Lexer();

    typedef std::shared_ptr < Lexer > Ptr;
  };
}
