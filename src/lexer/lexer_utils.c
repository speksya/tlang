#include <ctype.h>

#include "lexer.h"

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
