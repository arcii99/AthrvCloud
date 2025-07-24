//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

typedef struct {
    int id;
    int current_floor;
    int target_floor;
    int direction; // -1(down) or 1(up)
    int passengers;
} Elevator;

Elevator elevators[MAX_ELEVATORS];

void setup_elevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].current_floor = 0;
        elevators[i].target_floor = 0;
        elevators[i].direction = 1;
        elevators[i].passengers = 0;
    }
}

void *elevator_thread(void *arg) {
    Elevator *elevator = (Elevator *)arg;
    while (1) {
        if (elevator->current_floor == elevator->target_floor) {
            // elevator has reached target floor
            usleep(500000);
            continue;
        }
        if (elevator->current_floor == 0) {
            elevator->direction = 1;
            elevator->target_floor = rand() % MAX_FLOORS;
        } else if (elevator->current_floor == MAX_FLOORS-1) {
            elevator->direction = -1;
            elevator->target_floor = rand() % MAX_FLOORS;
        } else if (elevator->current_floor == elevator->target_floor) {
            // elevator has reached target floor
            usleep(500000);
            continue;
        } else {
            elevator->target_floor = rand() % MAX_FLOORS;
        }
        printf("Elevator %d: Going from floor %d to floor %d\n", elevator->id, elevator->current_floor, elevator->target_floor);
        if (elevator->target_floor < elevator->current_floor) {
            // moving down
            while (elevator->current_floor > elevator->target_floor) {
                printf("Elevator %d: Currently on floor %d\n", elevator->id, elevator->current_floor);
                elevator->current_floor--;
                usleep(100000);
            }
        } else {
            // moving up
            while (elevator->current_floor < elevator->target_floor) {
                printf("Elevator %d: Currently on floor %d\n", elevator->id, elevator->current_floor);
                elevator->current_floor++;
                usleep(100000);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    setup_elevators();
    pthread_t threads[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_create(&threads[i], NULL, elevator_thread, (void *)&elevators[i]);
    }
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}