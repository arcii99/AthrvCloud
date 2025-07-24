//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_ROADS 4
#define MAX_CARS 20
#define MAX_SPEED 5

typedef struct car {
    int car_id;
    int speed;
    int lane;
} Car;

int traffic_flow[NUM_ROADS][MAX_CARS];
int can_move[NUM_ROADS][MAX_CARS];
pthread_mutex_t mutex;

void* car_action(void* arg) {
    Car* car_ptr = (Car*) arg;
    int car_id = car_ptr->car_id;
    int speed = car_ptr->speed;
    int lane = car_ptr->lane;
    int position = 0;

    while (1) {
        pthread_mutex_lock(&mutex);

        if (position == 0) {
            traffic_flow[lane][position] = car_id;
            can_move[lane][position] = 1;
        } else if (position < MAX_CARS-1 && can_move[lane][position-1]) {
            traffic_flow[lane][position] = car_id;
            can_move[lane][position] = 1;
            can_move[lane][position-1] = 0;
        } else {
            can_move[lane][position] = 0;
        }

        pthread_mutex_unlock(&mutex);

        if (can_move[lane][position]) {
            position++;

            // Random delay to simulate traffic
            int delay_time = rand() % 1000 * (MAX_SPEED - speed + 1) + 1000;
            usleep(delay_time);

            pthread_mutex_lock(&mutex);

            if (position < MAX_CARS) {
                traffic_flow[lane][position-1] = -1;
            }

            pthread_mutex_unlock(&mutex);
        }

        if (position == MAX_CARS) {
            break;
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t car_threads[MAX_CARS];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_ROADS; i++) {
        for (int j = 0; j < MAX_CARS; j++) {
            traffic_flow[i][j] = -1;
            can_move[i][j] = 0;
        }
    }

    for (int car_id = 0; car_id < MAX_CARS; car_id++) {
        Car* car_ptr = (Car*) malloc(sizeof(Car));
        car_ptr->car_id = car_id;
        car_ptr->speed = rand() % MAX_SPEED + 1;
        car_ptr->lane = rand() % NUM_ROADS;
        pthread_create(&car_threads[car_id], NULL, car_action, (void*) car_ptr);
    }

    for (int i = 0; i < MAX_CARS; i++) {
        pthread_join(car_threads[i], NULL);
    }

    for (int i = 0; i < MAX_CARS; i++) {
        free((Car*) car_threads[i]);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}