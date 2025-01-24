#include <stdlib.h>
#include "token.h"

Token* token_init(int type, const char* value) {
    Token* token = malloc(sizeof(Token));

    token->value = value;
    token->token = type;

    return token;
}
