//FormAI DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 1024

// Function to backup a file
void backup(char* file_path, char* backup_path) {
    int fd1, fd2;
    char buffer[BUFF_SIZE];
    ssize_t bytes_read, bytes_written;

    // Open the original file for reading
    fd1 = open(file_path, O_RDONLY);
    if (fd1 == -1) {
        printf("Error opening the file %s\n", file_path);
        exit(1);
    }

    // Open the backup file for writing, create it if necessary
    fd2 = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd2 == -1) {
        printf("Error opening the file %s\n", backup_path);
        exit(1);
    }

    // Copy the contents of the original file to the backup file
    while ((bytes_read = read(fd1, buffer, BUFF_SIZE)) > 0) {
        bytes_written = write(fd2, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            printf("Error writing to the file %s\n", backup_path);
            exit(1);
        }
    }

    // Close the files
    close(fd1);
    close(fd2);

    printf("File %s backed up to %s\n", file_path, backup_path);
}

// Main function
int main(int argc, char* argv[]) {
    // Make sure the user provided the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <file_path> <backup_path>\n", argv[0]);
        exit(1);
    }

    // Backup the file
    backup(argv[1], argv[2]);

    return 0;
}