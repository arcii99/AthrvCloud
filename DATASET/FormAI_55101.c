//FormAI DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void print_usage() {
    printf("Usage: myprogram source_file destination_file\n");
}

int copy_file(const char *src_path, const char *dst_path) {
    int src_fd, dst_fd, num_read, num_written, ret;
    char buf[BUF_SIZE];

    src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        perror("Open source file");
        return -1;
    }

    dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("Open destination file");
        close(src_fd);
        return -1;
    }

    while ((num_read = read(src_fd, buf, BUF_SIZE)) > 0) {
        num_written = write(dst_fd, buf, num_read);
        if (num_written != num_read) {
            perror("Write to destination file");
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }

    if (num_read == -1) {
        perror("Read from source file");
        ret = -1;
    } else {
        ret = 0;
    }

    if (close(src_fd) == -1) {
        perror("Close source file");
        ret = -1;
    }

    if (close(dst_fd) == -1) {
        perror("Close destination file");
        ret = -1;
    }

    return ret;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char *src_path = argv[1];
    char *dst_path = argv[2];

    int ret = copy_file(src_path, dst_path);
    if (ret == -1) {
        printf("Error copying file\n");
        return 1;
    }

    printf("File copied successfully\n");
    return 0;
}