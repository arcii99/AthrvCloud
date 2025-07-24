//FormAI DATASET v1.0 Category: Interprocess communication ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUF 1024

int main()
{
    int fifo_fd;
    char buf[MAX_BUF];
    char *fifo_file = "/tmp/fifo_file";

    // Create the fifo
    mkfifo(fifo_file, 0666);

    // Open the fifo for reading
    fifo_fd = open(fifo_file, O_RDONLY);
    if (fifo_fd == -1)
    {
        perror("Error opening fifo for reading");
        exit(EXIT_FAILURE);
    }

    // Read from the fifo
    printf("Waiting for message...\n");
    while (1)
    {
        if (read(fifo_fd, buf, MAX_BUF) > 0)
        {
            printf("Message Received: %s\n", buf);
            break;
        }
    }

    // Close the fifo
    close(fifo_fd);

    // Open the fifo for writing
    fifo_fd = open(fifo_file, O_WRONLY);
    if (fifo_fd == -1)
    {
        perror("Error opening fifo for writing");
        exit(EXIT_FAILURE);
    }

    // Write to the fifo
    strcpy(buf, "Thanks for the message!");
    if (write(fifo_fd, buf, strlen(buf)) == -1)
    {
        perror("Error writing to fifo");
        exit(EXIT_FAILURE);
    }

    // Close the fifo and remove the file
    close(fifo_fd);
    unlink(fifo_file);

    return 0;
}