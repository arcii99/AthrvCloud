//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[50];

    // Opening a file
    fd = open("example.txt", O_WRONLY | O_CREAT, 0666);

    if (fd < 0) {
        printf("Could not open file.\n");
        exit(1);
    }

    printf("File opened successfully.\n");

    // Writing data to the file
    write(fd, "Hello, world!", 13);

    // Closing the file
    close(fd);

    printf("File closed successfully.\n");

    return 0;
}