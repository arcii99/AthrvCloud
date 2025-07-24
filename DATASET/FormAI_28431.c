//FormAI DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

    // Create a new file
    int file = open("example.txt", O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    if(file < 0) {
        printf("Error creating file!\n");
        exit(1);
    }

    printf("Created file 'example.txt' successfully!\n");

    // Write some data to the file
    const char *data = "Hello, world!";
    int bytes_written = write(file, data, strlen(data));
    if(bytes_written < 0) {
        printf("Error writing to file!\n");
        close(file);
        exit(1);
    }

    printf("Wrote %d bytes to 'example.txt'\n", bytes_written);

    // Close the file
    close(file);

    printf("Closed 'example.txt' successfully!\n");

    // Set some file permissions
    if(chmod("example.txt", S_IRWXU|S_IRGRP|S_IROTH) < 0) {
        printf("Error setting file permissions!\n");
        exit(1);
    }

    printf("Changed permissions on 'example.txt' successfully!\n");

    // Rename the file
    if(rename("example.txt", "new_example.txt") < 0) {
        printf("Error renaming file!\n");
        exit(1);
    }

    printf("Renamed 'example.txt' to 'new_example.txt' successfully!\n");

    // Delete the file
    if(remove("new_example.txt") < 0) {
        printf("Error deleting file!\n");
        exit(1);
    }

    printf("Deleted 'new_example.txt' successfully!\n");

    return 0;
}