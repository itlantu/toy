#ifndef TOY_TOKENLIST_H
#define TOY_TOKENLIST_H

#include <cstdint>
#include <array>
#include <tuple>
#include "Token/Token.h"

using namespace std;

namespace toy::Token{
    class TokenBlock{
    private:
        toy::Token::Token *list;
        array<size_t, 2> position[32]{};
    public:
        TokenBlock();
        ~TokenBlock();

        void setIndexValue(size_t index, const toy::Token::Token& value);
        toy::Token::Token getIndexValue(size_t index) const;

        void setIndexPosition(size_t index, array<size_t, 2> position_value);
        array<size_t, 2> getIndexPosition(size_t index) const;
    };

    class TokenList: private TokenBlock{
    private:
        int read_index = -1;
        int write_index = -1;
    public:
        tuple<array<size_t, 2>, toy::Token::Token> operator ++();

        void push(array<size_t, 2> position_value, toy::Token::Token value);
        tuple<array<size_t, 2>, toy::Token::Token> pop();

        bool isEnd() const;
    };
}

#endif //TOY_TOKENLIST_H
