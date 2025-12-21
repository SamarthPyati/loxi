#ifndef SV_STR_H_
#define SV_STR_H_

#include <ctype.h>
#include <string.h>

#ifndef SV_STR_DEF
#define SV_STR_DEF
#endif // SV_STR_DEF

typedef struct {
    const char *data;
    size_t count;
} StringView;

#define SV_Fmt "%.*s"
#define SV_Arg(sv) (int) (sv).count, (sv).data

SV_STR_DEF StringView sv_from_parts(const char *str, size_t count);
SV_STR_DEF StringView sv_from_cstr(const char *str);
SV_STR_DEF StringView sv_trim_left (StringView str);
SV_STR_DEF StringView sv_trim_right(StringView str);
SV_STR_DEF StringView sv_trim(StringView str);

#endif //  SV_STR_H_

#ifdef SV_STR_IMPLEMENTATION

SV_STR_DEF StringView sv_from_parts(const char *str, size_t count) {
    StringView sv;
    sv.data = str;
    sv.count = count;
    return sv;
}

SV_STR_DEF StringView sv_from_cstr(const char *str) {
    return sv_from_parts(str, strlen(str));
}

SV_STR_DEF StringView sv_trim_left(StringView str) {
    size_t i = 0;
    while (i < str.count && isspace((unsigned char)str.data[i])) {
        i++;
    }
    return sv_from_parts(str.data + i, str.count - i);
}

SV_STR_DEF StringView sv_trim_right(StringView str) {
    size_t i = str.count;
    while (i > 0 && isspace((unsigned char)str.data[i - 1])) {
        i--;
    }
    return sv_from_parts(str.data, i);
}

SV_STR_DEF StringView sv_trim(StringView str) {
    return sv_trim_right(sv_trim_left(str));
}

#endif // SV_STR_IMPLEMENTATION