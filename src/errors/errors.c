#include <stdlib.h>
#include <stdio.h>

#include "errors.h"

void throw_error(char* message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

void throw_unexpected_character_error(char character) {
    printf("Unexpected character `%c` (%d)\n", character, (int)character);
    exit(EXIT_FAILURE);
}
