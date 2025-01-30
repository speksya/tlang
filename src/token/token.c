#include <stdlib.h>
#include <string.h>

#include "errors/errors.h"

#include "token.h"

Token* token_iskeyword(const char* value) {
    for (size_t i = 0; i < sizeof(keywords) / sizeof(Token); i++) {
        if (strcmp(keywords[i].value, value) == 0) {
            return &keywords[i];
        }
    }

    return NULL;
}

Token* token_init(const TokenType type, const char* value) {
    Token* token = malloc(sizeof(Token));
    if (token == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    token->token = type;
    token->value = value;

    return token;
}
