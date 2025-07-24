//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// constants
#define LANES 3
#define MAX_SPEED 5
#define CARS 10

//global variables
int lanes[LANES][MAX_SPEED];
int positions[CARS][LANES];
bool running[CARS];

//function prototypes
void init_lanes();
void init_positions();
void print_positions();
void* move_cars(void* car_id);

int main() {
    srand(time(NULL)); //initialize random seed
    init_lanes();
    init_positions();
    print_positions();

    pthread_t threads[CARS];
    for (int i = 0; i < CARS; i++) {
        pthread_create(&threads[i], NULL, move_cars, (void*)i);
    }

    while (1) {
        sleep(1);
        print_positions();
    }

    return 0;
}

// initialize values for all lanes
void init_lanes() {
    for (int i = 0; i < LANES; i++) {
        for (int j = 0; j < MAX_SPEED; j++) {
            lanes[i][j] = rand() % 2;
        }
    }
}

// initialize values for all cars (positions and running status)
void init_positions() {
    for (int i = 0; i < CARS; i++) {
        int lane = rand() % LANES;
        int speed = rand() % MAX_SPEED;
        running[i] = true;
        for (int j = 0; j < LANES; j++) {
            positions[i][j] = (j == lane) ? speed : 0;
        }
    }
}

// print the current positions of all cars
void print_positions() {
    for (int i = 0; i < CARS; i++) {
        for (int j = 0; j < LANES; j++) {
            printf("%d ", positions[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

// simulate the movement of a car
void* move_cars(void* car_id) {
    int id = (int) car_id;
    while (running[id]) {
        int lane = -1;
        int pos = -1;
        // find the current lane and position of the car
        for (int i = 0; i < LANES; i++) {
            for (int j = 0; j < MAX_SPEED; j++) {
                if (positions[id][i] == j) {
                    lane = i;
                    pos = j;
                    break;
                }
            }
            if (pos != -1) break;
        }

        // check for collision
        if (pos > 0 && lanes[lane][pos - 1]) {
            running[id] = false;
            break;
        }

        // move the car forward
        if (pos != 0) positions[id][lane] = pos - 1;

        // check for random slow down
        if (rand() % 10 == 0) {
            if (pos > 0) {
                positions[id][lane] = pos - 1;
            }
        }

        // check for random speed up
        if (rand() % 10 == 0) {
            if (pos < MAX_SPEED - 1) {
                positions[id][lane] = pos + 1;
            }
        }

        // sleep for some time to simulate delay
        usleep(200000); // 200ms
    }
    return NULL;
}