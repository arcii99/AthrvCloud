//FormAI DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Define the maximum path length and buffer size
#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 4096

// Function to copy a file from a source path to a destination path
int copy_file(char *source, char *dest) {
    int source_fd, dest_fd, read_count, write_count;
    char buffer[BUFFER_SIZE];

    // Open the source file in read-only mode
    source_fd = open(source, O_RDONLY);
    if (source_fd == -1) {
        perror("Failed to open source file");
        return -1;
    }

    // Open or create the destination file in write-only mode
    dest_fd = open(dest, O_CREAT | O_WRONLY, 0644);
    if (dest_fd == -1) {
        perror("Failed to open destination file");
        close(source_fd);
        return -1;
    }

    // Copy data from the source file to the destination file
    while ((read_count = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write_count = write(dest_fd, buffer, read_count);
        if (write_count != read_count) {
            perror("Failed to write to destination file");
            close(source_fd);
            close(dest_fd);
            return -1;
        }
    }

    // Close the files and return success
    close(source_fd);
    close(dest_fd);
    return 0;
}

// Function to create a backup of a file
int backup_file(char *filename) {
    char source_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];

    // Construct the source and destination paths
    snprintf(source_path, MAX_PATH_LENGTH, "%s", filename);
    snprintf(dest_path, MAX_PATH_LENGTH, "%s.bak", filename);

    // Copy the original file to the backup file
    if (copy_file(source_path, dest_path) == -1) {
        return -1;
    }

    // Return success
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Backup the specified file
    if (backup_file(argv[1]) == -1) {
        printf("Failed to backup file %s\n", argv[1]);
        return -1;
    }

    printf("File backed up successfully\n");
    return 0;
}