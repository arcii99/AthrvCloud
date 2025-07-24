//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_CARS 10
#define GREEN_TIME 5
#define RED_TIME 2

bool stop_traffic = false;

void* traffic_light(void* arg) {
    int timer = GREEN_TIME;
    while(!stop_traffic) {
        printf("Green light: %ds\n", timer);
        sleep(1);
        timer--;
        if(timer < 1) {
            timer = RED_TIME;
            printf("Red light: %ds\n", timer);
            sleep(1);
        }
    }
    pthread_exit(NULL);
}

void* car(void* arg) {
    int car_id = *(int*) arg;
    printf("Car %d created.\n", car_id);
    while(!stop_traffic) {
        sleep(1);
    }
    printf("Car %d destroyed.\n", car_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t traffic_thread, car_threads[NUM_CARS];
    int car_ids[NUM_CARS];

    printf("Traffic simulation starting.\n");

    pthread_create(&traffic_thread, NULL, traffic_light, NULL);

    for(int i = 0; i < NUM_CARS; i++) {
        car_ids[i] = i;
        pthread_create(&car_threads[i], NULL, car, &car_ids[i]);
    }

    sleep(20);

    stop_traffic = true;

    pthread_join(traffic_thread, NULL);
    for(int i = 0; i < NUM_CARS; i++) {
        pthread_join(car_threads[i], NULL);
    }

    printf("Traffic simulation ended.\n");

    return 0;
}