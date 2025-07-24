//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE 1024 // Maximum line length for commands

int main(int argc, char *argv[]) {
    char buf[MAXLINE]; // Buffer for storing user input
    pid_t pid; // Process ID variable
    int status; // Exit status of processes

    while(1) {
        printf("Enter a command (start/stop/restart/status/exit):\n");
        if(fgets(buf, MAXLINE, stdin) == NULL) {
            printf("Error reading user input: %s\n", strerror(errno));
            exit(1);
        }

        // Remove newline character from user input
        buf[strlen(buf) - 1] = '\0';

        // Check user input and execute appropriate command
        if(strncmp(buf, "start", 5) == 0) {
            printf("Starting process...\n");
            if((pid = fork()) < 0) { // Fork process
                printf("Error forking process: %s\n", strerror(errno));
                exit(1);
            } else if(pid == 0) { // Child process
                if(execl("/bin/process", "process", (char *)0) < 0) { // Execute process
                    printf("Error executing process: %s\n", strerror(errno));
                    exit(1);
                }
            }
        } else if(strncmp(buf, "stop", 4) == 0) {
            printf("Stopping process...\n");
            if(kill(pid, SIGTERM) < 0) { // Stop process
                printf("Error stopping process: %s\n", strerror(errno));
                exit(1);
            }
        } else if(strncmp(buf, "restart", 7) == 0) {
            printf("Restarting process...\n");
            if(kill(pid, SIGHUP) < 0) { // Restart process
                printf("Error restarting process: %s\n", strerror(errno));
                exit(1);
            }
        } else if(strncmp(buf, "status", 6) == 0) {
            printf("Checking process status...\n");
            if(waitpid(pid, &status, WNOHANG) == 0) { // Check process status
                printf("Process is running.\n");
            } else {
                printf("Process is not running.\n");
            }
        } else if(strncmp(buf, "exit", 4) == 0) {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}