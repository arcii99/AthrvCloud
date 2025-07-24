//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int file_desc;
    char buffer[32];
    ssize_t size_read;

    // Create a new file
    file_desc = open("new_file.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_desc == -1) {
        perror("Error creating new file");
        exit(EXIT_FAILURE);
    }

    printf("New file created\n");

    // Write to the file
    write(file_desc, "Hello, world!", 13);
    printf("Data written to file\n");

    // Read from the file
    lseek(file_desc, 0, SEEK_SET);
    size_read = read(file_desc, buffer, sizeof(buffer));
    printf("Read %ld bytes from file: %.*s\n", size_read, (int)size_read, buffer);

    // Close the file
    close(file_desc);
    printf("File descriptor closed\n");

    return 0;
}