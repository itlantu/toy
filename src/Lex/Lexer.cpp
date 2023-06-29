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
        if(ch == '"'){
            this->list.push(makeString(code));
        }
        else if(isdigit(ch)){
            code.previous();
            this->list.push(makeNumber(code));
        }
        else{
            code.previous();
            cout << "unknown" << endl;
        }
    }
}

Token::Token Lex::lexer::getToken() {
    return this->list.pop();
}

bool Lex::lexer::empty() const {
    return this->list.empty();
}

