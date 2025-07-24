//FormAI DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Hello! Welcome to our cheerful interprocess communication program!\n");

    int fd;
    char *fifo = "/tmp/fifo";

    /* create the FIFO (named pipe) */
    if (mkfifo(fifo, 0666) == -1)
    {
        printf("Error: Failed to create FIFO. Please try again later.\n");
        exit(1);
    }

    /* create a child process */
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Error: Failed to create child process. Please try again later.\n");
        exit(1);
    }
    else if (pid == 0) /* child process */
    {
        fd = open(fifo, O_WRONLY);
        if (fd == -1)
        {
            printf("Error: Failed to open FIFO. Please try again later.\n");
            exit(1);
        }

        /* write to the FIFO */
        char *message = "Hello from the child process!";
        write(fd, message, sizeof(message));
        close(fd);
        exit(0);
    }
    else /* parent process */
    {
        fd = open(fifo, O_RDONLY);
        if (fd == -1)
        {
            printf("Error: Failed to open FIFO. Please try again later.\n");
            exit(1);
        }

        /* read from the FIFO */
        char message[100];
        read(fd, message, sizeof(message));
        printf("Message received from child process: %s\n", message);
        close(fd);

        /* remove the FIFO */
        if (unlink(fifo) == -1)
        {
            printf("Error: Failed to remove FIFO. Please try again later.\n");
            exit(1);
        }

        printf("Thank you for using our cheerful interprocess communication program!\n");
        return 0;
    }
}