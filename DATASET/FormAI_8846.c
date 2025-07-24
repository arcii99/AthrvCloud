//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_DIRECTION 360
#define MIN_DIRECTION 0
#define UPDATE_INTERVAL_MS 1000

int speed = 0;
int direction = 0;

void* updateSpeed(void* arg) {
    while(1) {
        usleep(UPDATE_INTERVAL_MS * 1000);
        int r = rand() % 100;
        if(r < 50) {
            if(speed < MAX_SPEED) {
                speed++;
            }
        } else {
            if(speed > MIN_SPEED) {
                speed--;
            }
        }
    }
}

void* updateDirection(void* arg) {
    while(1) {
        usleep(UPDATE_INTERVAL_MS * 1000);
        int r = rand() % 100;
        if(r < 25) {
            if(direction < MAX_DIRECTION) {
                direction += 10;
            }
        } else if(r < 50) {
            if(direction > MIN_DIRECTION) {
                direction -= 10;
            }
        }
    }
}

int main() {
    pthread_t speedThread, directionThread;

    pthread_create(&speedThread, NULL, updateSpeed, NULL);
    pthread_create(&directionThread, NULL, updateDirection, NULL);

    while(1) {
        printf("Current Speed: %d, Current Direction: %d\n", speed, direction);
        usleep(500 * 1000);
    }

    return 0;
}