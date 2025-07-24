//FormAI DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *source_file, *destination_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if(argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_file = fopen(argv[1], "rb");
    if(source_file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    destination_file = fopen(argv[2], "wb");
    if(destination_file == NULL) {
        printf("Error opening file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, destination_file);
    }

    if(ferror(source_file)) {
        printf("Error reading from file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if(ferror(destination_file)) {
        printf("Error writing to file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("File %s successfully recovered to %s\n", argv[1], argv[2]);

    fclose(source_file);
    fclose(destination_file);
    return 0;
}