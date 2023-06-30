#ifndef TOY_TOKENLIST_H
#define TOY_TOKENLIST_H

#include <cstdint>
#include <array>
#include "Token/Token.h"

using namespace std;

namespace toy::Token{
    class TokenBlock{
    private:
        toy::Token::Token *list;
        short read_index = -1;
        short write_index = -1;
        array<size_t, 2> position[32]{};
    public:
        TokenBlock();
        ~TokenBlock();
        toy::Token::Token pop();

        void push(toy::Token::Token tok);
        bool empty() const;

        void setPosition(const size_t position_value[2]);
        void setPosition(size_t line, size_t row);
        void setPosition(array<size_t, 2> position_value);
        array<size_t, 2> getPosition();
    };

    class TokenList: public TokenBlock{

    };
}

#endif //TOY_TOKENLIST_H
