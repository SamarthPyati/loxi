#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#define STMT(S) do { S } while (0)

#define Stringify(x) #x

#define UNUSED(value) (void)(value)
#define NOB_TODO(message) STMT (                                            \
    fprintf(stderr, "%s:%d: TODO: %s\n", __FILE__, __LINE__, message);      \
    abort();                                                                \
)                                                                           
#define UNIMPLEMENTED(message) STMT (                                           \
    fprintf(stderr, "%s:%d: UNIMPLEMENTED: %s\n", __FILE__, __LINE__, message); \
    abort();                                                                    \
)
#define UNREACHABLE(message) STMT (                                                 \
    fprintf(stderr, "%s:%d: UNREACHABLE : %s\n", __FILE__, __LINE__, message);      \
    abort();                                                                        \
)

#define ArrayLen(xs) sizeof((xs)) / sizeof(*(xs))

#define KB(b) (uint64_t)(b) << 10

/* Error handling */
#define LOG_ERROR(fmt, ...) STMT (                                                \
    fprintf(stderr, "%s:%d: ERROR: "fmt"", __FILE__, __LINE__, ##__VA_ARGS__);    \
)

#endif // UTILS_H_