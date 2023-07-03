#include "Token/Token.h"
#include <string>

using namespace toy;
using namespace std;

/* 对TokenValue的强制类型转换重载 */
toy::Token::TokenValue::operator long long() const {
    return this->Integer;
}

toy::Token::TokenValue::operator double() const {
    return this->Rect;
}

toy::Token::TokenValue::operator char* () const {
    return this->String;
}

toy::Token::Token::Token(toy::Token::TokenKind kind) : kind_(kind){
    this->value_.Integer = 0;
}

toy::Token::TokenKind toy::Token::Token::getKind() const {
    return this->kind_;
}

toy::Token::TokenValue toy::Token::Token::getValue() const {
    return this->value_;
}

bool Token::Token::setKind(toy::Token::TokenKind kind) {
    if(this->kind_ != toy::Token::TokenKind::None) return false;
    this->kind_ = kind;
    return true;
}

/* 对Token::setValue的重载函数 */
bool toy::Token::Token::setValue(long long int integer_value) {
    if(this->kind_ != toy::Token::TokenKind::Integer)
        return false;
    this->value_.Integer = integer_value;
    return true;
}

bool Token::Token::setValue(double rect_value) {
    if(this->kind_ != toy::Token::TokenKind::Rect)
        return false;
    this->value_.Rect = rect_value;
    return true;
}

bool Token::Token::setValue(char* string_value) {
    if(this->kind_ != toy::Token::TokenKind::String)
        return false;
    this->value_.String = string_value;
    return true;
}

string Token::Token::to_string() const {
    switch (this->kind_) {
        case toy::Token::TokenKind::None:
            return "None";
        case toy::Token::TokenKind::String:
            return '"' + string(static_cast<char*>(this->value_)) + '"';
        case toy::Token::TokenKind::Integer:
            return std::to_string(static_cast<long long>(this->value_));
        case toy::Token::TokenKind::Rect:
            return std::to_string(static_cast<double>(this->value_));
    }
    return "Unknown";
}
