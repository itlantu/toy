#include "Lex/Lexer.h"
#include <string>
#include <string_view>
#include <cctype>
#include <iostream>
#include "Lex/CodeReader.h"
#include "lex/LexerToken.h"

using namespace toy;
using namespace std;

void Lex::lexer::constructor() {

}

Lex::lexer::lexer(const string& source) {
    this->constructor();

    toy::Lex::CodeReader code(source);

    while(!code.isEnd()){
        char ch = code.next();

        if(isspace(ch))
            continue;

        auto position = code.getPosition();
        if(ch == '"'){
            this->list.push(position, makeString(code));
        }
        else if(isdigit(ch)){
            code.previous();
            this->list.push(position,makeNumber(code));
        }
        else{
            cout << "unknown" << endl;
            exit(-2);
        }
    }
}

Token::Token Lex::lexer::getToken() {
    return get<1>(this->list.pop());
}

bool Lex::lexer::empty() const {
    return false;
}

bool Lex::lexer::isEnd() const{
    return this->list.isEnd();
}