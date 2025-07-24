//FormAI DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    //Declare variables
    int status;
    pid_t pid1,pid2,pid3;
    
    //Create process 1
    pid1 = fork();
    
    if(pid1 == 0){ //Code executed by child 1
        
        printf("Child 1: Starting process...\n");
        system("ls -l"); //Example command
        printf("Child 1: Process finished.\n");
        
        exit(0); //Terminate child process
    }
    else if(pid1 == -1){ //Error occurred
        
        perror("Error creating child 1");
        exit(1);
    }
    
    //Create process 2
    pid2 = fork();
    
    if(pid2 == 0){ //Code executed by child 2
        
        printf("Child 2: Starting process...\n");
        system("df -h"); //Example command
        printf("Child 2: Process finished.\n");
        
        exit(0); //Terminate child process
    }
    else if(pid2 == -1){ //Error occurred
        
        perror("Error creating child 2");
        exit(1);
    }
    
    //Create process 3
    pid3 = fork();
    
    if(pid3 == 0){ //Code executed by child 3
        
        printf("Child 3: Starting process...\n");
        system("ps aux"); //Example command
        printf("Child 3: Process finished.\n");
        
        exit(0); //Terminate child process
    }
    else if(pid3 == -1){ //Error occurred
        
        perror("Error creating child 3");
        exit(1);
    }
    
    //Main process waits for all child processes to finish
    wait(&status);
    wait(&status);
    wait(&status);
    
    printf("\nAll processes finished.\n");
    
    return 0;
}