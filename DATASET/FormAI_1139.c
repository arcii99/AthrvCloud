//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLOORS 10
#define MAX_PEOPLE 10

typedef struct {
    int floor;
    bool want_to_go_up;
} Person;

typedef struct {
    Person people[MAX_PEOPLE];
    int num_people;
    int current_floor;
    bool going_up;
} Elevator;

void print_state(Elevator elevator) {
    printf("Current floor: %d\n", elevator.current_floor);
    printf("Going %s\n", elevator.going_up ? "up" : "down");
    printf("People in elevator: ");
    for (int i = 0; i < elevator.num_people; i++) {
        printf("Floor %d (%s), ", elevator.people[i].floor, elevator.people[i].want_to_go_up ? "up" : "down");
    }
    printf("\n\n");
}

int main() {
    Elevator elevator = { .num_people = 0, .current_floor = 1, .going_up = true };
    Person floor_people[FLOORS][MAX_PEOPLE];
    int num_floor_people[FLOORS] = {0};

    // Generate some people on each floor
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < MAX_PEOPLE; j++) {
            if (rand() % 2 == 0) {
                floor_people[i][j] = (Person){ .floor = i + 1, .want_to_go_up = true };
                num_floor_people[i]++;
            } else {
                floor_people[i][j] = (Person){ .floor = i + 1, .want_to_go_up = false };
                num_floor_people[i]++;
            }
        }
    }

    // Begin simulation
    while (true) {
        print_state(elevator);

        // Check if we're at the top or bottom floor
        if (elevator.current_floor == 1) {
            elevator.going_up = true;
        } else if (elevator.current_floor == FLOORS) {
            elevator.going_up = false;
        }

        // Let people off if they need to leave
        for (int i = 0; i < elevator.num_people; i++) {
            if (elevator.people[i].floor == elevator.current_floor) {
                printf("Person leaves elevator on floor %d\n", elevator.current_floor);
                elevator.num_people--;
                for (int j = i; j < elevator.num_people; j++) {
                    elevator.people[j] = elevator.people[j+1];
                }
                i--;
            }
        }

        // Check if we need to pick anyone up
        for (int i = 0; i < num_floor_people[elevator.current_floor-1]; i++) {
            Person potential_passenger = floor_people[elevator.current_floor-1][i];
            if (elevator.num_people < MAX_PEOPLE && potential_passenger.want_to_go_up == elevator.going_up) {
                printf("Person enters elevator on floor %d\n", elevator.current_floor);
                elevator.people[elevator.num_people++] = potential_passenger;
                // Remove person from floor list
                num_floor_people[elevator.current_floor-1]--;
                for (int j = i; j < num_floor_people[elevator.current_floor-1]; j++) {
                    floor_people[elevator.current_floor-1][j] = floor_people[elevator.current_floor-1][j+1];
                }
                i--;
            }
        }

        // Move elevator one floor in the direction we're going
        elevator.current_floor += elevator.going_up ? 1 : -1;
    }

    return 0;
}