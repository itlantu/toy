#include "Token/TokenList.h"

using namespace toy;

Token::TokenBlock::TokenBlock() {
    this->list = &(new toy::Token::Token(toy::Token::TokenKind::None))[32];

    for(int i = 0; i < 32; i++){
        this->position[i][0] = 0;
        this->position[i][1] = 0;
    }
}

Token::TokenBlock::~TokenBlock() {
    delete[] this->list;
}

toy::Token::Token Token::TokenBlock::pop(){
    if(this->read_index > this->write_index)
        return toy::Token::Token(toy::Token::TokenKind::None);
    return this->list[++this->read_index];
}

void Token::TokenBlock::push(toy::Token::Token tok) {
    if(this->write_index >= 32) return ;
    this->list[++this->write_index] = tok;
}

bool Token::TokenBlock::empty() const {
    return this->read_index >= this->write_index;
}

array<size_t, 2> Token::TokenBlock::getPosition() {
    if(this->read_index > this->write_index || this->read_index == -1)
        return array<size_t, 2>{0, 0};
    return this->position[this->read_index];
}

void Token::TokenBlock::setPosition(const size_t *position_value) {
    this->setPosition(position_value[0], position_value[1]);
}

void Token::TokenBlock::setPosition(array<size_t, 2> position_value) {
    this->setPosition(position_value[0], position_value[1]);
}

void Token::TokenBlock::setPosition(size_t line, size_t row) {
    if(this->write_index >= 32 || this->write_index == -1) return ;

    auto &p = this->position[this->write_index];
    p[0] = line;
    p[1] = row;
}

