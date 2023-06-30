#ifndef TOY_LEXER_H
#define TOY_LEXER_H

#include <string>
#include "Token/TokenList.h"

using namespace std;

namespace toy::Lex{
    class lexer{
    private:
        Token::TokenList list;
        void constructor();

    public:
        explicit lexer(const string& source);
        Token::Token getToken();
        tuple<array<size_t, 2>, toy::Token::Token> getTokenAndPosition();
        bool empty() const;
        bool isEnd() const;
    };
}

#endif //TOY_LEXER_H
