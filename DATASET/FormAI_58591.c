//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
//This program demonstrates interprocess communication using pipes in C programming language. 
//It creates two child process which communicates with each other through a pipe. 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() 
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) < 0) //create pipe
        exit(1);

    pid = fork(); //create first child process

    if (pid < 0) //fork failed 
        exit(2);

    else if (pid > 0) //parent process
    {
        char message[30] = "Hello from parent process";
        char buffer[30];

        close(fd[0]); //close reading end of pipe

        write(fd[1], message, sizeof(message)); //write message to pipe

        close(fd[1]); //close writing end of pipe

        pid = fork(); //create second child process

        if (pid < 0) //fork failed 
            exit(2);

        else if (pid > 0) //parent process
        {
            wait(NULL); //wait for child process to finish

            close(fd[1]); //close writing end of pipe

            read(fd[0], buffer, sizeof(buffer)); //read message from pipe

            printf("Parent received message: %s\n", buffer); //print received message

            close(fd[0]); //close reading end of pipe
        }

        else //second child process
        {
            char message[30] = "Hello from second child process";
            char buffer[30];

            close(fd[1]); //close writing end of pipe

            read(fd[0], buffer, sizeof(buffer)); //read message from pipe

            printf("Second child received message: %s\n", buffer); //print received message

            write(fd[1], message, sizeof(message)); //write message to pipe

            close(fd[0]); //close reading end of pipe

            close(fd[1]); //close writing end of pipe
        }
    }

    else //first child process
    {
        char message[30] = "Hello from first child process";
        char buffer[30];

        close(fd[1]); //close writing end of pipe

        read(fd[0], buffer, sizeof(buffer)); //read message from pipe

        printf("First child received message: %s\n", buffer); //print received message

        write(fd[1], message, sizeof(message)); //write message to pipe

        close(fd[0]); //close reading end of pipe

        close(fd[1]); //close writing end of pipe
    }

    return 0;
}