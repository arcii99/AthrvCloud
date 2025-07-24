//FormAI DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void create_file(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    create_file(filename);

    return EXIT_SUCCESS;
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        if (errno == EACCES) {
            fprintf(stderr, "permission denied\n");
        } else if (errno == ENOENT) {
            fprintf(stderr, "could not find path\n");
        } else {
            perror("fopen");
        }
        exit(EXIT_FAILURE);
    }

    fputs("Hello, World!", file);

    if (fclose(file) == EOF) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}