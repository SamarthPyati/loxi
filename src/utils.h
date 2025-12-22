#define Stmt(s) do { S } while (0)

#define UNUSED(x) (void)(x)
#define UNIMPLEMENTED(msg) Stmt (                                                           \
    fprintf(stderr, "%s:%d: [%s UNIMPLEMENTED] : %s\n", __FILE__, __LINE__, __func__, msg); \
    abort();                                                                                \
)
#define UNREACHABLE(msg) Stmt (                                                             \
    fprintf(stderr, "%s:%d: [UNREACHABLE] : %s\n", __FILE__, __LINE__, msg);                \
    abort();                                                                                \
)

#define ArrayLen(xs) sizeof((xs)) / sizeof(*(xs))

#define KB(b) (b) * 1024