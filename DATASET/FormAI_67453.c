//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to execute shell commands
void executeCommand(char* cmd) {
    int status;
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        status = system(cmd);
        if (status == -1) {
            printf("Failed to execute command: %s\n", cmd);
            exit(-1);
        }
        exit(0);
    } else if (pid < 0) {
        printf("Failed to fork child process to execute command: %s\n", cmd);
        exit(-1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            printf("Command exited with non-zero status: %d\n", WEXITSTATUS(status));
        }
    }
}

int main() {
    char* cmd1 = "grep -i 'error' /var/log/syslog";
    char* cmd2 = "du -h /home";
    char* cmd3 = "df -h";

    printf("Executing system administration tasks...\n");

    // Execute commands
    executeCommand(cmd1);
    executeCommand(cmd2);
    executeCommand(cmd3);

    printf("System administration tasks executed successfully!\n");

    return 0;
}