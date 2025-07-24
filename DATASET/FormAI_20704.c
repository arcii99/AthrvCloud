//FormAI DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void copy_file(FILE *source, FILE *destination) {
    int c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Error opening source file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL) {
        printf("Error opening destination file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Copying file %s to %s\n", argv[1], argv[2]);

    copy_file(source, destination);

    printf("Copy complete\n");

    fclose(source);
    fclose(destination);

    return 0;
}