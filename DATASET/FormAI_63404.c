//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char *dir = argv[1];

    printf("Searching for files in %s directory...\n", dir);

    // Check if directory exists
    if (access(dir, F_OK) != 0) {
        printf("Error: %s directory does not exist\n", dir);
        exit(1);
    }

    // Check if directory is readable
    if (access(dir, R_OK) != 0) {
        printf("Error: %s directory is not readable\n", dir);
        exit(1);
    }

    // Check if directory is writable
    if (access(dir, W_OK) != 0) {
        printf("Error: %s directory is not writable\n", dir);
        exit(1);
    }

    printf("%s directory is accessible and writable.\n", dir);

    return 0;
}