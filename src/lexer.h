#ifndef LEXER_H_
#define LEXER_H_

#include <sv_str.h>

/* Minimal lexer logic

while not EOF:
    skip whitespace
    if letter → read identifier
    if digit → read number
    if '"' → read string literal
    if symbol → read symbol token
*/

typedef enum {
    // Single-character tokens
    LEFT_PAREN = 0, 
    RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keywords
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    // End of file
    EOF, 

    TOKEN_TYPE_COUNT
} TokenType;

typedef struct {
    TokenType type;
    StringView lexeme;    
    void *literal;

    // Error reporting
    const char *file;
    size_t line;
} Token;

#endif // LEXER_H_