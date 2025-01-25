#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors/errors.h"

#include "io.h"

char* io_read(const char* name) {
    FILE* file = fopen(name, "r");
    if (file == NULL) {
        throw_error(FILE_READ_ERROR);
    }

    char* buffer = malloc(sizeof(char));
    if (buffer == NULL) {
        fclose(file);
        throw_error(ALLOCATION_ERROR);
    }

    char* lineptr = NULL;
    size_t length = 0;
    ssize_t line;

    while ((line = getline(&lineptr, &length, file)) != -1) {
        buffer = realloc(buffer, strlen(buffer) + line);
        if (buffer == NULL) {
            fclose(file);
            free(buffer);
            free(lineptr);
            throw_error(REALLOCATION_ERROR);
        }
        strcat(buffer, lineptr);
    }

    free(lineptr);
    fclose(file);

    return buffer;
}
