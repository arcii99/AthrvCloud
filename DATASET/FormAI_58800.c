//FormAI DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 256

int main()
{
    int fd1, fd2;
    char *myfifo1 = "/tmp/myfifo1";
    char *myfifo2 = "/tmp/myfifo2";

    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);

    char str1[BUFFER_SIZE], str2[BUFFER_SIZE];

    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Welcome to Chatbot Program (Process 1)\n");
        fd1 = open(myfifo1, O_RDWR);
        fd2 = open(myfifo2, O_RDWR);

        while (1)
        {
            printf("You: ");
            fgets(str1, BUFFER_SIZE, stdin);
            write(fd1, str1, BUFFER_SIZE);

            read(fd2, str2, BUFFER_SIZE);
            printf("Chatbot: %s", str2);
        }
        close(fd1);
        close(fd2);
    }
    else
    {
        printf("Welcome to Chatbot Program (Process 2)\n");
        fd1 = open(myfifo2, O_RDWR);
        fd2 = open(myfifo1, O_RDWR);

        while (1)
        {
            read(fd1, str1, BUFFER_SIZE);
            printf("Chatbot: %s", str1);

            printf("You: ");
            fgets(str2, BUFFER_SIZE, stdin);
            write(fd2, str2, BUFFER_SIZE);
        }
        close(fd1);
        close(fd2);
    }

    return 0;
}