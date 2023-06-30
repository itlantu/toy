#include "Debug/View/ViewToken.h"
#include <string>
#include <string_view>

using namespace std;

string toy::Debug::View::viewToken(tuple<array<size_t, 2>, toy::Token::Token> value, string_view source_filename) {
    string ret;

    auto &position =  get<0>(value);
    auto token = get<1>(value);
    auto token_value = token.to_string();
    auto token_kind = token.getKind();

    ret.append("Token <");

    ret.append(source_filename);
    ret.push_back(':');
    ret.append(std::to_string(position[0]));
    ret.push_back('.');
    ret.append(std::to_string(position[1]));

    ret.append("\t(");
    ret.append(toy::Token::TokenKindTable[static_cast<short>(token_kind)]);
    ret.append(" , ");

    if(token_kind == toy::Token::TokenKind::String){
        ret.push_back('"');
        ret.append(token_value);
        ret.push_back('"');
    }else
        ret.append(token_value);

    ret.append(")>");

    return ret;
}
