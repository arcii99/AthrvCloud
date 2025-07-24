//FormAI DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

void handle_error(const char* msg, int error) {
    fprintf(stderr, "%s: %s\n", msg, strerror(error));
    exit(EXIT_FAILURE);
}

int main() {
    int fd1, fd2, ret;

    fd1 = open("file1.txt", O_RDONLY);
    if(fd1 == -1) {
        handle_error("Failed to open file1", errno);
    }

    fd2 = open("file2.txt", O_RDONLY | O_CREAT | O_EXCL, 0644);
    if(fd2 == -1) {
        handle_error("Failed to create file2", errno);
    }

    char buf[1024];
    while((ret = read(fd1, buf, sizeof(buf))) > 0) {
        if(write(fd2, buf, ret) != ret) {
            handle_error("Failed to write to file2", errno);
        }
    }

    if(ret < 0) {
        handle_error("Failed to read from file1", errno);
    }

    if(close(fd1) == -1) {
        handle_error("Failed to close file1", errno);
    }

    if(close(fd2) == -1) {
        handle_error("Failed to close file2", errno);
    }

    return 0;
}