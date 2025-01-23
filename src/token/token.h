#ifndef TOKEN
#define TOKEN

/**
 * @file token.h
 * @brief Tokens module for describing tokens.
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
    const char* value;
} Token;

/**
 * @brief Creates a token with the given type and value.
 * 
 * @param type Token type from TokenType enum.
 * @param value String value associated with the token.
 * @return Pointer to the newly created Token.
 */
Token* token_init(int type, const char* value);

#endif
