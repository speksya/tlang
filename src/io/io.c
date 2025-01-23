#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

char* io_read(const char* name) {
    FILE* file = fopen(name, "r");
    if (file == NULL) {
        exit(EXIT_FAILURE);
    }

    char* buffer = malloc(sizeof(char));
    buffer[0] = '\0';

    char* lineptr = NULL;
    size_t length = 0;
    ssize_t line;

    while ((line = getline(&lineptr, &length, file)) != -1) {
        buffer = realloc(buffer, (strlen(buffer) + strlen(lineptr)) * sizeof(char));
        strcat(buffer, lineptr);
    }

    fclose(file);

    if (lineptr != NULL) {
        free(lineptr);
    }

    return buffer;
}
