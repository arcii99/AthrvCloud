//FormAI DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define CHUNK_SIZE 1024 // change the chunk size as per requirement

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source_file = argv[1];
    char *destination_file = argv[2];

    // open source file in read-only mode
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Error: Failed to open source file");
        exit(EXIT_FAILURE);
    }

    // open destination file in write-only mode
    int destination_fd = open(destination_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (destination_fd == -1) {
        perror("Error: Failed to open destination file");
        exit(EXIT_FAILURE);
    }

    char buffer[CHUNK_SIZE];
    ssize_t bytes_read, bytes_written;

    // read source file in chunks and write to destination file
    while ((bytes_read = read(source_fd, buffer, CHUNK_SIZE)) > 0) {
        bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error: Failed to write to destination file");
            exit(EXIT_FAILURE);
        }
    }

    // close file descriptors
    close(source_fd);
    close(destination_fd);

    printf("File backup successful!\n");

    return 0;
}