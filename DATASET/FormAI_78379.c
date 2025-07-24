//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile int* drone_running;
volatile int* drone_battery;
pthread_mutex_t drone_status_mutex;

void* remote_control(void* arg) {
    while (*drone_running) {
        pthread_mutex_lock(&drone_status_mutex);
        printf("Drone battery remaining: %d%%\n", *drone_battery);
        pthread_mutex_unlock(&drone_status_mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    drone_running = (int*)malloc(sizeof(int));
    drone_battery = (int*)malloc(sizeof(int));
    
    *drone_running = 1;
    *drone_battery = 100;

    pthread_mutex_init(&drone_status_mutex, NULL);
    pthread_t thread;
    pthread_create(&thread, NULL, remote_control, NULL);

    while (*drone_running && *drone_battery > 0) {
        // TODO: Implement remote control functionality here
        // e.g. move drone, change camera angle, arm/disarm motors, etc.
        pthread_mutex_lock(&drone_status_mutex);
        *drone_battery -= 1;
        pthread_mutex_unlock(&drone_status_mutex);
        sleep(1);
    }

    *drone_running = 0;
    pthread_join(thread, NULL);
    pthread_mutex_destroy(&drone_status_mutex);
    free((void*)drone_running);
    free((void*)drone_battery);
    return 0;
}