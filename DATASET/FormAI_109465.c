//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid;
    char system_command[100];
    printf("Enter the system command to execute (e.g. ls, ps, whoami): ");
    fgets(system_command, sizeof(system_command), stdin);
    //remove newline character from command
    system_command[strlen(system_command)-1] = '\0';
    pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork process\n");
        exit(1);
    } else if (pid == 0) {
        printf("Child process executing system command: %s\n", system_command);
        //place the child process in a new process group
        setpgid(0, 0);
        //execute the system command in the child process
        execlp(system_command, system_command, NULL);
        //if the above command fails, perror will execute
        perror(system_command);
        exit(1);
    } else {
        //parent process waits for child process to terminate
        waitpid(pid, NULL, 0);
        printf("Child process has terminated\n");
        //parent process reclaims control of the terminal
        tcsetpgrp(STDIN_FILENO, getpgrp());
        printf("Terminal control returned to parent process\n");
    }
    return 0;
}