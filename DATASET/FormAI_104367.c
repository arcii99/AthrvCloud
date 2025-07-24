//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filepath = argv[1];
    int file_desc = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file_desc == -1) {
        fprintf(stderr, "Failed to open file at %s. Error: %s\n", filepath, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(STDIN_FILENO, buffer, 1024)) > 0) {
        if (write(file_desc, buffer, bytes_read) != bytes_read) {
            fprintf(stderr, "Failed to write to file at %s. Error: %s\n", filepath, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from stdin. Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    close(file_desc);
    printf("File created at %s and input copied to it successfully.\n", filepath);

    return 0;
}