//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

pthread_mutex_t lock;

int direction = 0; // 0: stop, 1: forward, 2: backward, 3: left, 4: right

void *engineThread(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        switch (direction) {
            case 1:
                printf("Moving Forward...\n");
                break;
            case 2:
                printf("Moving Backward...\n");
                break;
            case 3:
                printf("Turning Left...\n");
                break;
            case 4:
                printf("Turning Right...\n");
                break;
            default:
                printf("Stopped.\n");
        }

        pthread_mutex_unlock(&lock);
        usleep(100000); // wait for 100ms
    }
}

void *remoteControlThread(void *arg) {
    srand(time(NULL)); // seed random number generator

    while (1) {
        pthread_mutex_lock(&lock);

        int randomDirection = rand() % 5;
        direction = randomDirection;

        pthread_mutex_unlock(&lock);
        usleep(500000); // wait for 500ms
    }
}

int main() {
    pthread_t engineID;
    pthread_t remoteControlID;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&engineID, NULL, engineThread, NULL);
    pthread_create(&remoteControlID, NULL, remoteControlThread, NULL);

    pthread_join(engineID, NULL);
    pthread_join(remoteControlID, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}