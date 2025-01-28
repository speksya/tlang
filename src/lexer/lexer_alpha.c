#include <ctype.h>
#include <stdlib.h>

#include "errors/errors.h"
#include "token/token.h"

#include "lexer.h"

Token* lexer_get_identifier(const char* identifier) {
    Token* keyword = token_iskeyword(identifier);
    if (keyword != NULL) {
        return keyword;
    }

    Token* type = token_istype(identifier);
    if (type != NULL) {
        return type;
    }

    Token* logical = token_islogical(identifier);
    if (logical != NULL) {
        return logical;
    }

    return token_init(TOKEN_IDENTIFIER, identifier);
}

Token* lexer_parse_identifier(Lexer* lexer) {
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
