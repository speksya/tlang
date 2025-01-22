#ifndef LEXER
#define LEXER

/**
 * @file lexer.h
 * @brief Lexer module for tokenizing input.
 */

/**
 * @brief Enumeration of token types.
 * 
 * Represents all possible token types, including keywords, types, operators, and grammar symbols.
 */
typedef enum {
    TOKEN_KEYWORD,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_BOOL,
    TOKEN_VOID,
    TOKEN_NIL,
    TOKEN_AND,
    TOKEN_NOT,
    TOKEN_OR,
    TOKEN_GREATER,
    TOKEN_LESS,
    TOKEN_EQUAL,
    TOKEN_THAN,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_MODULO,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASSIGN,
    TOKEN_QUESTION,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_DOUBLE_QUOTE,
    TOKEN_SINGLE_QUOTE,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_DOT,
    TOKEN_COMMA,
    TOKEN_EXCLAMATION,
} TokenType;

/**
 * @brief Represents a token.
 * 
 * Contains the token type and its associated value. 
 */
typedef struct {
    TokenType token;
    char* value;
} Token;

/**
 * @brief Initializes the lexer and tokenizes the input buffer.
 * @param buffer Input string to tokenize.
 * @return Pointer to the first token in the tokenized list.
 */
Token* init(const char* buffer);

#endif 
