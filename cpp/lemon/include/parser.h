#pragma once

#include <memory>
#include "token.h"
#include "lexer.h"
#include "parsetree.h"

namespace calc {
  struct Parser {
    Lexer::Ptr lexer;
    void *yyps;

    void push(Token::Ptr token);
    ParseTree::Ptr parse();
    
    Parser(Lexer::Ptr _lexer);

    virtual ~Parser();

    bool ok;
    ParseTree::Ptr result;

    typedef std::shared_ptr < Parser > Ptr;
  };
}
