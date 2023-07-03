#ifndef TOY_TOKEN_H
#define TOY_TOKEN_H

#include <string>

namespace toy::Token {
    enum class TokenKind : short {
        None = 0,
        String,
        Integer,
        Rect
    };

    typedef union TokenValue{
        long long Integer;
        double Rect;
        char* String;

        explicit operator long long() const;
        explicit operator double() const;
        explicit operator char* () const;
    };

    class Token{
    private:
        TokenKind kind_;
        TokenValue value_;
        // digit成员变量用于记录如整数有多少位，浮点数小数点后有多少位
        short digit_;
    public:
        explicit Token(TokenKind kind = toy::Token::TokenKind::None);

        TokenKind getKind() const;
        TokenValue getValue() const;

        bool setValue(long long integer_value);
        bool setValue(double rect_value);
        bool setValue(char* string_value);

        /**
         * 根据kind_返回value_面量值的字符串表示
         * */
        std::string to_string() const;
    };
}

#endif //TOY_TOKEN_H
