//FormAI DATASET v1.0 Category: Error handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

char* read_data(FILE* fp, size_t size) {
    char* buffer = (char*)malloc(sizeof(char) * size);
    if(buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(buffer, sizeof(char), size, fp);
    if(bytesRead < size) {
        if(ferror(fp)) {
            fprintf(stderr, "Error reading from file.\n");
            free(buffer);
            exit(EXIT_FAILURE);
        }
        else {
            fprintf(stderr, "Unexpected end of file.\n");
        }
    }

    return buffer;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char* data = read_data(fp, 1024);
    printf("%s\n", data);

    free(data);
    fclose(fp);

    return EXIT_SUCCESS;
}