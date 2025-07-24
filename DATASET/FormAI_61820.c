//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    // check if user is root
    if (getuid() != 0) {
        printf("You must be root to execute this program.\n");
        return 1;
    }

    // check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <file name> <permissions>\n", argv[0]);
        printf("Example: %s test.txt 644\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *permissions = argv[2];

    // check if file exists
    struct stat buf;
    if (stat(file_name, &buf) != 0) {
        printf("File does not exist.\n");
        return 1;
    }

    // change file permissions
    if (chmod(file_name, strtol(permissions, 0, 8)) == -1) {
        printf("Failed to change file permissions.\n");
        return 1;
    }

    printf("Successfully changed permissions of %s to %s.\n", file_name, permissions);
    return 0;
}