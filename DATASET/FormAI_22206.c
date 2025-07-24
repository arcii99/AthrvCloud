//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        exit(1);
    }

    char *src_path = argv[1];
    char *dest_path = argv[2];
    char buffer[BUFFER_SIZE];

    int src_fd = open(src_path, O_RDONLY);

    if (src_fd == -1) {
        perror("open source file");
        exit(1);
    }

    struct stat stat_buf;
    if (stat(src_path, &stat_buf) < 0) {
        perror("stat source file");
        exit(1);
    }
    mode_t mode = stat_buf.st_mode;

    int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, mode);

    if (dest_fd == -1) {
        perror("open destination file");
        exit(1);
    }

    size_t nread;
    while ((nread = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, nread) != nread) {
            perror("write destination file");
            exit(1);
        }
    }

    if (nread == -1) {
        perror("read source file");
        exit(1);
    }

    if (close(src_fd) == -1) {
        perror("close source file");
        exit(1);
    }

    if (close(dest_fd) == -1) {
        perror("close destination file");
        exit(1);
    }

    printf("Backup %s to %s successfully.\n", src_path, dest_path);

    return 0;
}