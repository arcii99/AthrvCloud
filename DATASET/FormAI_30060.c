//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void copy_file(char *src_file, char *dest_file) {
    // Open source file for reading
    int src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        printf("Error: Could not open source file\n");
        exit(EXIT_FAILURE);
    }

    // Open destination file for writing, create it if it doesn't exist
    int dest_fd = open(dest_file, O_CREAT | O_WRONLY, 0644);
    if (dest_fd == -1) {
        printf("Error: Could not open destination file\n");
        exit(EXIT_FAILURE);
    }

    // Read source file and write to destination file
    char buffer[BUFFER_SIZE];
    int read_bytes = 0;
    while ((read_bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        int written_bytes = 0;
        int total_written_bytes = 0;
        while (total_written_bytes < read_bytes) {
            written_bytes = write(dest_fd, buffer + total_written_bytes, read_bytes - total_written_bytes);
            if (written_bytes == -1) {
                printf("Error: Could not write to destination file\n");
                exit(EXIT_FAILURE);
            }
            total_written_bytes += written_bytes;
        }
    }

    // Close files
    close(src_fd);
    close(dest_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [source file] [destination file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check if source file exists
    if (access(argv[1], F_OK) == -1) {
        printf("Error: Source file does not exist\n");
        exit(EXIT_FAILURE);
    }

    // Check if source file is a regular file
    struct stat src_stat;
    if (stat(argv[1], &src_stat) == -1) {
        printf("Error: Could not stat source file\n");
        exit(EXIT_FAILURE);
    }
    if (!S_ISREG(src_stat.st_mode)) {
        printf("Error: Source file is not a regular file\n");
        exit(EXIT_FAILURE);
    }

    // Copy file
    copy_file(argv[1], argv[2]);

    printf("File copied successfully!\n");

    return 0;
}