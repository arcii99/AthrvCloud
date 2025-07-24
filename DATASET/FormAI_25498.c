//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_PROCESS 100

int main(){
    pid_t processes[MAX_PROCESS];
    int num_processes = 0;

    // Start 10 child processes
    for(int i = 0; i < 10; i++){
        pid_t pid = fork();

        // error check
        if(pid == -1){
            printf("Failed to fork process %d\n", i+1);
            exit(1);
        }
        // child process
        else if(pid == 0){
            printf("Child process %d with PID %d\n", i+1, getpid());
            exit(0);
        }
        // parent process
        else{
            processes[num_processes++] = pid;
        }
    }

    // Wait for child processes to finish and print their status
    for(int i = 0; i < num_processes; i++){
        int status;
        waitpid(processes[i], &status, 0);
        printf("Child process with PID %d exited with status %d\n", processes[i], WEXITSTATUS(status));
    }

    return 0;
}