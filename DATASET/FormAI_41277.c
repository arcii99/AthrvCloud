//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>

#define MAX_SIZE 1024

int main(int argc, char* argv[]){

    int fd[2], nbytes;
    pid_t childpid;

    char parent_buffer[MAX_SIZE], child_buffer[MAX_SIZE];
    char* parent_message = "Hello from parent process!";
    char* child_message = "Hello from child process!";

    if(pipe(fd) == -1){ //Creating Pipe
        perror("Pipe Failed!");
        exit(1);
    }

    if((childpid = fork()) == -1){ //Forking to create child process
        perror("Fork Failed!");
        exit(1);
    }

    if(childpid == 0){ //Child Process
        close(fd[0]); //Close unused read end
        strcpy(child_buffer,child_message); //Copy message to buffer
        nbytes = strlen(child_buffer);
        write(fd[1],child_buffer,nbytes); //Write message to pipe
        exit(0);
    }
    else{ //Parent Process
        close(fd[1]); //Close unused write end
        nbytes = read(fd[0],parent_buffer,MAX_SIZE); //Read message from pipe
        printf("%s\n",parent_buffer);
        exit(0);
    }
    return 0;
}