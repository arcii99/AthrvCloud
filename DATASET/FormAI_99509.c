//FormAI DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define MSGSIZE 50 // maximum size of the message

/*
The parent and child processes communicate through a pipe. 
The parent reads data from keyboard and sends it to the child 
process which then prints it to the console.
*/

void parentHandler(int signum) {
    printf("Parent: signal %d received\n", signum);
    exit(signum);
}

void childHandler(int signum) {
    printf("Child: signal %d received\n", signum);
    exit(signum);
}

int main() {

    signal(SIGINT, parentHandler); // parent process handles SIGINT signal
    signal(SIGTERM, childHandler); // child process handles SIGTERM signal

    int fd[2]; // file descriptors for pipe

    if(pipe(fd) < 0) { // creating pipe
        printf("Error: Pipe creation failed");
        return -1;
    }

    pid_t pid = fork(); // creating child process

    if(pid < 0) { // error handling for forking process
        printf("Error: Forking failed");
        return -1;
    }

    if(pid > 0) { // parent process

        close(fd[0]); // close reading end, using fd[1] to write 
        char message[MSGSIZE];
        printf("Enter a message: ");
        fgets(message, MSGSIZE, stdin);
        write(fd[1], message, strlen(message)+1); // write message to pipe
        close(fd[1]); // close write end of pipe
    }

    else { // child process

        close(fd[1]); // close writing end, using fd[0] to read
        char message[MSGSIZE];
        read(fd[0], message, MSGSIZE); // read from pipe
        printf("Child: Message received: %s\n", message);
        close(fd[0]); // close reading end of pipe
    }

    return 0;
}