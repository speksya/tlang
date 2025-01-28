#include <stdlib.h>

#include "errors/errors.h"
#include "io/io.h"
#include "lexer/lexer.h"
#include "token/token.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        throw_error(FILE_NOT_SPECIFIED_NAME_ERROR);
    }

    const char* filename = *++argv; 
    char* buffer = io_read(filename);

    Lexer* lexer = lexer_init(buffer);
    Token* tokens = lexer_tokenize(lexer);

    free(buffer);
    free(lexer);
    free(tokens);

    return EXIT_SUCCESS;
}
