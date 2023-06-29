#include <iostream>
#include "Lex/Lexer.cpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
using namespace toy;

string get_code(string filename = "C:\\Users\\IT_la\\Documents\\code\\toy\\test.txt"){
    ifstream fs(filename);
    string ret;
    ostringstream tmp;

    if(!fs.is_open()){
        cout << "file open error" << endl;
        exit(-1);
    }

    tmp << fs.rdbuf();
    ret = tmp.str();
    return ret;
}

int main() {
    Lex::lexer obj(get_code());

    while(!obj.empty()){
        cout << obj.getToken().to_string() << endl;
    }

    return 0;
}
