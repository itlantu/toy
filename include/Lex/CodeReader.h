#ifndef TOY_CODEREADER_H
#define TOY_CODEREADER_H

#include <string_view>
#include <string>
#include <array>

using namespace std;

namespace toy::Lex{
    class CodeReader{
    private:
        string _code;
        string_view code;
        // position[0]表示行, position[1]表示列
        array<size_t, 2> position{0, 0};
        size_t index = 0;
        size_t length;
    public:
        explicit CodeReader(string_view code = "");
        explicit CodeReader(const string& code);
        ~CodeReader();

        char next();
        char getChar() const;

        size_t getIndex() const;
        size_t size() const;

        string_view getRange(size_t start, size_t end) const;
        
        bool isEnd() const;
        bool previous();

        array<size_t, 2> getPosition() const;
    };
}

#endif //TOY_CODEREADER_H
