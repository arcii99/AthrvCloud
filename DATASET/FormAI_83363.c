//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX_BUF 1024

int main(int argc, char** argv){
    if(argc < 3){
        printf("Usage: %s source_file target_file\n", argv[0]);
        exit(1);
    }

    int src_fd, tar_fd, n;
    char buf[MAX_BUF];

    src_fd = open(argv[1], O_RDONLY);
    if(src_fd == -1){
        perror("Unable to open the source file");
        exit(1);
    }

    tar_fd = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if(tar_fd == -1){
        perror("Unable to create the target file");
        exit(1);
    }

    while((n = read(src_fd, buf, MAX_BUF)) > 0){
        if(write(tar_fd, buf, n) != n){
            perror("Error while writing data");
            exit(1);
        }
    }

    if(n == -1){
        perror("Error while reading data");
        exit(1);
    }

    if(close(src_fd) == -1){
        perror("Error while closing the source file");
        exit(1);
    }

    if(close(tar_fd) == -1){
        perror("Error while closing the target file");
        exit(1);
    }

    printf("File synchronization complete!\n");

    return 0;
}