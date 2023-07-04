#ifndef TOY_STRINGCOPY_H
#define TOY_STRINGCOPY_H

#include <cstddef>

namespace toy::Basic{
    // 从src拷贝大小为size的字符串到dest
    void StringCopy(const char* src, char* dest, size_t size);
}

#endif //TOY_STRINGCOPY_H
