//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    // ensure user has root access
    if (getuid() != 0) {
        printf("You must have root access to run this program.\n");
        exit(1);
    }

    // check command line arguments
    if (argc != 3) {
        printf("Please enter two arguments: the path to an existing file and the new permissions in octal format.\n");
        exit(1);
    }

    // get file path and permissions
    char *path = argv[1];
    int permissions = strtol(argv[2], NULL, 8);

    // change file permissions
    if (chmod(path, permissions) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    // confirm success
    printf("File permissions successfully changed to %d.\n", permissions);
    
    return 0;
}