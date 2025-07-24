//FormAI DATASET v1.0 Category: Error handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    int fd;
    char *filename = "test.txt";

    // Open file
    if ((fd = open(filename, O_RDONLY)) < 0) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Read file
    char buffer[256];
    if (read(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to read file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Print file contents
    printf("File contents:\n%s", buffer);

    // Close file
    if (close(fd) < 0) {
        perror("Failed to close file");
        exit(EXIT_FAILURE);
    }

    // Success!
    printf("Program executed successfully!\n");
    return EXIT_SUCCESS;
}