#pragma once

#include <memory>
#include <string>
#include <stdint.h>

namespace calc {
  struct Token {
    enum Type {
	       UNKNOWN='?',
	       ADD='+',
	       SUB='-',
	       MUL='*',
	       DIV='/',
	       LP='(',
	       RP=')',
	       NUM='#',
	       EOL='\n',
	       END=-1
    };

    std::string file;
    int32_t line,column;
    std::string text;
    Type type;
    static const char *strtype(enum Type type);

    virtual ~Token();
    Token(const std::string &_text,
	  Type _type = UNKNOWN,
	  const std::string &_file="",
	  int32_t _line=0,
	  int32_t _column=0);
    typedef std::shared_ptr < Token > Ptr;

    virtual double num() const;

    static Ptr unknown(const std::string &_text, const std::string &_file="", int32_t _line = 0, int _column = 0);
    static Ptr add(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr sub(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr mul(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr div(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr lp(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr rp(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr num(const std::string &_text, const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr eol(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);
    static Ptr end(const std::string &_file="", int32_t _line = 0, int32_t _column = 0);

    virtual void print(std::ostream &out) const;
    // create token table
  };

  struct NumberToken : Token {
    NumberToken(const std::string &_text,
		const std::string &_file="",
		int32_t _line=0,
		int32_t _column=0);
    virtual double num() const;
    virtual void print(std::ostream &out) const;    
    virtual ~NumberToken();
  };

  std::ostream& operator<<(std::ostream &out, const Token::Ptr &token);
}
