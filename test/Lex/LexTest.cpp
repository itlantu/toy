#include <iostream>
#include "Lex/Lexer.H"
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
            cout << obj.getToken().to_string() << endl;
        }
    }

    cout << "END" <<  endl;

    return 0;
}
