#include "Lex/CodeReader.h"
#include <string_view>

using namespace toy;
using namespace std;

Lex::CodeReader::CodeReader(string_view code) {
//    this->position[0] = 0;
//    this->position[1] = 0;
    this->length = code.size();

    // 拷贝字符串
    if(!code.empty()) this->_code = code.substr(0, code.size());
    this->code = string_view(this->_code);
}

Lex::CodeReader::CodeReader(const string& code) {
    this->length = code.size();

    // 拷贝字符串
    if(!code.empty()) this->_code = code.substr(0, code.size());
    this->code = string_view(_code);
}

/*
 * 从成员变量code中获取下一个字符
 * 并且遇到换行时自增成员变量position[0]
 * */
char Lex::CodeReader::next() {
    char ret;

    if(this->index + 1 > this->length) return '\0';

    ret = this->code[(++this->index) - 1];

    ++this->position[1];
    if(ret == '\n'){
        ++this->position[0];
        this->position[1] = 0;
    }

    return ret;
}

size_t Lex::CodeReader::getIndex() const{
    return this->index;
}

// 获得下标范围为[start, end] 的字符串
string_view Lex::CodeReader::getRange(size_t start, size_t end) const{
    string_view ret;

    if(start >= end){
        // Error
    }

    ret = this->code.substr(start, end - start);

    return ret;
}

bool Lex::CodeReader::isEnd() const{
    return this->index + 1 > this->length;
}

Lex::CodeReader::~CodeReader() {
    // 长度为0则不回收
    if(this->length == 0) return ;
}

size_t Lex::CodeReader::size() const {
    return this->length;
}

char Lex::CodeReader::getChar() const{
    return this->index + 1 > this->length ? '\0': this->code[this->index - 1];
}

bool Lex::CodeReader::previous() {
    if(this->index <= 0) return false;
    --this->index;
    return true;
}

