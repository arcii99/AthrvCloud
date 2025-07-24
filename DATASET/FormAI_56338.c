//FormAI DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    file = fopen(filename, "r");
    if (!file) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    char buffer[512];
    int lines_read = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        lines_read++;
        printf("%d: %s", lines_read, buffer);
    }

    if (ferror(file)) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (fclose(file) == EOF) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
}