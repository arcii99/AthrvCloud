//FormAI DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(){

    printf("Welcome to the System Administration Example Program!\n\n");

    // Forking a child process to run the command
    pid_t pid = fork();

    if(pid == 0){
        // Child process
        printf("Running system command: 'df -h'\n\n");
        system("df -h");
        exit(0);
    }else if(pid > 0){
        // Parent process
        printf("Waiting for child process to complete...\n\n");

        // Installing a signal handler to catch any Ctrl+C or Interrupt signals
        struct sigaction new_action, old_action;
        new_action.sa_handler = SIG_IGN;
        sigemptyset(&new_action.sa_mask);
        new_action.sa_flags = 0;
        sigaction(SIGINT, NULL, &old_action);
        if(old_action.sa_handler != SIG_IGN){
            printf("Press Ctrl+C or send an Interrupt signal to exit.\n\n");
            sigaction(SIGINT, &new_action, NULL);
        }

        // Waiting for the child process to complete
        int status;
        wait(&status);

        if(WIFEXITED(status)){
            printf("\nChild process completed with status %d\n", WEXITSTATUS(status));
        }
    }else{
        // Error forking
        perror("Error forking process.");
        exit(1);
    }

    return 0;
}