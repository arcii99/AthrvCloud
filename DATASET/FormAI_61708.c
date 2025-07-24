//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 5

time_t t;

// Elevator states
enum {
    STATIONARY,
    ASCENDING,
    DESCENDING
};

// Elevator struct
typedef struct {
    int id;
    int floor;
    int state;
} Elevator;

// Function to generate a random floor
int generate_floor() {
    srand(time(NULL));
    return rand() % MAX_FLOORS + 1;
}

// Function to print the elevator status
void print_status(Elevator *elevator) {
    printf("Elevator %d is currently at floor %d and is %s\n", elevator->id, elevator->floor, elevator->state == STATIONARY ? "stationary" : elevator->state == ASCENDING ? "ascending" : "descending");
}

// Function to simulate elevator movement
void simulate_elevator(Elevator *elevator) {
    if(elevator->state == STATIONARY) {
        int destination = generate_floor();
        printf("Elevator %d is now moving from floor %d to floor %d\n", elevator->id, elevator->floor, destination);
        if(destination > elevator->floor) {
            elevator->state = ASCENDING;
        } else {
            elevator->state = DESCENDING;
        }
    } else if(elevator->state == ASCENDING) {
        elevator->floor++;
        printf("Elevator %d is now at floor %d\n", elevator->id, elevator->floor);
        if(elevator->floor == MAX_FLOORS) {
            printf("Elevator %d has reached the top floor and is now descending\n", elevator->id);
            elevator->state = DESCENDING;
        }
    } else if(elevator->state == DESCENDING) {
        elevator->floor--;
        printf("Elevator %d is now at floor %d\n", elevator->id, elevator->floor);
        if(elevator->floor == 1) {
            printf("Elevator %d has reached the bottom floor and is now ascending\n", elevator->id);
            elevator->state = ASCENDING;
        }
    }
}

int main() {
    Elevator elevators[MAX_ELEVATORS];

    for(int i=0; i < MAX_ELEVATORS; i++) {
        elevators[i].id = i+1;
        elevators[i].floor = 1;
        elevators[i].state = STATIONARY;
    }

    // Simulate elevator movement for 10 iterations
    for(int i=0; i < 10; i++) {
        printf("Iteration %d:\n", i+1);
        for(int j=0; j < MAX_ELEVATORS; j++) {
            print_status(&elevators[j]);
            simulate_elevator(&elevators[j]);
            printf("\n");
        }
    }

    printf("Simulation complete!\n");

    return 0;
}