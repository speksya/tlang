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
