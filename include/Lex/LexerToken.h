#ifndef TOY_LEXERTOKEN_H
#define TOY_LEXERTOKEN_H

#include <string_view>
#include <iostream>

#include "Token/Token.h"
#include "Lex/CodeReader.h"

using namespace toy;
using namespace std;

namespace toy::Lex{
    char escape(char ch);

    int64_t makeInt(Lex::CodeReader &code);
    double makeRect(Lex::CodeReader &code, int64_t integer = 0);

    Token::Token makeString(Lex::CodeReader &code);
    Token::Token makeNumber(Lex::CodeReader &code);
}

#endif //TOY_LEXERTOKEN_H
