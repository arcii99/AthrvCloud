//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_PATH "/var/log/syslog"

int main(int argc, char *argv[]) {
    int file_fd;
    ssize_t bytes_read;
    char buff[1024];
    
    // Open the log file for reading
    file_fd = open(FILE_PATH, O_RDONLY);
    
    if (file_fd == -1) {
        fprintf(stderr, "Failed to open log file %s.\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }
    
    // Move the file pointer to the end of the file
    if (lseek(file_fd, 0, SEEK_END) == -1) {
        fprintf(stderr, "Failed to move file pointer to the end of the file.\n");
        close(file_fd);
        exit(EXIT_FAILURE);
    }
    
    // Continuously read new log entries and output them to stdout
    while (1) {
        // Move the file pointer back 1024 bytes from the end of the file
        if (lseek(file_fd, -1024, SEEK_END) == -1) {
             fprintf(stderr, "Failed to move file pointer 1024 bytes from the end of the file.\n");
             close(file_fd);
             exit(EXIT_FAILURE);
        }
        
        // Read the next 1024 bytes from the file
        bytes_read = read(file_fd, buff, 1024);
        
        if (bytes_read == -1) {
            fprintf(stderr, "Failed to read log entries from file.\n");
            close(file_fd);
            exit(EXIT_FAILURE);
        }
        
        // Output the read bytes to stdout
        if (write(STDOUT_FILENO, buff, bytes_read) != bytes_read) {
            fprintf(stderr, "Failed to output log entries to stdout.\n");
            close(file_fd);
            exit(EXIT_FAILURE);
        }
        
        // Sleep for 5 seconds before reading again
        sleep(5);
    }
    
    // Close the file descriptor
    close(file_fd);
    
    return EXIT_SUCCESS;
}