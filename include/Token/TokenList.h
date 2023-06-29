#ifndef TOY_TOKENLIST_H
#define TOY_TOKENLIST_H

#include "cstdint"
#include "Token/Token.h"

namespace toy::Token{
    class TokenBlock{
    private:
        toy::Token::Token *list;
        short read_index = -1;
        short write_index = -1;
        size_t position[32][2];
    public:
        TokenBlock();
        ~TokenBlock();
        toy::Token::Token pop();

        void push(toy::Token::Token tok);
        bool empty() const;
    };

    class TokenList: public TokenBlock{

    };
}

#endif //TOY_TOKENLIST_H
