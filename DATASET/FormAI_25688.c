//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUF 1024

int count_bytes(char *filename){
    int fd, n, total_bytes = 0;
    char buf[MAX_BUF];

    fd = open(filename, O_RDONLY);

    while((n = read(fd, buf, MAX_BUF)) > 0){
        total_bytes += n;
    }

    close(fd);

    return total_bytes;
}

int count_lines(char *filename){
    int fd, count = 0;
    char c;

    fd = open(filename, O_RDONLY);

    while(read(fd, &c, 1) == 1){
        if(c == '\n'){
            count++;
        }
    }

    close(fd);

    return count;
}

void print_error(char *filename){
    printf("Error: Unable to open %s.\n", filename);
    exit(1);
}

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    if(access(filename, F_OK) == -1){
        print_error(filename);
    }

    int bytes = count_bytes(filename);
    int lines = count_lines(filename);

    printf("File: %s\n", filename);
    printf("Total bytes: %d\n", bytes);
    printf("Total lines: %d\n", lines);

    exit(0);
}