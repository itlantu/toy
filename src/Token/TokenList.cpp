#include "Token/TokenList.h"

using namespace toy;

Token::TokenBlock::TokenBlock() {
    this->list = new toy::Token::Token[32];
    for(int i = 0; i < 32; i++){
        this->list[i].kind = toy::Token::TokenKind::None;
        this->list[i].value.Integer = 0;
    }
}

Token::TokenBlock::~TokenBlock() {
    delete this->list;
}

toy::Token::Token Token::TokenBlock::pop(){
    return this->list[this->read_index++];
}

void Token::TokenBlock::push(toy::Token::Token tok) {
    if(this->write_index >= 32) return ;
    this->list[this->write_index++] = tok;
}

bool Token::TokenBlock::empty() const {
    return this->read_index >= this->write_index;
}

