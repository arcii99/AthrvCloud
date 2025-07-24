//FormAI DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argc, char *argv[]) {
    int file1, file2, size;
    char *buffer[512];

    if (argc != 3) {
        printf("Oh no! You need to provide two file names as arguments.\n");
        printf("Usage: ./copy file1 file2\n");
        exit(1);
    }

    file1 = open(argv[1], O_RDONLY);
    if (file1 == -1) {
        printf("Yikes! Could not open file %s\n", argv[1]);
        exit(1);
    }

    file2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file2 == -1) {
        printf("OMG! Could not open file %s\n", argv[2]);
        close(file1);
        exit(1);
    }

    while ((size = read(file1, buffer, 512)) > 0) {
        if (write(file2, buffer, size) != size) {
            printf("What?! Error writing to file %s\n", argv[2]);
            close(file1);
            close(file2);
            exit(1);
        }
    }

    if (size == -1) {
        printf("Holy crap! Error reading from file %s\n", argv[1]);
        close(file1);
        close(file2);
        exit(1);
    }

    printf("Great job! File %s has been successfully copied to file %s.\n", argv[1], argv[2]);

    close(file1);
    close(file2);
    exit(0);
}