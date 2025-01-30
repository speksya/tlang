#ifndef LEXER
#define LEXER

#include <stddef.h>

#include "token/token.h"

/**
 * @file lexer.h
 * @brief Lexer module for tokenizing input.
 */

/**
 * @brief Lexer structure for tokenizing input.
 *
 * Holds the input buffer, current character, buffer size, and position.
 */
typedef struct {
    char* buffer;
    char character;
    size_t buffer_size;
    size_t position;
} Lexer;

/**
 * @brief Initializes a lexer with the input buffer.
 *
 * @param buffer Input string to tokenize.
 * @return Pointer to the initialized Lexer.
 */
Lexer* lexer_init(char* buffer);

/**
 * @brief Tokenizes the input buffer using the lexer.
 *
 * @param lexer Initialized Lexer instance.
 * @return Pointer to the first token in the tokenized list.
 */
Token* lexer_tokenize(Lexer* lexer);

/**
 * @brief Moves the lexer to the next character in the input buffer.
 *
 * @param lexer Initialized Lexer instance.
 */
static void lexer_advance(Lexer* lexer);

/**
 * @brief Advances the lexer by a specified offset and returns the character at that position.
 *
 * @param lexer Initialized Lexer instance.
 * @param offset Number of positions to advance.
 * @return Character at the offset position.
 */
static char lexer_advance_offset(const Lexer* lexer, const size_t offset);

/**
 * @brief Moves the lexer to the next character in the input buffer.
 *
 * @param lexer Initialized Lexer instance.
 * @param type Token type.
 * @return Pointer to the corresponding Token.
 */
static Token* lexer_advance_token(Lexer* lexer, const TokenType type);

/**
 * @brief Advances the lexer and returns a token with the specified type and value.
 *
 * @param lexer Initialized Lexer instance.
 * @param type Token type.
 * @param value String value of the token.
 * @return Pointer to the corresponding Token.
 */
static Token* lexer_advance_string_token(Lexer* lexer, const TokenType type, const char* value);

/**
 * @brief Skips whitespace characters in the input buffer.
 *
 * @param lexer Initialized Lexer instance.
 */
static void lexer_skip_whitespace(Lexer* lexer);

/**
 * @brief Returns a token for the given identifier, checking if it is a keyword, type, or logical operator.
 *
 * @param identifier String to check.
 * @return Pointer to the corresponding Token.
 */
static Token* lexer_get_alpha(const char* identifier);

/**
 * @brief Parses an identifier from the input buffer and returns its token.
 *
 * @param lexer Initialized Lexer instance.
 * @return Pointer to the parsed Token.
 */
static Token* lexer_parse_alpha(Lexer* lexer);

/**
 * @brief Returns a token for the given number
 *
 * @param lexer Initialized Lexer instance.
 * @return Pointer to the corresponding Token.
 */
static Token* lexer_parse_digit(Lexer* lexer);

/**
 * @brief Parses a plus sign and returns the corresponding token (e.g., '+', '++', '+=').
 *
 * @param lexer Initialized Lexer instance.
 * @return Pointer to the corresponding Token.
 */
static Token* lexer_parse_plus(Lexer* lexer);

/**
 * @brief Parses a minus sign and returns the corresponding token (e.g., '-', '--', '-=', '->').
 *
 * @param lexer Initialized Lexer instance.
 * @return Pointer to the corresponding Token.
 */
static Token* lexer_parse_minus(Lexer* lexer);

/**
 * @brief Parses an assignment operator and returns the corresponding token (e.g., '=', '+=', '-=', '*=', '/=', '%=').
 *
 * @param lexer Initialized Lexer instance.
 * @param assignType Token type for the assignment operator.
 * @param type Token type for the base operator.
 * @param value String value of the token.
 * @return Pointer to the corresponding Token.
 */
static Token* lexer_parse_assign(Lexer* lexer, const TokenType assignType, const TokenType type, const char* value);

#endif 
