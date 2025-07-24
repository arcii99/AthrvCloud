//FormAI DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <original file> <target file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    int source_file, target_file, read_bytes;
    
    source_file = open(argv[1], O_RDONLY);
    if(source_file == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    target_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(target_file == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while((read_bytes = read(source_file, buffer, BUFFER_SIZE)) > 0) {
        if(write(target_file, buffer, read_bytes) != read_bytes) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if(read_bytes == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if(close(source_file) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    if(close(target_file) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");

    return 0;
}