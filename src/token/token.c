#include <stdlib.h>
#include <string.h>

#include "errors/errors.h"

#include "token.h"

Token* token_init(int type, const char* value) {
    Token* token = malloc(sizeof(Token));
    if (token == NULL) {
        throw_error(ALLOCATION_ERROR);
    }

    token->token = type;
    token->value = value;

    return token;
}

Token* token_iskeyword(const char* value) {
    if (strcmp(value, "det") == 0) {
        return token_init(TOKEN_DET, "det");
    }

    if (strcmp(value, "const") == 0) {
        return token_init(TOKEN_CONST, "const");
    }

    if (strcmp(value, "fun") == 0) {
        return token_init(TOKEN_FUN, "fun");
    }

    if (strcmp(value, "if") == 0) {
        return token_init(TOKEN_IF, "if");
    }

    if (strcmp(value, "else") == 0) {
        return token_init(TOKEN_ELSE, "else");
    }

    if (strcmp(value, "match") == 0) {
        return token_init(TOKEN_MATCH, "match");
    }

    if (strcmp(value, "do") == 0) {
        return token_init(TOKEN_DO, "do");
    }

    if (strcmp(value, "while") == 0) {
        return token_init(TOKEN_WHILE, "while");
    }

    if (strcmp(value, "for") == 0) {
        return token_init(TOKEN_FOR, "for");
    }

    if (strcmp(value, "foreach") == 0) {
        return token_init(TOKEN_FOREACH, "foreach");
    }

    if (strcmp(value, "until") == 0) {
        return token_init(TOKEN_UNTIL, "until");
    }

    if (strcmp(value, "in") == 0) {
        return token_init(TOKEN_IN, "in");
    }

    if (strcmp(value, "is") == 0) {
        return token_init(TOKEN_IS, "is");
    }

    if (strcmp(value, "return") == 0) {
        return token_init(TOKEN_RETURN, "return");
    }

    if (strcmp(value, "break") == 0) {
        return token_init(TOKEN_BREAK, "break");
    }

    if (strcmp(value, "default") == 0) {
        return token_init(TOKEN_DEFAULT, "default");
    }

    if (strcmp(value, "then") == 0) {
        return token_init(TOKEN_THEN, "then");
    }

    if (strcmp(value, "array") == 0) {
        return token_init(TOKEN_ARRAY, "array");
    }

    return NULL;
}

Token* token_istype(const char* value) {
    if (strcmp(value, "string") == 0) {
        return token_init(TOKEN_STRING, "string");
    }

    if (strcmp(value, "number") == 0) {
        return token_init(TOKEN_NUMBER, "number");
    }

    if (strcmp(value, "bool") == 0) {
        return token_init(TOKEN_BOOL, "bool");
    }

    if (strcmp(value, "void") == 0) {
        return token_init(TOKEN_VOID, "void");
    }

    if (strcmp(value, "nil") == 0) {
        return token_init(TOKEN_NIL, "nil");
    }

    return NULL;
}

Token* token_islogical(const char* value) {
    if (strcmp(value, "and") == 0) {
        return token_init(TOKEN_AND, "and");
    }

    if (strcmp(value, "not") == 0) {
        return token_init(TOKEN_NOT, "not");
    }

    if (strcmp(value, "or") == 0) {
        return token_init(TOKEN_OR, "or");
    }

    if (strcmp(value, "greater") == 0) {
        return token_init(TOKEN_GREATER, "greater");
    }

    if (strcmp(value, "less") == 0) {
        return token_init(TOKEN_LESS, "less");
    }

    if (strcmp(value, "equal") == 0) {
        return token_init(TOKEN_EQUAL, "equal");
    }

    if (strcmp(value, "than") == 0) {
        return token_init(TOKEN_LESS, "than");
    }

    return NULL;
}
