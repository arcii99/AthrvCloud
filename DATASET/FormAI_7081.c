//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    char command[100];
    pid_t pid;
    int status;
    printf("Welcome to My Unix-like Shell\n");

    while(1) {
        printf(">> ");
        fgets(command, 100, stdin); // take user input
        command[strlen(command) - 1] = '\0'; // remove newline character from the user input

        if(strcmp(command, "exit") == 0) { // exit the shell
            exit(0);
        } else {
            pid = fork(); // create a child process
            if(pid == 0) { // child process
                char *args[] = {"sh", "-c", command, NULL};
                execvp(args[0], args); // execute the command using sh command
                exit(0);
            } else if(pid > 0) { // parent process
                waitpid(pid, &status, 0); // wait for the child process to finish
            } else { // error in creating child process
                printf("Error in creating fork.\n");
            }
        }
    }

    return 0;
}