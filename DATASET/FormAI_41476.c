//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define FIFO_NAME "/tmp/my_fifo"

int main()
{
    char buf[1024];
    int num, fd;
    pid_t pid;
    struct stat st;

    if(stat(FIFO_NAME, &st) != 0)
    {
        if(mkfifo(FIFO_NAME, 0777) != 0)
        {
            printf("Error: Could not create fifo %s\n", FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }

    if((pid = fork()) == -1)
    {
        printf("Error creating child process\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0)
    {
        printf("Child process executing\n");

        fd = open(FIFO_NAME, O_RDONLY);
        if(fd != -1)
        {
            if((num = read(fd, buf, sizeof(buf))) > 0)
            {
                buf[num] = '\0';
                printf("Message received by child: %s\n", buf);
            }
            else
            {
                printf("Error: Failed to read data from fifo\n");
            }

            close(fd);
        }
        else
        {
            printf("Error: Failed to open fifo for reading\n");
        }

        printf("Child process exiting\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Parent process executing\n");

        fd = open(FIFO_NAME, O_WRONLY);
        if(fd != -1)
        {
            printf("Enter message to send to child: ");
            fgets(buf, sizeof(buf), stdin);
            if(write(fd, buf, strlen(buf)) != -1)
            {
                printf("Message sent by parent: %s\n", buf);
            }
            else
            {
                printf("Error: Failed to write data to fifo\n");
            }

            close(fd);
        }
        else
        {
            printf("Error: Failed to open fifo for writing\n");
        }

        wait(NULL);
        printf("Parent process exiting\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}