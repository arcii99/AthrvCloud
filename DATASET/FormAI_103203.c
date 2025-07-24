//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *filename = argv[1];
    ssize_t read_size;
    char buffer[BUFFER_SIZE];
    int fd;
    
    fd = open(filename, O_RDONLY);
    if(fd == -1) {
        fprintf(stderr, "Failed to open file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("Reading contents of file: %s\n", filename);
    while((read_size = read(fd, buffer, BUFFER_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, read_size);
    }
    
    if(read_size == -1) {
        fprintf(stderr, "Failed to read from file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if(close(fd) == -1) {
        fprintf(stderr, "Failed to close file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("File reading successfully completed.\n");
    
    return 0;
}