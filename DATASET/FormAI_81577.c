//FormAI DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./admin_mode filename\n");
        exit(1);
    }

    char *filename = argv[1];

    struct stat file;
    if (stat(filename, &file) == -1) {
        printf("Error: file %s not found\n", filename);
        exit(1);
    }

    // check if user has root privileges
    if (getuid() != 0) {
        printf("Error: you need to be root to run this program\n");
        exit(1);
    }

    // disable the execute permission for other users
    file.st_mode &= ~(S_IXUSR | S_IXGRP | S_IXOTH);
    if (chmod(filename, file.st_mode) == -1) {
        printf("Error: failed to change file permissions\n");
        exit(1);
    }

    printf("Admin mode enabled for file: %s\n", filename);

    return 0;
}