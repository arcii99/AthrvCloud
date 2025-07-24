//FormAI DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *source_file_ptr = fopen(argv[1], "rb");
    if (!source_file_ptr) {
        printf("Error: failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *destination_file_ptr = fopen(argv[2], "wb");
    if (!destination_file_ptr) {
        printf("Error: failed to open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source_file_ptr)) > 0) {
        bytes_written = fwrite(buffer, sizeof(char), bytes_read, destination_file_ptr);
        if (bytes_written != bytes_read) {
            printf("Error: failed to write to %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

    printf("%s successfully backed up to %s\n", argv[1], argv[2]);

    fclose(source_file_ptr);
    fclose(destination_file_ptr);

    return 0;
}