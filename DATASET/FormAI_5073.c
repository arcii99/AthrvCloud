//FormAI DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {

    if(argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE* source_file = fopen(argv[1], "rb");
    if(source_file == NULL) {
        printf("Failed to open source file: %s\n", argv[1]);
        return 1;
    }

    FILE* destination_file = fopen(argv[2], "wb");
    if(destination_file == NULL) {
        printf("Failed to open destination file: %s\n", argv[2]);
        fclose(source_file);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t n_bytes_read;

    while((n_bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) != 0) {
        size_t n_bytes_written = fwrite(buffer, 1, n_bytes_read, destination_file);
        if(n_bytes_written != n_bytes_read) {
            printf("Failed to write to destination file!\n");
            fclose(source_file);
            fclose(destination_file);
            return 1;
        }
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File synchronization completed successfully!\n");

    return 0;
}