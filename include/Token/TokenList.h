#ifndef TOY_TOKENLIST_H
#define TOY_TOKENLIST_H

#include <cstdint>
#include <array>
#include <tuple>
#include "Token/Token.h"
#include "Token/TokenBlock.h"

using namespace std;

namespace toy::Token{
    class TokenList: private TokenBlock{
    private:
        int read_index = -1;
        int write_index = -1;
    public:
        tuple<array<size_t, 2>, toy::Token::Token> operator ++();

        void push(array<size_t, 2> position_value, toy::Token::Token value);
        tuple<array<size_t, 2>, toy::Token::Token> pop();

        toy::Token::Token& getIndexTokenRef(size_t index);

        bool isEnd() const;
    };
}

#endif //TOY_TOKENLIST_H
