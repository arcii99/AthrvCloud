//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: statistical
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

/* Structs */
typedef struct Elevator {
    int current_floor;
    bool going_up;
    bool door_open;
} Elevator;

/* Global Variables */
Elevator elevators[NUM_ELEVATORS];

/* Prototypes */
void move_elevator(int elevator_index, int destination_floor);
void print_elevator_status(int elevator_index);

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Initialize all elevators on the ground floor with doors closed */
    for (int i=0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].going_up = true;
        elevators[i].door_open = false;
    }

    /* Loop forever */
    while (true) {
        /* Pick a random floor for someone to request an elevator */
        int requested_floor = rand() % NUM_FLOORS;

        /* Find the nearest elevator to the requested floor */
        int best_elevator_index = 0;
        int closest_distance = NUM_FLOORS + 1;
        for (int i=0; i < NUM_ELEVATORS; i++) {
            int distance = abs(elevators[i].current_floor - requested_floor);
            if (distance < closest_distance) {
                best_elevator_index = i;
                closest_distance = distance;
            }
        }

        /* Move the elevator to the requested floor */
        move_elevator(best_elevator_index, requested_floor);

        /* Simulate someone getting on and requesting a destination floor */
        int current_floor = elevators[best_elevator_index].current_floor;
        int destination_floor = rand() % (NUM_FLOORS - 1);  // Can't go to top floor from top floor
        if (destination_floor >= current_floor) {
            elevators[best_elevator_index].going_up = true;
        } else {
            elevators[best_elevator_index].going_up = false;
        }
        move_elevator(best_elevator_index, destination_floor);

        /* Simulate someone getting off */
        elevators[best_elevator_index].door_open = true;
        sleep(1);
        elevators[best_elevator_index].door_open = false;

        /* Print out the status of all elevators */
        for (int i=0; i < NUM_ELEVATORS; i++) {
            print_elevator_status(i);
        }

        /* Sleep for 3 seconds so we can see the output */
        sleep(3);
    }

    return 0;
}

void move_elevator(int elevator_index, int destination_floor) {
    /* Open the doors first if they're closed */
    if (!elevators[elevator_index].door_open) {
        elevators[elevator_index].door_open = true;
        sleep(1);
    }

    /* Move the elevator */
    while (elevators[elevator_index].current_floor != destination_floor) {
        /* Print out the status of this elevator before each move */
        if (!elevators[elevator_index].door_open) {
            print_elevator_status(elevator_index);
        }

        /* Move the elevator up or down */
        if (elevators[elevator_index].going_up) {
            elevators[elevator_index].current_floor++;
        } else {
            elevators[elevator_index].current_floor--;
        }

        /* Pause a bit between floors */
        sleep(1);
    }

    /* Close the doors */
    elevators[elevator_index].door_open = false;
    sleep(1);
}

void print_elevator_status(int elevator_index) {
    printf("Elevator %d: ", elevator_index);
    if (elevators[elevator_index].door_open) {
        printf("DOORS OPEN  ");
    } else {
        printf("DOORS CLOSED");
    }
    printf("   ");
    for (int i=0; i < NUM_FLOORS; i++) {
        if (i == elevators[elevator_index].current_floor) {
            printf("| X ");
        } else {
            printf("|   ");
        }
    }
    printf("|\n");
}