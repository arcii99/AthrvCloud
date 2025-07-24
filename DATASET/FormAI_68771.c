//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

#define INTERVAL 5

int state = RED;

pthread_mutex_t mutex;

// Function to change state of the traffic light
void change_state() {
    switch(state) {
        case RED:
            state = GREEN;
            break;
        case GREEN:
            state = YELLOW;
            break;
        case YELLOW:
            state = RED;
            break;
    }
}

// Function to print the current state of the traffic light
void print_state() {
    switch(state) {
        case RED:
            printf("RED\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        case YELLOW:
            printf("YELLOW\n");
            break;
    }
}

// Thread function to change the state of the traffic light every INTERVAL seconds
void *controller_thread(void *args) {
    while(1) {
        pthread_mutex_lock(&mutex);
        change_state();
        print_state();
        pthread_mutex_unlock(&mutex);
        sleep(INTERVAL);
    }
}

// Thread function to simulate traffic passing through the intersection
void *vehicle_thread(void *args) {
    int id = *(int *) args;
    while(1) {
        pthread_mutex_lock(&mutex);
        printf("Vehicle %d passing through %d signal\n", id, state);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 10 + 1);
    }
}

int main() {
    pthread_t controller;
    pthread_t vehicles[5];
    int ids[] = {1, 2, 3, 4, 5};
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_create(&controller, NULL, controller_thread, NULL);
    
    for(int i = 0; i < 5; i++) {
        pthread_create(&vehicles[i], NULL, vehicle_thread, &ids[i]);
    }
    
    pthread_join(controller, NULL);
    for(int i = 0; i < 5; i++) {
        pthread_join(vehicles[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}