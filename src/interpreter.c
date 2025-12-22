#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SV_STR_IMPLEMENTATION
#include <sv_str.h>

#include <utils.h>

#define STATIC_BUF_CAP  KB(10)
#define MAX_TOKENS      KB(10)

static size_t __load_file_to_buf(const char *fname, char *buf) {
    FILE *f = fopen(fname, "rb");
    size_t length = 0;
    if (f) {
        // Set file pointer to end (for ftell to obtain the length of file)
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        
        // TODO: Introduce dynamic buffer
        if (length >= STATIC_BUF_CAP) {
            fprintf(stderr, "ERROR: File too large.\n");
            exit(EXIT_FAILURE);
        }
        // Set file pointer back to start to read
        fseek(f, 0, SEEK_SET);

        // Load the buffer
        fread(buf, sizeof(*buf), length, f);
        buf[length] = '\0';

        fclose(f);
    } else {
        fprintf(stderr, "ERROR: Could not load file to buffer.\n");
        exit(EXIT_FAILURE);
    }

    return length;
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [script.lox]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *file = argv[1];
    static char buf[STATIC_BUF_CAP] = {0};
    size_t length = 0;

    StringView tokens[MAX_TOKENS];
    
    const char *sep = " \t\n";
    
    if (file) {
        /* interprete the whole file */ 
        char *token; 
        size_t idx = 0;

        length = __load_file_to_buf(file, buf); 
        char *cursor = buf;

        while ((token = strsep(&cursor, sep)) != NULL) {
            StringView svtoken = sv_from_cstr(token);
            svtoken = sv_trim(svtoken);
            tokens[idx++] = svtoken;
            printf("%zu: " SV_Fmt "\n", idx, SV_Arg(svtoken));
        }
        
        printf("File %s, Length: %zu\n", file, length);
    } else {
        char line[KB(1)];
        // REPL
        for (;;) {
            printf("> ");
            fflush(stdout);

            if (fgets(line, sizeof(line), stdin) == NULL) {
                printf("\n");
                break;
            }

            // strip trailing newline
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';

            if (strcmp(line, "exit") == 0) break;

            // tokenize
            char *cursor = line;
            char *token;
            size_t idx = 0;
            while ((token = strsep(&cursor, sep)) != NULL) {
                StringView svtoken = sv_from_cstr(token);
                svtoken = sv_trim(svtoken);
                if (svtoken.count == 0) continue;
                tokens[idx++] = svtoken;
                printf("%zu: " SV_Fmt "\n", idx, SV_Arg(svtoken));
                if (idx >= MAX_TOKENS) break;
            }
        }
    }
    return 0;
}