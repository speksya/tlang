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

    /* General */

    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_DIGIT,

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
 * @brief Array of keywords.
 *
 * Represents all possible keywords, including types, logical operators.
 */
static Token keywords[] = {
    TOKEN_DET, "det",
    TOKEN_CONST, "const",
    TOKEN_FUN, "fun",
    TOKEN_IF, "if",
    TOKEN_ELSE, "else",
    TOKEN_MATCH, "match",
    TOKEN_DO, "do",
    TOKEN_WHILE, "while",
    TOKEN_FOR, "for",
    TOKEN_FOREACH, "foreach",
    TOKEN_UNTIL, "until",
    TOKEN_IN, "in",
    TOKEN_IS, "is",
    TOKEN_RETURN, "return",
    TOKEN_BREAK, "break",
    TOKEN_DEFAULT, "default",
    TOKEN_THEN, "then",
    TOKEN_ARRAY, "array",
    TOKEN_STRING, "string",
    TOKEN_NUMBER, "number",
    TOKEN_BOOL, "bool",
    TOKEN_VOID, "void",
    TOKEN_NIL, "nil",
    TOKEN_AND, "and",
    TOKEN_NOT, "not",
    TOKEN_OR, "or",
    TOKEN_GREATER, "greater",
    TOKEN_LESS, "less",
    TOKEN_EQUAL, "equal",
    TOKEN_THAN, "than",
};

/**
 * @brief Creates a token with the given type and value.
 *
 * @param type Token type from TokenType enum.
 * @param value String value associated with the token.
 * @return Pointer to the newly created Token.
 */
Token* token_init(TokenType type, const char* value);

/**
 * @brief Checks if the given value is a keyword and returns the corresponding token.
 *
 * @param value String value to check against keyword list.
 * @return Pointer to the Token if the value is a keyword, otherwise NULL.
 */
Token* token_iskeyword(const char* value);

#endif
