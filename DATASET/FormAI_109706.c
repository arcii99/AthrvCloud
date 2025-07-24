//FormAI DATASET v1.0 Category: System administration ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int status;
    pid_t pid;

    pid=fork();     //create child process

    if(pid<0){      //if fork fails
        printf("Fork Failed\n");
        exit(1);    //exit with failure status
    }
    else if(pid==0){    //child process
        printf("Child Process ID is %d\n", getpid());
        printf("Parent Process ID is %d\n", getppid());

        char *args[]={"ls","-l",NULL};
        execvp(args[0],args);

        printf("Error Occured in execvp\n");
        exit(1);
    }
    else{   //parent process
        printf("Parent Process ID is %d\n", getpid());
        printf("Child Process ID is %d\n", pid);

        wait(&status);  //wait for child process to complete

        if(WIFEXITED(status))
            printf("Child Process Terminated with Status %d\n", WEXITSTATUS(status));
        else
            printf("Child Process Terminated Abnormally\n");
    }

    return 0;
}