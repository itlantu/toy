#ifndef TOY_VIEWTOKEN_H
#define TOY_VIEWTOKEN_H

#include <string>
#include "Token/Token.h"
#include "Token/TokenList.h"

using namespace std;

namespace toy::Debug::View{

    string viewToken(toy::Token::Token token, string_view source_filename="unknown");
    string viewToken(tuple<array<size_t, 2>, toy::Token::Token> value, string_view source_filename="unknown");
}

#endif //TOY_VIEWTOKEN_H
