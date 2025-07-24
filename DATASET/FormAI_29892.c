//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MSG_SIZE 100

int main(){
    int fd1, fd2;
    char msg[MSG_SIZE];

    // create named pipes
    mkfifo("pipe1", 0666);
    mkfifo("pipe2", 0666);

    // fork child process
    pid_t child_pid = fork();

    if (child_pid == 0){
        // child process code
        fd1 = open("pipe1", O_WRONLY);
        fd2 = open("pipe2", O_RDONLY);

        //send message to parent process
        char str[] = "Hello Parent";
        write(fd1, str, strlen(str)+1);

        //wait for response from parent process
        read(fd2, msg, MSG_SIZE);

        printf("Child received message: %s\n", msg);

        //close file descriptors
        close(fd1);
        close(fd2);
                
    }else if (child_pid > 0){
        // parent process code
        fd1 = open("pipe2", O_WRONLY);
        fd2 = open("pipe1", O_RDONLY);

        //wait for message from child process
        read(fd2, msg, MSG_SIZE);

        printf("Parent received message: %s\n", msg);

        //send response message to child process
        char str[] = "Hello Child";
        write(fd1, str, strlen(str)+1);

        //close file descriptors
        close(fd1);
        close(fd2);
    }
    else{
        // error handling for fork failure
        perror("failed to fork child process");
        exit(1);
    }

    // remove named pipes
    unlink("pipe1");
    unlink("pipe2");

    return 0;
}