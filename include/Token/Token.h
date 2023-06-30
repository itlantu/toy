#ifndef TOY_TOKEN_H
#define TOY_TOKEN_H

#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

namespace toy::Token{
    enum class TokenKind: short {
        None = 0,
        String ,
        Integer,
        Rect,
    };

    typedef union TokenValue{
        char* String;
        int64_t Integer;
        double Rect;

        explicit operator char*() const;
        explicit operator int64_t() const;
        explicit operator double() const;
    }TokenValue;

//    typedef struct Token{
//        TokenKind kind;
//        TokenValue value;
//
//        explicit operator char*() const;
//        explicit operator int64_t() const;
//        explicit operator double() const;
//        string to_string() const;
//    }Token;

    class Token{
    private:
        TokenKind kind;
        short digit = 0;
        TokenValue value;
    public:
        explicit Token(double rect_value);
        explicit Token(int64_t integer_value);
        explicit Token(const string& string_value);
        explicit Token(TokenKind kind = toy::Token::TokenKind::None);

        toy::Token::TokenKind getKind() const;
        void setKind(toy::Token::TokenKind kind_value);

        string to_string() const;

        void setDigit(short digit_value);
        short getDigit() const;

        template<typename ty>
        ty at() const;

        void setValue(int64_t integer_value);
        void setValue(double rect_value);
        void setValue(char* string_value);

        void* operator new[](size_t size);
        void operator delete[](void* ptr);
    };
}

#endif //TOY_TOKEN_H
