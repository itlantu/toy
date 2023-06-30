#include "Token/Token.h"
#include <string>
#include <cstdint>
#include <cstdlib>

using namespace toy;
using namespace std;

extern const char* toy::Token::TokenKindTable[] = {
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
    switch (this->kind) {
        case toy::Token::TokenKind::None:
            return "None";
        case toy::Token::TokenKind::Integer:
            return std::to_string(this->value.Integer);
        case toy::Token::TokenKind::Rect:
            return std::to_string(this->value.Rect);
        case toy::Token::TokenKind::String:
            return this->value.String;
    }
    return "Unknown";
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

Token::Token::Token(toy::Token::TokenKind kind) {
    this->kind = kind;
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

void Token::Token::setValue(int64_t integer_value) {
    this->value.Integer = integer_value;
}

void Token::Token::setValue(double rect_value) {
    this->value.Rect = rect_value;
}

void Token::Token::setValue(char *string_value) {
    this->value.String = string_value;
}

void Token::Token::setKind(toy::Token::TokenKind kind_value) {
    this->kind = kind_value;
}

void *Token::Token::operator new[](size_t size) {
    auto _obj = ::operator new(size);
    auto* obj = reinterpret_cast<toy::Token::Token*>(_obj);

    for(size_t i = 0, len = size / sizeof(toy::Token::Token); i < len; i++){
        obj[i].kind = toy::Token::TokenKind::None;
        obj[i].value.Integer = 0;
    }
    return obj;
}

void Token::Token::operator delete[](void *ptr) {
    std::free(ptr);
}

