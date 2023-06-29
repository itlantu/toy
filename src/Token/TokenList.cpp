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

