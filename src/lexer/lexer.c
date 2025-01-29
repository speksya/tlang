#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "errors/errors.h"
#include "token/token.h"

#include "lexer.h"

static void lexer_advance(Lexer* lexer) {
    if (lexer->position < lexer->buffer_size && lexer->character != '\0') {
        lexer->position += 1;
        lexer->character = lexer->buffer[lexer->position];
    }
}

static void lexer_skip_whitespace(Lexer* lexer) {
    if (isspace(lexer->character)) {
        lexer_advance(lexer);
    }
}

static Token* lexer_get_identifier(const char* identifier) {
    Token* keyword = token_iskeyword(identifier);
    if (keyword != NULL) {
        return keyword;
    }

    return token_init(TOKEN_IDENTIFIER, identifier);
}

static Token* lexer_parse_identifier(Lexer* lexer) {
    size_t identifier_size = 1;
    size_t index = 0;

    char* identifier = malloc(sizeof(char));
    if (identifier == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    while(isalpha(lexer->character)) {
        if (index + 1 > identifier_size) {
            identifier_size *= 2;
            identifier = realloc(identifier, identifier_size);
            if (identifier == NULL) {
                free(identifier);
                throw_error(REALLOCATION_ERROR);
            }
        }
        identifier[index] = lexer->character;
        lexer_advance(lexer);
        index++;
    }

    identifier[index] = '\0';

    return lexer_get_identifier(identifier);
}

static Token* lexer_parse_number(Lexer* lexer) {
    size_t number_size = 1;
    size_t index = 0;

    char* number = malloc(sizeof(char));
    if (number == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    while(isdigit(lexer->character)) {
        if (index + 1 > number_size) {
            number_size *= 2;
            number = realloc(number, number_size);
            if (number == NULL) {
                free(number);
                throw_error(REALLOCATION_ERROR);
            }
        }
        number[index] = lexer->character;
        lexer_advance(lexer);
        index++;
    }

    number[index] = '\0';

    return token_init(TOKEN_DIGIT, number);
}

Token* lexer_tokenize(Lexer* lexer) {
    Token* tokens = malloc(sizeof(Token));
    if (tokens == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    while(lexer->character != '\0') {
        lexer_skip_whitespace(lexer);

        if (isalpha(lexer->character)) {
            Token* identifier = lexer_parse_identifier(lexer);
            // TODO: remove printf
            printf("%d\t", identifier->token);
            // TODO: remove printf
            printf("%s\n", identifier->value);
        }

        if (isdigit(lexer->character)) {
            Token* number = lexer_parse_number(lexer);
            // TODO: remove printf
            printf("%d\t", number->token);
            // TODO: remove printf
            printf("%s\n", number->value);
        }

        lexer_advance(lexer);
    }

    return tokens;
}

Lexer* lexer_init(char* buffer) {
    Lexer* lexer = malloc(sizeof(Lexer));
    if (lexer == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    lexer->buffer = buffer;
    lexer->buffer_size = strlen(buffer);
    lexer->position = 0;
    lexer->character = buffer[lexer->position];

    return lexer;
}
