#ifndef TOY_TOKENBLOCK_H
#define TOY_TOKENBLOCK_H

#include <array>
#include "Token/Token.h"

using namespace std;

namespace toy::Token{
    class TokenBlock{
    private:
        toy::Token::Token *list;
        array<size_t, 2> *position;
    protected:
        const size_t list_length = 32;
    public:
        TokenBlock();
        ~TokenBlock();

        void setIndexValue(size_t index, const toy::Token::Token& value);
        toy::Token::Token getIndexValue(size_t index) const;

        void setIndexPosition(size_t index, array<size_t, 2> position_value);
        array<size_t, 2> getIndexPosition(size_t index) const;
    };
}

#endif //TOY_TOKENBLOCK_H
