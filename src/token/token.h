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

    /* Keywords */

    TOKEN_DET,
    TOKEN_CONST,
    TOKEN_FUN,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_MATCH,
    TOKEN_DO,
    TOKEN_WHILE,
    TOKEN_FOR,
    TOKEN_FOREACH,
    TOKEN_UNTIL,
    TOKEN_IN,
    TOKEN_IS,
    TOKEN_RETURN,
    TOKEN_BREAK,
    TOKEN_DEFAULT,
    TOKEN_THEN,
    TOKEN_ARRAY,
    TOKEN_IDENTIFIER,

    /* Types */

    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_BOOL,
    TOKEN_VOID,
    TOKEN_NIL,

    /* Logical operators */

    TOKEN_AND,
    TOKEN_NOT,
    TOKEN_OR,
    TOKEN_GREATER,
    TOKEN_LESS,
    TOKEN_EQUAL,
    TOKEN_THAN,

    /* Operators */

    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_MODULO,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASSIGN,
    TOKEN_QUESTION,

    /* Grammar */

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
    TOKEN_UNKNOWN,
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

/**
 * @brief Checks if the given value is a keyword and returns the corresponding token.
 *
 * @param value String value to check against keyword list.
 * @return Pointer to the Token if the value is a keyword, otherwise NULL.
 */
Token* token_iskeyword(const char* value);

/**
 * @brief Checks if the given value is a type and returns the corresponding token.
 *
 * @param value String value to check against type list.
 * @return Pointer to the Token if the value is a type, otherwise NULL.
 */
Token* token_istype(const char* value);

/**
 * @brief Checks if the given value is a logical operator and returns the corresponding token.
 *
 * @param value String value to check against logical operator list.
 * @return Pointer to the Token if the value is a logical operator, otherwise NULL.
 */
Token* token_islogical(const char* value);

#endif
