#ifndef TOY_TOKENBLOCK_H
#define TOY_TOKENBLOCK_H

#include "Token/Token.h"
#include <array>
#include <tuple>

namespace toy::Token{
    class TokenBlock{
    private:
        toy::Token::Token* block_list_;
        // position_成员变量用于记录Token在源码中的行列位置
        std::array<size_t, 2>* position_;

        size_t write_index_ = 0;

        bool is_full() const;
    public:
        static const int BlockSize = 32;

        TokenBlock();
        ~TokenBlock();

        void push(std::array<size_t, 2> position, toy::Token::Token token);

        std::tuple<const std::array<size_t, 2>&, const Token &> getValue(size_t index) const;
    };
}

#endif //TOY_TOKENBLOCK_H
