#include <stdlib.h>
#include <ctype.h>

#include "errors/errors.h"
#include "token/token.h"

#include "lexer.h"

Token* lexer_parse_number(Lexer* lexer) {
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

    return token_init(TOKEN_DIGHT, number);
}
