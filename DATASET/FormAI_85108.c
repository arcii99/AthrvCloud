//FormAI DATASET v1.0 Category: System administration ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_usage(char *program_name) {
    printf("Usage: %s <source_file> <destination_file>\n", program_name);
}

int main(int argc, char *argv[]) {
    int fd_source, fd_dest, n;
    char buf[BUFSIZ];

    // check if correct number of arguments are passed
    if (argc != 3) {
        print_usage(argv[0]);
        exit(1);
    }

    // open source file
    if ((fd_source = open(argv[1], O_RDONLY)) < 0) {
        perror("Error opening source file");
        exit(1);
    }

    // create or truncate destination file
    if ((fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        perror("Error creating or truncating destination file");
        close(fd_source);
        exit(1);
    }

    // copy data from source file to destination file
    while ((n = read(fd_source, buf, BUFSIZ)) > 0) {
        if (write(fd_dest, buf, n) != n) {
            perror("Error writing to destination file");
            close(fd_source);
            close(fd_dest);
            exit(1);
        }
    }

    // check for read error
    if (n < 0) {
        perror("Error reading from source file");
        close(fd_source);
        close(fd_dest);
        exit(1);
    }

    // close file descriptors
    close(fd_source);
    close(fd_dest);

    printf("File successfully copied from %s to %s\n", argv[1], argv[2]);

    return 0;
}