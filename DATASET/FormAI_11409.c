//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

void *traffic_light_controller(void *arg);

int current_color = GREEN;

int main() {
    pthread_t traffic_light_thread;

    if (pthread_create(&traffic_light_thread, NULL, traffic_light_controller, NULL)) {
        perror("pthread_create() error");
        exit(EXIT_FAILURE);
    }

    while (true) {
        switch (current_color) {
            case GREEN:
                printf("Green Light is ON\n");
                sleep(5);
                current_color = YELLOW;
                break;
            case YELLOW:
                printf("Yellow Light is ON\n");
                sleep(2);
                current_color = RED;
                break;
            case RED:
                printf("Red Light is ON\n");
                sleep(3);
                current_color = GREEN;
                break;
        }
    }

    pthread_join(traffic_light_thread, NULL);
    return 0;
}

void *traffic_light_controller(void *arg) {
    while (true) {
        switch (current_color) {
            case GREEN:
                sleep(15);
                break;
            case YELLOW:
                sleep(3);
                break;
            case RED:
                sleep(10);
                break;
        }
    }
}