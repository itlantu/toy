#ifndef TOY_TOKEN_H
#define TOY_TOKEN_H

#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

namespace toy::Token{
    enum class TokenKind{
        None = 0,
        String ,
        Integer,
        Rect,
    };

    typedef union TokenValue{
        char* String;
        int64_t Integer;
        double Rect;
    }TokenValue;

    typedef struct Token{
        TokenKind kind;
        TokenValue value;

        explicit operator char*() const;
        explicit operator int64_t() const;
        explicit operator double() const;
        string to_string() const;
    }Token;
}

#endif //TOY_TOKEN_H
