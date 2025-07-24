//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    char buffer[MAX_BUF];
    int fd;
    ssize_t num_read;

    // Create the log file if it doesn't exist
    if( access( "/var/log/system_admin_example.log", F_OK ) == -1 ) {
        fd = open("/var/log/system_admin_example.log", O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            perror("Error creating log file");
            exit(EXIT_FAILURE);
        }
        write(fd, "System administration example log file created\n", 47);
        close(fd);
    }

    // Open the log file
    fd = open("/var/log/system_admin_example.log", O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    // Write message to log file
    snprintf(buffer, MAX_BUF, "System administration example program started with %d arguments\n", argc);
    write(fd, buffer, strlen(buffer));

    // Check if user has root privileges
    if (getuid() != 0) {
        snprintf(buffer, MAX_BUF, "User %s attempted to run program without root privileges\n", getlogin());
        write(fd, buffer, strlen(buffer));
        printf("This program must be run with root privileges\n");
        exit(EXIT_FAILURE);
    }

    // Check if correct number of arguments
    if (argc != 2) {
        snprintf(buffer, MAX_BUF, "User %s did not provide correct number of arguments\n", getlogin());
        write(fd, buffer, strlen(buffer));
        printf("Usage: ./system_admin_example file_path\n");
        exit(EXIT_FAILURE);
    }

    // Check if file exists
    if (access(argv[1], F_OK) == -1) {
        snprintf(buffer, MAX_BUF, "User %s attempted to access a file that does not exist\n", getlogin());
        write(fd, buffer, strlen(buffer));
        printf("Error: File does not exist\n");
        exit(EXIT_FAILURE);
    }

    // Check if user has write permissions for file
    if (access(argv[1], W_OK) == -1) {
        snprintf(buffer, MAX_BUF, "User %s attempted to modify a file without write permissions\n", getlogin());
        write(fd, buffer, strlen(buffer));
        printf("Error: User does not have write permissions for file\n");
        exit(EXIT_FAILURE);
    }

    // Modify the file
    snprintf(buffer, MAX_BUF, "User %s modified file: %s\n", getlogin(), argv[1]);
    write(fd, buffer, strlen(buffer));
    FILE *file = fopen(argv[1], "a"); // Append mode
    fprintf(file, "\nModified by system_admin_example\n");
    fclose(file);

    // Write message to log file
    write(fd, "System administration example program completed successfully\n", 64);

    // Close the log file
    close(fd);

    return 0;
}