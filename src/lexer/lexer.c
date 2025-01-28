#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "errors/errors.h"
#include "token/token.h"

#include "lexer.h"

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
