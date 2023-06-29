#include "Token/Token.h"
#include <string>
#include <cstdint>

using namespace toy;
using namespace std;

static const char *TokenKindTable[] = {
        "None", "String",
        "Integer", "Rect",
};

Token::TokenValue::operator char*() const{
    return this->String;
}

Token::TokenValue::operator int64_t () const {
    return this->Integer;
}

Token::TokenValue ::operator double() const {
    return this->Rect;
}

string Token::Token::to_string() const {
    string ret = "(";

    ret.append(TokenKindTable[(int)this->kind]);
    ret.append(", ");

    switch (this->getKind()) {
        case toy::Token::TokenKind::None:
            ret.append("None");
            break;
        case toy::Token::TokenKind::String:
            ret.push_back('"');
            ret.append(this->at<char*>());
            ret.push_back('"');
            break;
        case toy::Token::TokenKind::Integer:
            ret.append(std::to_string(this->at<int64_t>()));
            break;
        case toy::Token::TokenKind::Rect:
            ret.append(std::to_string(this->at<double>()));
            break;
    }

    ret.push_back(')');
    return ret;
}

Token::Token::Token(double rect_value){
    this->kind = toy::Token::TokenKind::Rect;
    this->value.Rect = rect_value;
}

Token::Token::Token(int64_t integer_value) {
    this->kind = toy::Token::TokenKind::Integer;
    this->value.Integer = integer_value;
}

Token::Token::Token(const string& string_value) {
    this->kind = toy::Token::TokenKind::Integer;
    this->value.String = const_cast<char*>(string_value.c_str());
}

Token::Token::Token() {
    this->kind = toy::Token::TokenKind::None;
    this->value.Integer = 0;
}


toy::Token::TokenKind Token::Token::getKind() const {
    return this->kind;
}

short Token::Token::getDigit() const {
    return this->digit;
}

void Token::Token::setDigit(short digit_value){
    this->digit = digit_value;
}

template<typename ty>
ty Token::Token::at() const {
    return static_cast<ty>(this->value);
}







