//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10 // define number of floors
#define NUM_ELEVATORS 3 // define number of elevators
#define MAX_CAPACITY 10 // define maximum capacity of each elevator

enum direction {UP, DOWN, IDLE}; // define elevator direction

typedef struct {
    int id;
    int curr_floor;
    int destination;
    int passengers[MAX_CAPACITY];
    int num_passengers;
    enum direction curr_direction;
} Elevator;

Elevator elevators[NUM_ELEVATORS]; // create array of elevators

void initializeElevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i + 1;
        elevators[i].curr_floor = 1;
        elevators[i].destination = 1;
        elevators[i].num_passengers = 0;
        elevators[i].curr_direction = IDLE;
    }
}

void printElevatorsStatus() {
    printf("Elevator Status\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d is at floor %d, heading %s with %d passengers.\n", 
                elevators[i].id, elevators[i].curr_floor,
                elevators[i].curr_direction == UP ? "UP" :
                elevators[i].curr_direction == DOWN ? "DOWN" : "IDLE",
                elevators[i].num_passengers
        );
    }
    printf("\n");
}

void simulateElevatorOperation() {
    int random_floor;
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        switch (elevators[i].curr_direction) {
            case UP:
                elevators[i].curr_floor++;
                if (elevators[i].curr_floor == elevators[i].destination) {
                    elevators[i].curr_direction = IDLE;
                }
                for (int j = 0; j < elevators[i].num_passengers; j++) {
                    if (elevators[i].passengers[j] == elevators[i].curr_floor) {
                        elevators[i].num_passengers--;
                        elevators[i].passengers[j] = elevators[i].passengers[elevators[i].num_passengers];
                        printf("Passenger has arrived at floor %d on Elevator %d. Remaining passengers %d.\n", elevators[i].curr_floor, elevators[i].id, elevators[i].num_passengers);
                    }
                }
                break;
            case DOWN:
                elevators[i].curr_floor--;
                if (elevators[i].curr_floor == elevators[i].destination) {
                    elevators[i].curr_direction = IDLE;
                }
                for (int j = 0; j < elevators[i].num_passengers; j++) {
                    if (elevators[i].passengers[j] == elevators[i].curr_floor) {
                        elevators[i].num_passengers--;
                        elevators[i].passengers[j] = elevators[i].passengers[elevators[i].num_passengers];
                        printf("Passenger has arrived at floor %d on Elevator %d. Remaining passengers %d.\n", elevators[i].curr_floor, elevators[i].id, elevators[i].num_passengers);
                    }
                }
                break;
            case IDLE:
                random_floor = rand() % NUM_FLOORS + 1;
                elevators[i].destination = random_floor;
                elevators[i].curr_direction = random_floor > elevators[i].curr_floor ? UP : DOWN;
                printf("Elevator %d is idle. Destination floor: %d, Direction: %s\n", elevators[i].id, elevators[i].destination, elevators[i].curr_direction == UP ? "UP" : "DOWN");
                break;
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    initializeElevators();
    for (int i = 0; i < 20; i++) {
        printf("Simulation tick: %d\n", i+1);
        simulateElevatorOperation();
        printElevatorsStatus();
    }
    return 0;
}