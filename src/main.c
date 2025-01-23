#include <stdlib.h>
#include <stdio.h>
#include "io/io.h"
#include "lexer/lexer.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s", "Please specify file name");
        return EXIT_FAILURE;
    }

    char* filename = *++argv; 
    char* buffer = io_read(filename);

    Lexer* lexer = lexer_init(buffer);
    Token* tokens = lexer_tokenize(lexer);

    return EXIT_SUCCESS;
}
