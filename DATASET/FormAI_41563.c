//FormAI DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define ERROR(msg, code) do { \
    fprintf(stderr, "ERROR: %s\n", msg); \
    exit(code); \
} while (0)

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        ERROR("Invalid number of arguments", 1);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        ERROR("Could not open file", 2);
    }

    // Rest of the code goes here...

    fclose(file);
    return 0;
}