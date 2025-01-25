#include <stdlib.h>
#include <stdio.h>

#include "errors.h"

void throw_error(char* message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}
