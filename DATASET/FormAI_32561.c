//FormAI DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, error_check;
    char buffer[1024];

    // Open a file using open() syscall
    fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write to the file using write() syscall
    error_check = write(fd, "Hello World!\n", 13);

    if (error_check == -1) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    // Close the file using close() syscall
    error_check = close(fd);

    if (error_check == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("File written successfully!\n");

    // Change the file permissions using chmod() syscall
    error_check = chmod("example.txt", S_IRWXU);

    if (error_check == -1) {
        perror("Error changing file permissions");
        exit(EXIT_FAILURE);
    } else {
        printf("File permissions changed successfully!\n");
    }

    // Change the owner of the file using chown() syscall
    error_check = chown("example.txt", 1000, 1000); // Assuming user id 1000 is the new owner

    if (error_check == -1) {
        perror("Error changing file owner");
        exit(EXIT_FAILURE);
    } else {
        printf("File owner changed successfully!\n");
    }

    // Read from the file using read() syscall
    fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    error_check = read(fd, buffer, 1024);

    if (error_check == -1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }

    printf("Data read from file: %s", buffer);

    // Close the file using close() syscall
    error_check = close(fd);

    if (error_check == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return 0;
}