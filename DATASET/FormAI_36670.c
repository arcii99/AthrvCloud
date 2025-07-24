//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

    int fd[2];
    int pid;
    char str1[] = "Message from Parent Process to Child Process";
    char str2[] = "Message from Child Process to Parent Process";
    char buffer[100];

    // create pipe
    if (pipe(fd) < 0) {
        fprintf(stderr, "Pipe failed!\n");
        exit(1);
    }

    // create child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    }

    // parent process
    if (pid > 0){
        close(fd[0]);  // close reading end of parent
        printf("Parent: Sending message to child!\n");
        write(fd[1], str1, strlen(str1)+1);
        wait(NULL);     // wait for child process to finish
    }

    // child process
    else {
        close(fd[1]);  // close writing end of child
        printf("Child: Receiving message from parent!\n");
        read(fd[0], buffer, sizeof(buffer)); // read message sent by the parent process
        printf("Child: Message received: %s\n", buffer);
        printf("Child: Sending message to parent!\n");
        write(fd[1], str2, strlen(str2)+1);   // send message to parent process
        exit(0);    // exit child process
    }

    return 0;
}