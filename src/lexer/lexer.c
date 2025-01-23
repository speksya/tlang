#include <stdlib.h>
#include <string.h>
#include "lexer.h"

Lexer* lexer_init(char* buffer) {
    Lexer* lexer = malloc(sizeof(Lexer));
    lexer->buffer = buffer;
    lexer->buffer_size = strlen(buffer);
    lexer->position = 0;
    lexer->character = buffer[lexer->position];

    return lexer;
}

Token* lexer_tokenize(Lexer* lexer) {
    Token* tokens = malloc(sizeof(Token));

    while(lexer->character != '\0') {}

    return tokens;
}
