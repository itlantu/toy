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
        bool empty() const;
    };
}

#endif //TOY_LEXER_H
