#include "Basic/StringCopy.h"

using namespace toy;

void Basic::StringCopy(const char *src, char *dest, size_t size) {
    const auto *src_llp = reinterpret_cast<const long long *>(src);
    auto *dest_llp = reinterpret_cast<long long *>(dest);

    size_t i = 0;
    for (size_t len = size / sizeof(long long); i < len; i++) {
        // 1次拷贝8个字节
        dest_llp[i] = src_llp[i];
    }
    for(size_t j = i * sizeof(long long); j < size; j++){
        // 1次拷贝1个字节
        dest[j] = src[j];
    }
}
