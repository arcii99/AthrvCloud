//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Maximum number of floors and elevators
#define MAX_FLOORS 20
#define MAX_ELEVATORS 3

// Struct to represent an elevator
typedef struct {
    int id;
    int current_floor;
    int target_floor;
    int direction; // -1 for down, 0 for stopped, 1 for up
    int passengers;
} Elevator;

// Struct to represent a passenger
typedef struct {
    int id;
    int current_floor;
    int target_floor;
} Passenger;

// Array to represent the floors, each floor has a queue of passengers
// waiting for an elevator going in their direction
Passenger* floors[MAX_FLOORS][2];

// Array to represent the elevators
Elevator elevators[MAX_ELEVATORS];

// Helper function to randomly generate a number between `min` and `max`
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the elevator struct array with default values
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].id = i+1;
        elevators[i].current_floor = 0;
        elevators[i].target_floor = 0;
        elevators[i].direction = 0;
        elevators[i].passengers = 0;
    }

    // Simulation loop
    int time_elapsed = 0;
    while (time_elapsed < 3600) { // simulation runs for 1 hour
        // Generate new passengers
        for (int i = 0; i < MAX_FLOORS; i++) {
            int going_up = random_number(0, 1); // 50% chance of going up
            int going_down = random_number(0, 1); // 50% chance of going down
            if (going_up) {
                int num_passengers = random_number(0, 5); // max 5 passengers per floor
                for (int j = 0; j < num_passengers; j++) {
                    Passenger* p = (Passenger*) malloc(sizeof(Passenger));
                    p->id = random_number(1000, 9999); // random 4-digit ID
                    p->current_floor = i;
                    do {
                        p->target_floor = random_number(i+1, MAX_FLOORS-1); // must go up
                    } while (floors[i][0] != NULL && floors[i][1] != NULL && p->target_floor < floors[i][0]->target_floor && p->target_floor < floors[i][1]->target_floor); // check if there are already waiting passengers going in the same direction and to a higher floor, if so, this passenger must wait
                    floors[i][1] = p; // add passenger to the queue going up
                }
            }
            if (going_down) {
                int num_passengers = random_number(0, 5); // max 5 passengers per floor
                for (int j = 0; j < num_passengers; j++) {
                    Passenger* p = (Passenger*) malloc(sizeof(Passenger));
                    p->id = random_number(1000, 9999); // random 4-digit ID
                    p->current_floor = i;
                    do {
                        p->target_floor = random_number(0, i-1); // must go down
                    } while (floors[i][0] != NULL && floors[i][1] != NULL && p->target_floor > floors[i][0]->target_floor && p->target_floor > floors[i][1]->target_floor); // check if there are already waiting passengers going in the same direction and to a lower floor, if so, this passenger must wait
                    floors[i][0] = p; // add passenger to the queue going down
                }
            }
        }

        // Update elevator positions and states
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            Elevator* e = &elevators[i];
            if (e->direction == 1 && e->current_floor == e->target_floor) { // elevator has reached its target floor
                e->direction = 0;
                e->passengers = 0;
            } else if (e->direction == -1 && e->current_floor == e->target_floor) { // elevator has reached its target floor
                e->direction = 0;
                e->passengers = 0;
            } else if (e->direction == 1) { // elevator is going up
                e->current_floor++;
                // Check if there are any passengers waiting to get off
                for (int j = 0; j < MAX_FLOORS; j++) {
                    if (floors[e->current_floor][1] != NULL && floors[e->current_floor][1]->target_floor == e->current_floor) {
                        // Passenger wants to get off here
                        floors[e->current_floor][1] = NULL;
                        e->passengers--;
                    }
                }
                // Check if there are any passengers waiting to get on
                if (e->passengers < 10) { // max 10 passengers per elevator
                    if (floors[e->current_floor][1] != NULL) {
                        // Passenger wants to go up from here
                        e->target_floor = floors[e->current_floor][1]->target_floor;
                        floors[e->current_floor][1] = NULL;
                        e->direction = 1;
                        e->passengers++;
                    } else if (floors[e->current_floor][0] != NULL && e->target_floor < floors[e->current_floor][0]->target_floor) {
                        // Passenger wants to go down from here, but elevator is going up
                        e->target_floor = floors[e->current_floor][0]->target_floor;
                        floors[e->current_floor][0] = NULL;
                        e->direction = -1;
                        e->passengers++;
                    }
                }
            } else if (e->direction == -1) { // elevator is going down
                e->current_floor--;
                // Check if there are any passengers waiting to get off
                for (int j = 0; j < MAX_FLOORS; j++) {
                    if (floors[e->current_floor][0] != NULL && floors[e->current_floor][0]->target_floor == e->current_floor) {
                        // Passenger wants to get off here
                        floors[e->current_floor][0] = NULL;
                        e->passengers--;
                    }
                }
                // Check if there are any passengers waiting to get on
                if (e->passengers < 10) { // max 10 passengers per elevator
                    if (floors[e->current_floor][0] != NULL) {
                        // Passenger wants to go down from here
                        e->target_floor = floors[e->current_floor][0]->target_floor;
                        floors[e->current_floor][0] = NULL;
                        e->direction = -1;
                        e->passengers++;
                    } else if (floors[e->current_floor][1] != NULL && e->target_floor > floors[e->current_floor][1]->target_floor) {
                        // Passenger wants to go up from here, but elevator is going down
                        e->target_floor = floors[e->current_floor][1]->target_floor;
                        floors[e->current_floor][1] = NULL;
                        e->direction = 1;
                        e->passengers++;
                    }
                }
            } else { // elevator is stopped
                // Check if there are any passengers waiting to get on
                if (floors[e->current_floor][1] != NULL) {
                    // Passenger wants to go up from here
                    e->target_floor = floors[e->current_floor][1]->target_floor;
                    floors[e->current_floor][1] = NULL;
                    e->direction = 1;
                    e->passengers++;
                } else if (floors[e->current_floor][0] != NULL) {
                    // Passenger wants to go down from here
                    e->target_floor = floors[e->current_floor][0]->target_floor;
                    floors[e->current_floor][0] = NULL;
                    e->direction = -1;
                    e->passengers++;
                }
            }
        }

        // Print current status of elevators and floors
        printf("Time elapsed: %d seconds\n", time_elapsed);
        printf("Elevator status:\n");
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            Elevator e = elevators[i];
            printf("Elevator #%d: Floor %d, Direction %s, Passengers %d\n", e.id, e.current_floor, e.direction == 1 ? "Up" : e.direction == -1 ? "Down" : "Stopped", e.passengers);
        }
        printf("Floor status:\n");
        for (int i = 0; i < MAX_FLOORS; i++) {
            printf("Floor %d: ", i);
            if (floors[i][0] != NULL) {
                printf("%d passengers going down, ", floors[i][0]->current_floor != floors[i][0]->target_floor ? 1 : 0);
            } else {
                printf("0 passengers going down, ");
            }
            if (floors[i][1] != NULL) {
                printf("%d passengers going up\n", floors[i][1]->current_floor != floors[i][1]->target_floor ? 1 : 0);
            } else {
                printf("0 passengers going up\n");
            }
        }
        printf("\n");

        // Increment time and sleep for 1 second to simulate real time
        time_elapsed++;
        sleep(1);
    }

    return 0;
}