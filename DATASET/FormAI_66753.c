//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int sig) {
    printf("Interrupted! Exiting program.\n");
    exit(0);
}

int main() {

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESETHAND;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (!pid) { // Child process
        // Start QoS monitoring
        printf("Starting QoS monitoring...\n");
        unsigned int counter = 0;
        while (1) {
            counter++;
            printf("Counter: %u\n", counter);
            sleep(1);
        }
    } else { // Parent process
        // Wait for child
        int status;
        waitpid(pid, &status, 0);
        printf("Child process exited with status %d\n", status);
    }

    return 0;
}