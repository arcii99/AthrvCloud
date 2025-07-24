//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void print_file_contents(char *filename) {
    int fd;
    char buffer[1024];

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    ssize_t bytes_read;
    do {
        bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            printf("Error reading from file %s\n", filename);
            exit(1);
        }

        ssize_t bytes_written;
        bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written == -1) {
            printf("Error writing to stdout\n");
            exit(1);
        }
    } while (bytes_read > 0);

    close(fd);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        printf("Error getting file size for %s\n", filename);
        exit(1);
    }

    printf("File size: %lld bytes\n", (long long) statbuf.st_size);

    mode_t old_mode = statbuf.st_mode;
    mode_t new_mode = old_mode | S_IRUSR;  // Add read permission for owner

    if (chmod(filename, new_mode) == -1) {
        printf("Error setting permission for %s\n", filename);
        exit(1);
    }

    printf("Read permission for owner added to %s\n", filename);

    printf("File contents:\n");
    print_file_contents(filename);

    if (chmod(filename, old_mode) == -1) {
        printf("Error restoring old permission for %s\n", filename);
        exit(1);
    }

    printf("Old permission restored for %s\n", filename);

    return 0;
}