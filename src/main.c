#include <stdlib.h>
#include <stdio.h>
#include "io/io.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s", "Please specify file name");
        return EXIT_FAILURE;
    }

    char* filename = *++argv; 
    char* buffer = read_file(filename);
    printf("%s", buffer);
    return EXIT_SUCCESS;
}
