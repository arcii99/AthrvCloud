//FormAI DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf[1024];

    // Check if the file "example.txt" exists
    if (access("example.txt", F_OK) == -1) {
        // If it does not exist, create the file with read and write permissions for the owner
        fd = open("example.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
        if (fd == -1) {
            perror("Error opening file 'example.txt'");
            exit(EXIT_FAILURE);
        }
        printf("File 'example.txt' created successfully\n");
    } else {
        // If the file already exists, open it in append mode
        fd = open("example.txt", O_WRONLY | O_APPEND);
        if (fd == -1) {
            perror("Error opening file 'example.txt'");
            exit(EXIT_FAILURE);
        }
        printf("File 'example.txt' found and opened in append mode\n");
    }

    // Read input from user and append it to the file
    printf("Enter text to append to file (enter 'quit' to exit):\n");
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (strncmp(buf, "quit", 4) == 0) {
            break;
        }

        if (write(fd, buf, strlen(buf)) == -1) {
            perror("Error writing to file 'example.txt'");
            exit(EXIT_FAILURE);
        }
    }

    printf("Input successfully written to file 'example.txt'\n");

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file 'example.txt'");
        exit(EXIT_FAILURE);
    }

    return 0;
}