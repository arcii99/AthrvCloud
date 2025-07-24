//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int fd;

    printf("Welcome to the System Administration Program!\n");

    pid = fork(); // creating a child process
    if (pid < 0) {
        printf("Error: Could not fork.\n");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        printf("Parent process is running...\n");
        printf("Waiting for the child process to complete...\n\n");

        wait(NULL); // waiting for the child process to complete
        printf("Child process has completed.\n");

        printf("\nExiting the program.\n");
        exit(EXIT_SUCCESS);
    } 

    printf("Child process is running...\n");
    printf("Creating log file...\n");

    fd = open("system_logs.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR); // creating a log file
    if (fd < 0) {
        printf("Error: Could not create log file.\n");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDOUT_FILENO); // redirecting stdout to the log file
    dup2(fd, STDERR_FILENO); // redirecting stderr to the log file

    printf("Log file created successfully.\n");

    printf("\nPerforming system maintenance tasks...\n");
    system("sudo apt-get update"); // updating system packages using apt-get
    printf("System packages have been updated.\n");

    printf("\nPerforming disk cleanup...\n");
    system("sudo apt-get autoclean"); // removing unnecessary packages and dependencies
    printf("Disk cleanup has been completed.\n");

    printf("\nPerforming system restart...\n");
    system("sudo reboot"); // restarting the system
    printf("System has been restarted.\n");

    printf("\nExiting the child process.\n");

    close(fd); // closing the log file
    exit(EXIT_SUCCESS);
}