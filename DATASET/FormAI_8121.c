//FormAI DATASET v1.0 Category: Funny ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256

static volatile int running = 1;

/**
 * Signal handler to stop the program when a SIGINT is received 
 */
void sig_handler(int signo) {
    if(signo == SIGINT) {
        printf("\nReceived SIGINT. Stopping...\n");
        running = 0;
    }
}

/**
 * A function that writes a random number to a file and sleeps for a random amount of time
 */
void async_function(char* filename) {
    srand(time(NULL));
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    char buffer[BUFFER_SIZE];

    while(running) {
        int rand_num = rand() % 100;
        sprintf(buffer, "%d\n", rand_num);

        // Write the random number to the file
        if(write(fd, buffer, strlen(buffer)) < 0) {
            perror("Error writing to file");
            close(fd);
            exit(1);
        }

        // Sleep for a random amount of time
        int rand_sleep = (rand() % 5) + 1;
        sleep(rand_sleep);
    }

    close(fd);
}

/**
 * Main function that creates two child processes and runs an asynchronous task 
 */
int main() {
    pid_t child1_pid, child2_pid;

    // Register SIGINT signal handler
    if(signal(SIGINT, sig_handler) == SIG_ERR) {
        perror("Signal handler failed");
    }

    // Create the first child process
    if((child1_pid = fork()) == 0) {
        async_function("child1.txt");
        exit(0);
    } else if(child1_pid < 0) {
        perror("Error creating first child process");
        exit(1);
    }

    // Create the second child process
    if((child2_pid = fork()) == 0) {
        async_function("child2.txt");
        exit(0);
    } else if(child2_pid < 0) {
        perror("Error creating second child process");
        exit(1);
    }

    // Wait for the child processes to finish
    int status;
    waitpid(child1_pid, &status, 0);
    waitpid(child2_pid, &status, 0);

    printf("Done!\n");

    return 0;
}