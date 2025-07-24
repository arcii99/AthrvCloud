//FormAI DATASET v1.0 Category: System administration ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  printf("Welcome to the System Administration Example!\n");
  
  //creating a child process for the system call
  int pid = fork();
  
  //checking if fork was successful
  if(pid == -1){
    printf("Error: Failed to create child process.\n");
    exit(1);
  }else if(pid == 0){
    //executing a system call in the child process
    char* command[] = {"date", NULL};
    execvp(command[0], command);
  }else{
    //parent process waiting for the child to finish
    wait(NULL);
    printf("The time is displayed above!\n");
    printf("Now, let's check the CPU usage.\n");
    
    //executing another system call in the parent process
    char* command2[] = {"top", "-bn1", NULL};
    execvp(command2[0], command2);
  }
  return 0;
}