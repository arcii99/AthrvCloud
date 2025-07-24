//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define the number of floors and elevators
#define NUM_OF_FLOORS 5
#define NUM_OF_ELEVATORS 3

// Define the maximum number of passengers in the elevator
#define MAX_PASSENGERS 10

// Define the time it takes to move between floors
#define TIME_TO_TRAVERSE_ONE_FLOOR 1

// Define the total simulation time
#define SIMULATION_TIME 60

// Define enum for elevator direction
typedef enum {
    UP,
    DOWN,
    IDLE
} Direction;

// Define struct for passenger
typedef struct {
    int id;
    int start_floor;
    int end_floor;
} Passenger;

// Define struct for elevator
typedef struct {
    int id;
    int current_floor;
    int num_passengers;
    Direction direction;
    int passenger_list[MAX_PASSENGERS];
} Elevator;

// Define global variables
Passenger waiting_passengers[NUM_OF_FLOORS][NUM_OF_FLOORS];
Elevator elevators[NUM_OF_ELEVATORS];
sem_t passenger_locks[NUM_OF_FLOORS];
sem_t elevator_locks[NUM_OF_ELEVATORS];

// Function to initialize semaphore locks
void init_locks() {
    for (int i = 0; i < NUM_OF_FLOORS; i++) {
        sem_init(&passenger_locks[i], 0, 1);
    }
    for (int i = 0; i < NUM_OF_ELEVATORS; i++) {
        sem_init(&elevator_locks[i], 0, 1);
    }
}

// Function to add a passenger to a floor
void add_passenger_to_floor(Passenger p, int floor) {
    sem_wait(&passenger_locks[floor]);
    waiting_passengers[floor][p.id] = p;
    sem_post(&passenger_locks[floor]);
}

// Function to remove a passenger from a floor
void remove_passenger_from_floor(int id, int floor) {
    sem_wait(&passenger_locks[floor]);
    waiting_passengers[floor][id].id = -1;
    sem_post(&passenger_locks[floor]);
}

// Function to add a passenger to an elevator
void add_passenger_to_elevator(int id, int e) {
    sem_wait(&elevator_locks[e]);
    elevators[e].passenger_list[elevators[e].num_passengers++] = id;
    sem_post(&elevator_locks[e]);
}

// Function to remove a passenger from an elevator
void remove_passenger_from_elevator(int id, int e) {
    sem_wait(&elevator_locks[e]);
    int i, j;
    for (i = 0; i < elevators[e].num_passengers; i++) {
        if (elevators[e].passenger_list[i] == id) {
            for (j = i; j < elevators[e].num_passengers-1; j++) {
                elevators[e].passenger_list[j] = elevators[e].passenger_list[j+1];
            }
            elevators[e].num_passengers--;
            break;
        }
    }
    sem_post(&elevator_locks[e]);
}

// Function to check if an elevator is full
bool is_elevator_full(int e) {
    return elevators[e].num_passengers >= MAX_PASSENGERS;
}

// Function to check if an elevator is empty
bool is_elevator_empty(int e) {
    return elevators[e].num_passengers == 0;
}

// Function to update elevator direction
void update_elevator_direction(int e) {
    int current_floor = elevators[e].current_floor;
    Direction d = IDLE;
    if (elevators[e].direction == UP) {
        for (int i = current_floor+1; i < NUM_OF_FLOORS; i++) {
            if (!is_elevator_empty(e) && waiting_passengers[i][UP].id != -1) {
                d = UP;
                break;
            } else if (!is_elevator_empty(e) && waiting_passengers[i][DOWN].id != -1) {
                d = DOWN;
                break;
            }
        }
        if (d == IDLE) {
            for (int i = current_floor-1; i >= 0; i--) {
                if (!is_elevator_empty(e) && waiting_passengers[i][UP].id != -1) {
                    d = UP;
                    break;
                } else if (!is_elevator_empty(e) && waiting_passengers[i][DOWN].id != -1) {
                    d = DOWN;
                    break;
                }
            }
        }
    } else if (elevators[e].direction == DOWN) {
        for (int i = current_floor-1; i >= 0; i--) {
            if (!is_elevator_empty(e) && waiting_passengers[i][DOWN].id != -1) {
                d = DOWN;
                break;
            } else if (!is_elevator_empty(e) && waiting_passengers[i][UP].id != -1) {
                d = UP;
                break;
            }
        }
        if (d == IDLE) {
            for (int i = current_floor+1; i < NUM_OF_FLOORS; i++) {
                if (!is_elevator_empty(e) && waiting_passengers[i][DOWN].id != -1) {
                    d = DOWN;
                    break;
                } else if (!is_elevator_empty(e) && waiting_passengers[i][UP].id != -1) {
                    d = UP;
                    break;
                }
            }
        }
    } else {
        for (int i = current_floor+1; i < NUM_OF_FLOORS; i++) {
            if (!is_elevator_empty(e) && waiting_passengers[i][UP].id != -1) {
                d = UP;
                break;
            } else if (!is_elevator_empty(e) && waiting_passengers[i][DOWN].id != -1) {
                d = DOWN;
                break;
            }
        }
        if (d == IDLE) {
            for (int i = current_floor-1; i >= 0; i--) {
                if (!is_elevator_empty(e) && waiting_passengers[i][UP].id != -1) {
                    d = UP;
                    break;
                } else if (!is_elevator_empty(e) && waiting_passengers[i][DOWN].id != -1) {
                    d = DOWN;
                    break;
                }
            }
        }
    }
    elevators[e].direction = d;
}

// Function to move elevator
void move_elevator(int e) {
    Direction d = elevators[e].direction;
    int current_floor = elevators[e].current_floor;
    if (d == UP) {
        elevators[e].current_floor++;
        for (int i = 0; i < elevators[e].num_passengers; i++) {
            if (waiting_passengers[current_floor][UP].id == elevators[e].passenger_list[i]) {
                remove_passenger_from_elevator(elevators[e].passenger_list[i], e);
                i--;
            }
        }
    } else if (d == DOWN) {
        elevators[e].current_floor--;
        for (int i = 0; i < elevators[e].num_passengers; i++) {
            if (waiting_passengers[current_floor][DOWN].id == elevators[e].passenger_list[i]) {
                remove_passenger_from_elevator(elevators[e].passenger_list[i], e);
                i--;
            }
        }
    } else {
        return;
    }
    for (int i = 0; i < elevators[e].num_passengers; i++) {
        if (elevators[e].passenger_list[i] == -1) {
            continue;
        }
        if (current_floor == waiting_passengers[current_floor][UP].start_floor && d == UP) {
            add_passenger_to_elevator(waiting_passengers[current_floor][UP].id, e);
            remove_passenger_from_floor(waiting_passengers[current_floor][UP].id, current_floor);
            i--;
        } else if (current_floor == waiting_passengers[current_floor][DOWN].start_floor && d == DOWN) {
            add_passenger_to_elevator(waiting_passengers[current_floor][DOWN].id, e);
            remove_passenger_from_floor(waiting_passengers[current_floor][DOWN].id, current_floor);
            i--;
        }
    }
    update_elevator_direction(e);
}

// Function to print the state of each elevator
void print_elevator_state() {
    printf("\nElevator state:\n");
    for (int i = 0; i < NUM_OF_ELEVATORS; i++) {
        printf("Elevator %d - Floor: %d, Direction: ", elevators[i].id, elevators[i].current_floor);
        if (elevators[i].direction == UP) {
            printf("Up\n");
        } else if (elevators[i].direction == DOWN) {
            printf("Down\n");
        } else {
            printf("Idle\n");
        }
        printf("  Passengers: [ ");
        for (int j = 0; j < elevators[i].num_passengers; j++) {
            printf("%d ", elevators[i].passenger_list[j]);
        }
        printf("]\n");
    }
}

// Function to simulate passenger arrivals
void simulate_passenger_arrivals() {
    Passenger p;
    int r;
    for (int i = 0; i < NUM_OF_FLOORS; i++) {
        for (int j = 0; j < NUM_OF_FLOORS; j++) {
            r = rand() % 10;
            if (r < 2) {
                p.id = j;
                p.start_floor = i;
                p.end_floor = (i + j) % NUM_OF_FLOORS;
                add_passenger_to_floor(p, p.start_floor);
                printf("\nPassenger %d arrived on floor %d and wants to go to floor %d\n",
                    p.id, p.start_floor, p.end_floor);
            }
        }
    }
}

// Function to simulate elevators moving
void *simulate_elevator(void *arg) {
    int e = *(int *) arg;
    while (true) {
        if (is_elevator_empty(e)) {
            sem_wait(&elevator_locks[e]);
            elevators[e].direction = IDLE;
            sem_post(&elevator_locks[e]);
        }
        move_elevator(e);
        print_elevator_state();
        usleep(500000);
    }
}

// Function to simulate the elevator simulation
void simulate() {
    pthread_t elevator_threads[NUM_OF_ELEVATORS];
    int elevator_ids[NUM_OF_ELEVATORS];
    for (int i = 0; i < NUM_OF_ELEVATORS; i++) {
        elevator_ids[i] = i;
        elevators[i].id = i;
        elevators[i].current_floor = 0;
        elevators[i].num_passengers = 0;
        elevators[i].direction = IDLE;
        for (int j = 0; j < MAX_PASSENGERS; j++) {
            elevators[i].passenger_list[j] = -1;
        }
    }
    for (int i = 0; i < NUM_OF_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, simulate_elevator, &elevator_ids[i]);
    }
    for (int i = 0; i < SIMULATION_TIME; i++) {
        simulate_passenger_arrivals();
        usleep(1000000);
    }
    for (int i = 0; i < NUM_OF_ELEVATORS; i++) {
        pthread_cancel(elevator_threads[i]);
    }
}

int main() {
    init_locks();
    simulate();
    return 0;
}