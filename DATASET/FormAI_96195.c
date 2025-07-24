//FormAI DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 1024

int main()
{
    pid_t pid;
    int fd;
    char buffer[BUFSIZE];
    int status;
    mkfifo("myfifo", S_IRUSR | S_IWUSR | S_IWGRP);
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {

        fd = open("myfifo", O_WRONLY);
        if (fd < 0)
        {
            perror("child: open");
            exit(1);
        }
        printf("Child process with ID %d\n", getpid());

        while (1)
        {
            printf("Enter a message: ");
            fgets(buffer, BUFSIZE, stdin);
            if (strlen(buffer) <= 1)
                continue;
            if (write(fd, buffer, strlen(buffer) + 1) < 0)
            {
                perror("child: write");
                exit(1);
            }
        }
    }
    else
    {
        fd = open("myfifo", O_RDONLY);
        if (fd < 0)
        {
            perror("open");
            exit(1);
        }
        printf("Parent process with ID %d\n", getpid());

        while (1)
        {
            if (read(fd, buffer, BUFSIZE) < 0)
            {
                perror("read");
                exit(1);
            }

            printf("Received: %s", buffer);
            if (strcmp(buffer, "bye\n") == 0)
            {
                kill(pid, SIGKILL);
                exit(0);
            }
        }

        if (waitpid(pid, &status, 0) < 0)
        {
            perror("waitpid");
            exit(1);
        }

        printf("Child exited with status %d\n", WEXITSTATUS(status));
    }

    exit(0);
}