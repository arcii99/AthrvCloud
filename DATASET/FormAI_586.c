//FormAI DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

// Global variables
volatile int x = 0;
volatile int y = 0;
volatile bool stopFlag = false;

void* moveRobot(void* arg) {
    int delta_x = *((int*) arg);
    while(!stopFlag) {
        x += delta_x;
        y++;
        sleep(1);
    }
    return NULL;
}

void handleInterrupt(int sig) {
    printf("\nInterrupt received, stopping robot...\n");
    stopFlag = true;
    return;
}

int main() {
    // Set up interrupt handler
    signal(SIGINT, handleInterrupt);

    // Spawn thread to move robot right
    int dx = 1;
    pthread_t rightThread;
    pthread_create(&rightThread, NULL, moveRobot, (void*) &dx);

    // Move robot left in main thread
    int dy = -1;
    while(!stopFlag) {
        x--;
        y += dy;
        sleep(1);
        if(y == 0) dy = 1;
        else if(y == 10) dy = -1;
    }

    // Join threads and exit
    pthread_join(rightThread, NULL);
    printf("Final position: (%d, %d)\n", x, y);
    return 0;
}