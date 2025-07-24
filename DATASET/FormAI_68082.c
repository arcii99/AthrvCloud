//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUF 1024

int main()
{
    int fd1, fd2; //file descriptors for the pipes
    char * myfifo1 = "/tmp/myfifo1";
    char * myfifo2 = "/tmp/myfifo2";
    char * msg1 = "Hello from Process 1!";
    char * msg2 = "Hello from Process 2!";
    char buf[MAX_BUF]; //buffer for messages

    //create the named pipes
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);

    //create first child process
    pid_t pid1 = fork();

    if (pid1 == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid1 == 0) //child process 1
    {
        //open pipe for writing
        fd1 = open(myfifo1, O_WRONLY);
        if (fd1 == -1)
        {
            perror("open");
            exit(1);
        }

        //write message to pipe
        write(fd1, msg1, strlen(msg1)+1);

        //close pipe
        close(fd1);

        exit(0);
    }
    else //parent process
    {
        //create second child process
        pid_t pid2 = fork();

        if (pid2 == -1)
        {
            perror("fork");
            exit(1);
        }

        if (pid2 == 0) //child process 2
        {
            //open pipe for writing
            fd2 = open(myfifo2, O_WRONLY);
            if (fd2 == -1)
            {
                perror("open");
                exit(1);
            }

            //write message to pipe
            write(fd2, msg2, strlen(msg2)+1);

            //close pipe
            close(fd2);

            exit(0);
        }
        else //parent process
        {
            //open pipe for reading
            fd1 = open(myfifo1, O_RDONLY);
            fd2 = open(myfifo2, O_RDONLY);

            //read messages from pipes
            read(fd1, buf, MAX_BUF);
            printf("Process 1 received: %s\n", buf);

            read(fd2, buf, MAX_BUF);
            printf("Process 2 received: %s\n", buf);

            //close pipes
            close(fd1);
            close(fd2);

            //remove named pipes
            unlink(myfifo1);
            unlink(myfifo2);

            exit(0);
        }
    }

    return 0;
}