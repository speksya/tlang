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

static Token* lexer_advance_token(Lexer* lexer, TokenType type) {
    char* buffer = malloc(sizeof(char) * 2);

    buffer[0] = lexer->character;
    buffer[1] = '\0';

    lexer_advance(lexer);

    return token_init(type, buffer);
}

static void lexer_skip_whitespace(Lexer* lexer) {
    while(isspace(lexer->character)) {
        lexer_advance(lexer);
    }
}

static Token* lexer_get_alpha(const char* identifier) {
    Token* keyword = token_iskeyword(identifier);
    if (keyword != NULL) {
        return keyword;
    }

    return token_init(TOKEN_IDENTIFIER, identifier);
}

static Token* lexer_parse_alpha(Lexer* lexer) {
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

    return lexer_get_alpha(identifier);
}

static Token* lexer_parse_digit(Lexer* lexer) {
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
    while(lexer->character != '\0') {
        lexer_skip_whitespace(lexer);

        if (isalpha(lexer->character)) {
            return lexer_parse_alpha(lexer);
        }

        if (isdigit(lexer->character)) {
            return lexer_parse_digit(lexer);
        }

        switch(lexer->character) {
            case '+':
                return lexer_advance_token(lexer, TOKEN_PLUS);
            case '-':
                return lexer_advance_token(lexer, TOKEN_MINUS);
            case '*':
                return lexer_advance_token(lexer, TOKEN_MULTIPLY);
            case '/':
                return lexer_advance_token(lexer, TOKEN_DIVIDE);
            case '=':
                return lexer_advance_token(lexer, TOKEN_ASSIGN);
            case '?':
                return lexer_advance_token(lexer, TOKEN_QUESTION);
            case '(':
                return lexer_advance_token(lexer, TOKEN_LPAREN);
            case ')':
                return lexer_advance_token(lexer, TOKEN_RPAREN);
            case '{':
                return lexer_advance_token(lexer, TOKEN_LBRACE);
            case '}':
                return lexer_advance_token(lexer, TOKEN_RBRACE);
            case '[':
                return lexer_advance_token(lexer, TOKEN_LBRACKET);
            case ']':
                return lexer_advance_token(lexer, TOKEN_RBRACKET);
            case '"':
                return lexer_advance_token(lexer, TOKEN_DOUBLE_QUOTE);
            case '\'':
                return lexer_advance_token(lexer, TOKEN_SINGLE_QUOTE);
            case ';':
                return lexer_advance_token(lexer, TOKEN_SEMICOLON);
            case ':':
                return lexer_advance_token(lexer, TOKEN_COLON);
            case '.':
                return lexer_advance_token(lexer, TOKEN_DOT);
            case ',':
                return lexer_advance_token(lexer, TOKEN_COMMA);
            case '!':
                return lexer_advance_token(lexer, TOKEN_EXCLAMATION);
            case '\0':
                break;
            default:
                throw_unexpected_character_error(lexer->character);
                break;
        }
    }

    return token_init(TOKEN_EOF, "EOF");
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
