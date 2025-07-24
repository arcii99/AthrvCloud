//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int current_light = GREEN;

void* traffic_control(void* arg) {
    while(1) {
        switch(current_light) {
            case RED:
                printf("Stop! The traffic light is RED.\n");
                sleep(7);
                current_light = GREEN;
                break;
            case YELLOW:
                printf("Get ready! The traffic light is YELLOW.\n");
                sleep(2);
                current_light = RED;
                break;
            case GREEN:
                printf("Go! The traffic light is GREEN.\n");
                sleep(5);
                current_light = YELLOW;
                break;
            default:
                printf("Unknown traffic light color!\n");
                break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    int err = pthread_create(&tid, NULL, &traffic_control, NULL);
    if(err != 0) {
        printf("Error in creating thread: %d\n", err);
        exit(EXIT_FAILURE);
    }
    pthread_join(tid, NULL);
    return 0;
}