//FormAI DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    int fd, out_fd;
    char *filename, *out_filename;
    struct stat s;
    unsigned char block[BLOCK_SIZE];
    ssize_t n;
    int i;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image-file> <output-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    out_filename = argv[2];

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror(filename);
        exit(EXIT_FAILURE);
    }

    out_fd = open(out_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (out_fd < 0) {
        perror(out_filename);
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &s) < 0) {
        perror(filename);
        close(fd);
        close(out_fd);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < s.st_size / BLOCK_SIZE; i++) {
        n = read(fd, block, BLOCK_SIZE);
        if (n != BLOCK_SIZE) {
            fprintf(stderr, "Error reading block %d\n", i);
            close(fd);
            close(out_fd);
            exit(EXIT_FAILURE);
        }

        if (block[0] == 0xe5 && block[1] == 0x5) {
            printf("Found deleted file: ");
            for (int j = 2; j < 11 && block[j]; j++) {
                printf("%c", block[j]);
            }
            printf("\n");

            if (write(out_fd, block + 32, BLOCK_SIZE - 32) != BLOCK_SIZE - 32) {
                perror(out_filename);
                close(fd);
                close(out_fd);
                exit(EXIT_FAILURE);
            }
        }
    }

    close(fd);
    close(out_fd);

    return 0;
}