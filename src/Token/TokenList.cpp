#include "Token/TokenList.h"

using namespace toy;

Token::TokenBlock::TokenBlock() {
    this->list = new toy::Token::Token[32];

    for(auto & i : this->position){
        i[0] = 0;
        i[1] = 0;
    }
}

Token::TokenBlock::~TokenBlock() {
    delete[] this->list;
}


void Token::TokenBlock::setIndexValue(size_t index, const toy::Token::Token& value) {
    if(index >= 32) return;
    this->list[index] = value;
}

toy::Token::Token Token::TokenBlock::getIndexValue(size_t index) {
    if(index >= 32)
        return toy::Token::Token(toy::Token::TokenKind::None);
    return this->list[index];
}

void Token::TokenBlock::setIndexPosition(size_t index, array<size_t, 2> position_value) {
    if(index >= 32) return ;
    this->position[index] = position_value;
}

array<size_t, 2> Token::TokenBlock::getIndexPosition(size_t index) {
    if(index >= 32)
        return array<size_t, 2>{0, 0};
    return this->position[index];
}
