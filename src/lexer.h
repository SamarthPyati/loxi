#ifndef LEXER_H_
#define LEXER_H_

#include <sv_str.h>
#include <utils.h>

/* Minimal lexer logic

while not EOF:
    skip whitespace
    if letter → read identifier
    if digit → read number
    if '"' → read string literal
    if symbol → read symbol token
*/

#define TOKEN_LIST \
    /* Single-character tokens */ \
    X(TOKEN_LEFT_PAREN, "LEFT_PAREN"), \
    X(TOKEN_RIGHT_PAREN, "RIGHT_PAREN"), \
    X(TOKEN_LEFT_BRACE, "LEFT_BRACE"), \
    X(TOKEN_RIGHT_BRACE, "RIGHT_BRACE"), \
    X(TOKEN_COMMA, "COMMA"), \
    X(TOKEN_DOT, "DOT"), \
    X(TOKEN_MINUS, "MINUS"), \
    X(TOKEN_PLUS, "PLUS"), \
    X(TOKEN_SEMICOLON, "SEMICOLON"), \
    X(TOKEN_SLASH, "SLASH"), \
    X(TOKEN_STAR, "STAR"), \
    /* One or two character tokens */ \
    X(TOKEN_BANG, "BANG"), \
    X(TOKEN_BANG_EQUAL, "BANG_EQUAL"), \
    X(TOKEN_EQUAL, "EQUAL"), \
    X(TOKEN_EQUAL_EQUAL, "EQUAL_EQUAL"), \
    X(TOKEN_GREATER, "GREATER"), \
    X(TOKEN_GREATER_EQUAL, "GREATER_EQUAL"), \
    X(TOKEN_LESS, "LESS"), \
    X(TOKEN_LESS_EQUAL, "LESS_EQUAL"), \
    /* Literals */ \
    X(TOKEN_IDENTIFIER, "IDENTIFIER"), \
    X(TOKEN_STRING, "STRING"), \
    X(TOKEN_NUMBER, "NUMBER"), \
    /* Keywords */ \
    X(TOKEN_AND, "AND"), \
    X(TOKEN_CLASS, "CLASS"), \
    X(TOKEN_ELSE, "ELSE"), \
    X(TOKEN_FALSE, "FALSE"), \
    X(TOKEN_FUN, "FUN"), \
    X(TOKEN_FOR, "FOR"), \
    X(TOKEN_IF, "IF"), \
    X(TOKEN_NIL, "NIL"), \
    X(TOKEN_OR, "OR"), \
    X(TOKEN_PRINT, "PRINT"), \
    X(TOKEN_RETURN, "RETURN"), \
    X(TOKEN_SUPER, "SUPER"), \
    X(TOKEN_THIS, "THIS"), \
    X(TOKEN_TRUE, "TRUE"), \
    X(TOKEN_VAR, "VAR"), \
    X(TOKEN_WHILE, "WHILE"), \
    /* End of file */ \
    X(TOKEN_EOF, "EOF"),


typedef enum {

#define X(tokentype, name) tokentype
    TOKEN_LIST
#undef X

    TOKEN_TYPE_COUNT
} TokenType;

const char *TokenNames[TOKEN_TYPE_COUNT] = {
#define X(tokentype, name) name
    TOKEN_LIST
#undef X
};

typedef struct {
    TokenType type;
    StringView lexeme;    
    void *literal;

    // Error reporting
    const char *file;
    size_t line;
} Token;

void print_token(Token token) {
    printf("[%s - %.*s]\n", TokenNames[token.type], (int)token.lexeme.count, token.lexeme.data);
}

typedef struct {
    StringView source;
    Token *tokens;   
} Lexer;


#endif // LEXER_H_