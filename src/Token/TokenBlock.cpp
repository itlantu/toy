#include "Token/TokenBlock.h"

using namespace toy;
using namespace std;

Token::TokenBlock::TokenBlock() {
    this->list = new toy::Token::Token[this->list_length];
    this->position = new array<size_t, 2>[this->list_length];

    auto& position_ref = this->position;

    for(size_t i = 0; i < this->list_length; i++){
        position_ref[i][0] = 0;
        position_ref[i][1] = 0;
    }
}

Token::TokenBlock::~TokenBlock() {
    delete[] this->list;
}


void Token::TokenBlock::setIndexValue(size_t index, const toy::Token::Token& value) {
    if(index >= this->list_length) return;
    this->list[index] = value;
}

toy::Token::Token Token::TokenBlock::getIndexValue(size_t index) const{
    if(index >= this->list_length)
        return toy::Token::Token(toy::Token::TokenKind::None);
    return this->list[index];
}

void Token::TokenBlock::setIndexPosition(size_t index, array<size_t, 2> position_value) {
    if(index >= this->list_length) return ;
    this->position[index] = position_value;
}

array<size_t, 2> Token::TokenBlock::getIndexPosition(size_t index) const{
    if(index >= this->list_length)
        return array<size_t, 2>{0, 0};
    return this->position[index];
}