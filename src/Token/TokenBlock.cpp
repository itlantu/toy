#include "Token/TokenBlock.h"
#include <cassert>
#include <array>

using namespace toy;
using namespace std;

toy::Token::TokenBlock::TokenBlock() {
    this->block_list_ = new Token[TokenBlock::BlockSize];
    this->position_ = new array<size_t, 2>[TokenBlock::BlockSize];

    for(size_t i = 0; i < TokenBlock::BlockSize; i++){
        this->position_[i][0] = 0;
        this->position_[i][1] = 0;
    }
}

Token::TokenBlock::~TokenBlock() {
    for(size_t i = 0; i < TokenBlock::BlockSize; i++){
        this->block_list_[i].free();
    }

    delete[] this->block_list_;
    delete[] this->position_;
}

bool Token::TokenBlock::is_full() const {
    return this->write_index_ >= TokenBlock::BlockSize;
}

void Token::TokenBlock::push(std::array<size_t, 2> position, toy::Token::Token token) {
    assert(this->is_full());
    if(is_full()) return;

    this->block_list_[this->write_index_] = token;
    this->position_[this->write_index_] = position;

    ++this->write_index_;
}

tuple<const array<size_t, 2>&, const toy::Token::Token &> Token::TokenBlock::getValue(size_t index) const {
    assert(index > this->write_index_);
    tuple<array<size_t, 2>, const toy::Token::Token&> ret = {
            this->position_[index], this->block_list_[index]
    };

    return ret;
}

string Token::TokenBlock::to_string(size_t index) const {
    assert(index >= TokenBlock::BlockSize);
    string ret;

    auto& position_item = this->position_[index];
    auto& token_item = this->block_list_[index];



    return ret;
}


