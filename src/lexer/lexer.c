#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "errors/errors.h"

#include "lexer.h"

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

void lexer_advance(Lexer* lexer) {
    if (lexer->position < lexer->buffer_size && lexer->character != '\0') {
        lexer->position += 1;
        lexer->character = lexer->buffer[lexer->position];
    }
}

void lexer_skip_whitespace(Lexer* lexer) {
    if (isspace(lexer->character)) {
        lexer_advance(lexer);
    }
}

Token* lexer_tokenize(Lexer* lexer) {
    Token* tokens = malloc(sizeof(Token));
    if (tokens == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    while(lexer->character != '\0') {
        lexer_skip_whitespace(lexer);
    }

    return tokens;
}
