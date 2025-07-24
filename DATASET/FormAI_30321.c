//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define FILENAME "test.txt"

int main(int argc, char **argv) {
    int fd, n;
    char buffer[BUFFER_SIZE];
    struct stat file_stat;

    // Check if file exists
    if (access(FILENAME, F_OK) != -1) {

        // If file exists, get file information
        if (stat(FILENAME, &file_stat) != 0) {
            perror("Failed to get file information");
            exit(EXIT_FAILURE);
        }

        printf("File size: %ld bytes\n", file_stat.st_size);

        // Open file
        fd = open(FILENAME, O_RDONLY);

        // Check if file was opened successfully
        if (fd == -1) {
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }

        // Read from file and print to stdout
        while ((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
            if (write(STDOUT_FILENO, buffer, n) != n) {
                perror("Failed to write to stdout");
                exit(EXIT_FAILURE);
            }
        }

        // Close file
        if (close(fd) == -1) {
            perror("Failed to close file");
            exit(EXIT_FAILURE);
        }
    } else {
        // If file doesn't exist, create it
        fd = open(FILENAME, O_CREAT | O_WRONLY, 0666);

        // Check if file was created successfully
        if (fd == -1) {
            perror("Failed to create file");
            exit(EXIT_FAILURE);
        }

        // Write to file
        if (write(fd, "Hello, world!\n", strlen("Hello, world!\n")) !=
                strlen("Hello, world!\n")) {
            perror("Failed to write to file");
            exit(EXIT_FAILURE);
        }

        // Close file
        if (close(fd) == -1) {
            perror("Failed to close file");
            exit(EXIT_FAILURE);
        }
    }

    return(EXIT_SUCCESS);
}