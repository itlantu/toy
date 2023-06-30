#include <iostream>
#include "Lex/Lexer.h"
#include "Debug/View/ViewToken.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
using namespace toy;

string get_code(const string& filename = ""){
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
    {
        string test_file_path = "..\\..\\test\\Lex\\test.txt";
        Lex::lexer obj(get_code(test_file_path));

        while(!obj.isEnd()){
            auto value = obj.getTokenAndPosition();
            cout << Debug::View::viewToken(value) << endl;
        }
    }

    cout << "TEST END" <<  endl;

    return 0;
}
