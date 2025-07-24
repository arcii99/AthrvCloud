//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int count = 0;

void handler(int sig) {
    printf("Task %d started!\n", count + 1);
    sleep(1);
    printf("Task %d completed!\n", count + 1);
    count++;
}

int main() {
    int i;
    // Set up signal handler for SIGALRM
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    // Schedule 5 tasks
    for (i = 0; i < 5; i++) {
        printf("Scheduling task %d\n", i + 1);
        alarm(5); // Schedule alarm to go off in 5 seconds
        pause(); // Wait for signal
    }
    printf("All tasks completed!\n");
    return 0;
}