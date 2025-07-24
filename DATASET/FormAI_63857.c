//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 4096

void backupFile(char* source, char* destination);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get source and destination file paths
    char* source = argv[1];
    char* destination = argv[2];

    // Backup the file
    backupFile(source, destination);

    printf("File backed up successfully!\n");

    return EXIT_SUCCESS;
}

void backupFile(char* source, char* destination) {
    // Open source file for reading
    int sourceFd = open(source, O_RDONLY);
    if (sourceFd == -1) {
        perror("open() error");
        exit(EXIT_FAILURE);
    }

    // Create destination file for writing
    int destinationFd = open(destination, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (destinationFd == -1) {
        perror("open() error");
        exit(EXIT_FAILURE);
    }

    // Copy source file to destination file
    char buf[BUFSIZE];
    ssize_t numRead;
    while ((numRead = read(sourceFd, buf, BUFSIZE)) > 0) {
        if (write(destinationFd, buf, numRead) != numRead) {
            perror("write() error");
            exit(EXIT_FAILURE);
        }
    }

    // Close files
    if (close(sourceFd) == -1) {
        perror("close() error");
    }
    if (close(destinationFd) == -1) {
        perror("close() error");
    }
}