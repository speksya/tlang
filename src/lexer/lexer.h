#ifndef LEXER
#define LEXER

#include <stddef.h>
#include "../token/token.h"

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
void lexer_advance(Lexer* lexer);

/**
 * @brief Skips whitespace characters in the input buffer.
 * 
 * @param lexer Initialized Lexer instance.
 */
void lexer_skip_whitespace(Lexer* lexer);

#endif 
