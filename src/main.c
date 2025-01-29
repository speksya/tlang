#include <stdlib.h>
#include <stdio.h>

#include "errors/errors.h"
#include "io/io.h"
#include "lexer/lexer.h"
#include "token/token.h"

// TODO: temp function. remove later
void print_tokens(Lexer* lexer) {
    while(lexer->character != '\0') {
        Token* token = lexer_tokenize(lexer);
        printf("%d\t", token->token);
        printf("%s\n", token->value);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        throw_error(FILE_NOT_SPECIFIED_NAME_ERROR);
    }

    const char* filename = *++argv; 
    char* buffer = io_read(filename);

    Lexer* lexer = lexer_init(buffer);

    print_tokens(lexer);

    free(buffer);
    free(lexer);

    return EXIT_SUCCESS;
}
