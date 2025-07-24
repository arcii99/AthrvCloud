//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 20
#define ELEVATOR_CAPACITY 10

int current_floor = 0;
int current_passengers = 0;
int destinations[MAX_FLOORS] = { 0 }; // Array to keep track of where passengers need to go
int passengers[MAX_PASSENGERS] = { 0 }; // Array to keep track of each passenger's destination
int num_passengers = 0;

void print_status() {
    printf("Current floor: %d\n", current_floor);
    printf("Number of passengers: %d\n", current_passengers);
    printf("Destinations:");
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf(" %d", destinations[i]);
    }
    printf("\n");
}

void add_passenger() {
    if (num_passengers >= MAX_PASSENGERS) {
        printf("Elevator is at maximum capacity.\n");
        return;
    }
    int destination;
    do {
        destination = rand() % MAX_FLOORS;
    } while (destination == current_floor);
    passengers[num_passengers] = destination;
    destinations[destination]++;
    num_passengers++;
}

void remove_passenger(int destination) {
    destinations[destination]--;
    current_passengers--;
    num_passengers--;
}

void move_elevator() {
    if (current_floor == MAX_FLOORS - 1) { // At top floor, start descending
        for (int i = MAX_FLOORS - 1; i >= 0; i--) {
            if (destinations[i] > 0) {
                current_floor = i;
                printf("Elevator is going down to floor %d\n", current_floor);
                break;
            }
        }
    } else if (current_floor == 0) { // At bottom floor, start ascending
        for (int i = 1; i < MAX_FLOORS; i++) {
            if (destinations[i] > 0) {
                current_floor = i;
                printf("Elevator is going up to floor %d\n", current_floor);
                break;
            }
        }
    } else { // Between floors, go to next destination
        if (destinations[current_floor] > 0) {
            printf("Elevator has arrived at floor %d. Unloading passengers.\n", current_floor);
            int i = 0;
            while (i < num_passengers) {
                if (passengers[i] == current_floor) {
                    remove_passenger(current_floor);
                    printf("Passenger has left the elevator.\n");
                } else {
                    i++;
                }
            }
        }
        if (num_passengers < ELEVATOR_CAPACITY && destinations[current_floor] > 0) {
            printf("Elevator is loading passengers.\n");
            int i = 0;
            while (i < MAX_PASSENGERS && num_passengers < ELEVATOR_CAPACITY) {
                if (passengers[i] == current_floor) {
                    remove_passenger(current_floor);
                } else if (passengers[i] == -1) {
                    passengers[i] = current_floor;
                    destinations[current_floor]++;
                    current_passengers++;
                    printf("Passenger has boarded the elevator.\n");
                }
                i++;
            }
        }
        if (current_floor == MAX_FLOORS - 1) { // At top floor, start descending
            for (int i = MAX_FLOORS - 1; i >= 0; i--) {
                if (destinations[i] > 0) {
                    current_floor = i;
                    printf("Elevator is going down to floor %d\n", current_floor);
                    break;
                }
            }
        } else if (current_floor == 0) { // At bottom floor, start ascending
            for (int i = 1; i < MAX_FLOORS; i++) {
                if (destinations[i] > 0) {
                    current_floor = i;
                    printf("Elevator is going up to floor %d\n", current_floor);
                    break;
                }
            }
        } else if (destinations[current_floor + 1] > 0) { // Next destination above
            current_floor++;
            printf("Elevator is going up to floor %d\n", current_floor);
        } else if (destinations[current_floor - 1] > 0) { // Next destination below
            current_floor--;
            printf("Elevator is going down to floor %d\n", current_floor);
        } else { // No more destinations in this direction
            printf("Elevator is idle at floor %d\n", current_floor);
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i] = -1; // -1 represents an empty slot in the passengers array
    }

    printf("Elevator simulation started.\n");
    while (1) {
        add_passenger();
        move_elevator();
        print_status();
    }

    return 0;
}