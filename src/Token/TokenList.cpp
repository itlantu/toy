#include "Token/TokenList.h"

using namespace std;
using namespace toy;


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


