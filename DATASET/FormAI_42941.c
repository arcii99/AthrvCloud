//FormAI DATASET v1.0 Category: System administration ; Style: brave
// Brave System Administration Example Program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    printf("Welcome to the brave system administration example program!\n");
    
    int fd = open("example_file.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        printf("Failed to create file!\n");
        return -1;
    }
    
    printf("File successfully created!\n");
    
    char buffer[20] = "Hello, world!\n";
    ssize_t bytes_written = write(fd, buffer, sizeof(buffer));
    
    if (bytes_written == -1) {
        printf("Failed to write to file!\n");
        return -1;
    }
    
    printf("%ld bytes successfully written to file!\n", bytes_written);
    
    off_t current_offset = lseek(fd, 0, SEEK_CUR);
    
    if (current_offset == -1) {
        printf("Failed to retrieve current offset!\n");
        return -1;
    }
    
    printf("Current offset is: %ld\n", current_offset);
    
    off_t new_offset = lseek(fd, -7, SEEK_END);
    
    if (new_offset == -1) {
        printf("Failed to set new offset!\n");
        return -1;
    }
    
    printf("New offset is: %ld\n", new_offset);
    
    char read_buffer[7];
    ssize_t bytes_read = read(fd, read_buffer, sizeof(read_buffer));
    
    if (bytes_read == -1) {
        printf("Failed to read from file!\n");
        return -1;
    }
    
    printf("%ld bytes successfully read from file!\n", bytes_read);
    printf("Read buffer contains: %s", read_buffer);
    
    int close_status = close(fd);
    
    if (close_status == -1) {
        printf("Failed to close file descriptor!\n");
        return -1;
    }
    
    printf("File descriptor successfully closed!\n");
    
    return 0;
}