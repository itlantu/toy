#include "Lex/LexerToken.h"
#include <cctype>
#include <cfloat>
#include <cmath>
#include "Lex/CodeReader.h"
#include "Token/Token.h"

using namespace std;
using namespace toy;

/*
 * 将ch转义
 * */
char Lex::escape(char ch) {
    static const char escape_table[][2] = {
            {'n', '\n'},
            {'t', '\t'},
            {'v', '\v'},
            {'\\', '\\'},
            {'\'', '\''},
            {'"', '"'},
            {'0', '\0'},
            {'r', '\r'},
            {'a', '\a'},
            {'b', '\b'},
            {'f', '\f'},
    };

    for(auto &it : escape_table){
        if(ch == it[0]) return it[1];
    }

    return -1;
}

int64_t Lex::makeInt(Lex::CodeReader &code){
    static const int64_t max = INT64_MAX / 10;
    int64_t ret = 0;

    while(!code.isEnd()){
        char ch = code.next();

        if(isdigit(ch)){
            if(ret > max){
                // int64存不下了
            }
            ret = ret * 10 + (ch - '0');
        }else break;
    }

    return ret;
}

double Lex::makeRect(Lex::CodeReader &code, int64_t integer){
    double ret = floor(integer);
    double k = 0.1;
//    const auto max = DBL_MAX;

    while(!code.isEnd()){
        char ch = code.next();

        if(isdigit(ch)){
            ret += k * (ch - '0');
            k *= 0.1;
        }else break;
    }

    return ret;
}

Token::Token Lex::makeString(Lex::CodeReader &code){
    Token::Token ret(Token::TokenKind::String);
    char* StringValue;
    size_t i = 0;
    size_t escape_char_num = 0;
    size_t length;
    size_t start = code.getIndex();
    bool is_escape = false;

    // 检查字符串是否合法
    while(!code.isEnd()){
        char ch = code.next();
        if(is_escape){
            if(Lex::escape(ch) == -1){
                // 转义异常，Error
            }
            escape_char_num += 1;
            is_escape = false;
        }else if(ch == '\\')is_escape = true;
        else if(ch == '"' && !is_escape) break;
    }

    if(code.isEnd()){
        // 到了code末尾,都没有找到字符串结束符'"'
    }

    if(is_escape){
        // 已转义字符'\'结尾
    }

    // 计算字符串长度
    length = code.getIndex() - start -  escape_char_num;
    // 为字符串分配内存
    StringValue = new char[length + 1];

    // 拷贝字符串
    i = 0;
    for(char ch: code.getRange(start, code.getIndex())){
        if(is_escape){
            StringValue[i++] = Lex::escape(ch);
            is_escape = false;
        }else if(ch == '\\') is_escape = true;
        else StringValue[i++] = ch;
    }
    StringValue[length - 1] = '\0';

    ret.setValue(StringValue);
    return ret;
}

Token::Token Lex::makeNumber(Lex::CodeReader &code) {
    Token::Token ret(Token::TokenKind::Integer);
    int64_t integer;

    integer = Lex::makeInt(code);
    ret.setValue(integer);

    if(code.getChar() == '.'){
        ret.setKind(Token::TokenKind::Rect);
        ret.setValue(Lex::makeRect(code, integer));
    }

    return ret;
}

