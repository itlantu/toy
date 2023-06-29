#include "Token/Token.h"
#include <string>
#include <cstdint>

using namespace toy;
using namespace std;

static const char *TokenKindTable[] = {
        "None", "String",
        "Integer", "Rect",
};

Token::Token::operator char*() const{
    return this->value.String;
}

Token::Token::operator int64_t () const {
    return this->value.Integer;
}

Token::Token::operator double() const {
    return this->value.Rect;
}

string Token::Token::to_string() const {
    string ret = "(";

    ret.append(TokenKindTable[(int)this->kind]);
    ret.append(", ");

    switch (this->kind) {
        case toy::Token::TokenKind::None:
            ret.append("None");
            break;
        case toy::Token::TokenKind::String:
            ret.push_back('"');
            ret.append(this->value.String);
            ret.push_back('"');
            break;
        case toy::Token::TokenKind::Integer:
            ret.append(std::to_string(this->value.Integer));
            break;
        case toy::Token::TokenKind::Rect:
            ret.append(std::to_string(this->value.Rect));
            break;
    }

    ret.push_back(')');
    return ret;
}


