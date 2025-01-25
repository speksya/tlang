#include <stdlib.h>

#include "errors/errors.h"

#include "token.h"

Token* token_init(int type, const char* value) {
    Token* token = malloc(sizeof(Token));
    if (token == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    token->value = value;
    token->token = type;

    return token;
}
