#include "Token/TokenList.h"

using namespace std;
using namespace toy;

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

tuple<array<size_t, 2>, toy::Token::Token> Token::TokenList::operator++() {
    return tuple<array<size_t, 2>, toy::Token::Token>();
}

void Token::TokenList::push(array<size_t, 2> position_value, toy::Token::Token value) {
    if(this->write_index >= this->list_length) return ;
    auto& index = ++this->write_index;

    this->setIndexValue(this->write_index, value);
    this->setIndexPosition(this->write_index, position_value);
}

bool Token::TokenList::isEnd() const {
    return this->read_index >= this->write_index;
}

tuple<array<size_t, 2>, toy::Token::Token> Token::TokenList::pop() {
    auto ret = tuple<array<size_t, 2>, toy::Token::Token>();

    if(this->read_index >= this->list_length){
        get<0>(ret) = array<size_t, 2>{0, 0};
        get<1>(ret) = toy::Token::Token(toy::Token::TokenKind::None);
    }else{
        size_t index = this->read_index + 1;
        get<0>(ret) = this->getIndexPosition(index);
        get<1>(ret) = this->getIndexValue(index);
    }

    ++this->read_index;
    return ret;
}


