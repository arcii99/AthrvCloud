//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
/* C Interprocess Communication Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd[2]; // file descriptor
    pid_t pid; //process ID

    // create pipe before forking
    if (pipe(fd) == -1) {
        perror("Pipe Error");
        exit(1);
    }

    pid = fork(); // create a new process
    if (pid < 0) {
        perror("Fork Error");
        exit(1);
    }
    else if (pid == 0) { // child process
        close(fd[0]); // close the unused read side of the pipe

        char message[] = "Hello from the child process!";
        write(fd[1], message, sizeof(message)); //write message to the write end of the pipe
        close(fd[1]); // close the write side of the pipe

        exit(0); // exit the child process
    }
    else { // parent process
        close(fd[1]); // close the unused write side of the pipe

        char message[1024]; // buffer to read message
        read(fd[0], message, 1024); // read message from the read end of the pipe
        printf("Message from child: %s\n", message);

        close(fd[0]); // close the read side of the pipe
        wait(NULL); // wait for the child to finish execution

        exit(0); // exit the parent process
    }

    return 0;
}