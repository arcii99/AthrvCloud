//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> 

#define FLOOR_COUNT 10
#define ELEVATOR_CAPACITY 10

pthread_t elevator_thread;

pthread_mutex_t mutex, elevator_mutex;

int elevator_floor, elevator_direction, current_passengers, floors[FLOOR_COUNT], up_stop[FLOOR_COUNT], down_stop[FLOOR_COUNT];

void* elevator(void* ptr) {
    while(1) {
        pthread_mutex_lock(&mutex);

        int i;

        // Elevator direction check
        if (elevator_direction == 0) {
            for (i = elevator_floor + 1; i < FLOOR_COUNT; i++) {
                if (up_stop[i] == 1 || down_stop[i] == 1) {
                    elevator_direction = 1;
                    break;
                }
            }

            if (elevator_direction == 0) {
                for (i = elevator_floor - 1; i >= 0; i--) {
                    if (up_stop[i] == 1 || down_stop[i] == 1) {
                        elevator_direction = -1;
                        break;
                    }
                }
            }
        }

        int next_floor = elevator_floor + elevator_direction;

        // Floor reached check
        if (floors[next_floor]) {
            floors[next_floor] = 0;
            elevator_floor = next_floor;
            printf("Elevator reached floor %d.\n", elevator_floor);

            // Passenger pickup
            if (elevator_direction == 1) {
                if (up_stop[elevator_floor]) {
                    current_passengers++;
                    up_stop[elevator_floor] = 0;
                    printf("Elevator picked up passenger going up at floor %d.\n", elevator_floor);

                    if (current_passengers == ELEVATOR_CAPACITY) {
                        printf("Elevator is at full capacity.\n");
                        elevator_direction = 0;
                    }
                }

                if (down_stop[elevator_floor]) {
                    current_passengers++;
                    down_stop[elevator_floor] = 0;
                    printf("Elevator picked up passenger going down at floor %d.\n", elevator_floor);

                    if (current_passengers == ELEVATOR_CAPACITY) {
                        printf("Elevator is at full capacity.\n");
                        elevator_direction = 0;
                    }
                }
            } else if (elevator_direction == -1) {
                if (down_stop[elevator_floor]) {
                    current_passengers++;
                    down_stop[elevator_floor] = 0;
                    printf("Elevator picked up passenger going down at floor %d.\n", elevator_floor);

                    if (current_passengers == ELEVATOR_CAPACITY) {
                        printf("Elevator is at full capacity.\n");
                        elevator_direction = 0;
                    }
                }

                if (up_stop[elevator_floor]) {
                    current_passengers++;
                    up_stop[elevator_floor] = 0;
                    printf("Elevator picked up passenger going up at floor %d.\n", elevator_floor);

                    if (current_passengers == ELEVATOR_CAPACITY) {
                        printf("Elevator is at full capacity.\n");
                        elevator_direction = 0;
                    }
                }
            }

            // Stopping if no more floors to go
            if (elevator_direction == 0) {
                printf("Elevator stopped at floor %d.\n", elevator_floor);
                current_passengers = 0;

                for (i = 0; i < FLOOR_COUNT; i++) {
                    if (up_stop[i] == 1 || down_stop[i] == 1) {
                        elevator_direction = i > elevator_floor ? 1 : -1;
                        break;
                    }
                }

                if (elevator_direction == 0) {
                    printf("Elevator is idle.\n");
                }
            }

            pthread_mutex_unlock(&mutex);
            pthread_mutex_unlock(&elevator_mutex);
        } else {
            pthread_mutex_unlock(&mutex);
            usleep(1000);
        }
    }
}

// Function to add floor stops to elevator
void add_stop(int floor, int direction) {
    if(direction == 1) {
        up_stop[floor] = 1;
    } else {
        down_stop[floor] = 1;
    }

    floors[floor] = 1;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&elevator_mutex, NULL);

    int i;

    // Generating floor requests
    srand(time(NULL));

    for (i = 0; i < FLOOR_COUNT; i++) {
        int direction = rand() % 2;

        if (direction == 1) {
            printf("Floor %d has requested elevator to go up.\n", i);
        } else {
            printf("Floor %d has requested elevator to go down.\n", i);
        }

        add_stop(i, direction);
    }

    printf("\n");

    // Elevator simulation
    elevator_floor = 0;
    elevator_direction = 1;
    printf("Elevator started moving up.\n\n");

    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&elevator_mutex);

    pthread_create(&elevator_thread, NULL, elevator, NULL);

    while(1) {
        pthread_mutex_lock(&mutex);

        if (elevator_direction == 1) {
            printf("Passenger on floor %d is going up.\n", elevator_floor);
            add_stop(rand() % FLOOR_COUNT, elevator_direction);

            if (current_passengers == ELEVATOR_CAPACITY) {
                printf("Elevator is at full capacity.\n");
                elevator_direction = 0;
            }
        } else if (elevator_direction == -1) {
            printf("Passenger on floor %d is going down.\n", elevator_floor);
            add_stop(rand() % FLOOR_COUNT, elevator_direction);

            if (current_passengers == ELEVATOR_CAPACITY) {
                printf("Elevator is at full capacity.\n");
                elevator_direction = 0;
            }
        }

        if (elevator_direction == 0) {
            printf("All requested passengers have boarded the elevator.\n");
            pthread_mutex_unlock(&elevator_mutex);
            pthread_mutex_unlock(&mutex);
            break;
        }

        pthread_mutex_unlock(&mutex);
        usleep(rand() % 1000000);
    }

    pthread_join(elevator_thread, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&elevator_mutex);

    return 0;
}