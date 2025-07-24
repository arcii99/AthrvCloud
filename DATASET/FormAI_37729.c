//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants for elevator simulation */
#define NUM_FLOORS 6
#define ELEVATOR_CAPACITY 10
#define MAX_PEOPLE 20
#define MAX_WAIT_TIME 20

/* Struct for person */
typedef struct person {
    int current_floor;
    int destination_floor;
} Person;

/* Function declarations */
void move_elevator(int*, int*, int*, int*);

int main() {
    srand(time(NULL)); // Seed random number generator
    int current_floor = 1; // Starting floor of elevator
    int elevator_load = 0; // Number of people on elevator
    int num_people = 0; // Total number of people in simulation 
    int waiting[NUM_FLOORS] = {0}; // Number of people waiting on each floor
    
    while (num_people < MAX_PEOPLE) {
        int wait_time = rand() % MAX_WAIT_TIME + 1; // Random wait time for person
        usleep(wait_time * 1000); // Wait for person to arrive
        int direction; // Direction person is going
        if (current_floor == 1) {
            direction = 1; // Person going up
        } else if (current_floor == NUM_FLOORS) {
            direction = -1; // Person going down
        } else {
            direction = (rand() % 2 == 0) ? 1 : -1; // Random direction
        }
        Person new_person = {current_floor, current_floor + direction}; // Create new person
        printf("New person added at floor %d going %s\n", new_person.current_floor, (direction == 1) ? "up" : "down");
        waiting[current_floor - 1]++; // Increment waiting count on current floor
        num_people++; // Increment total number of people
        while (elevator_load < ELEVATOR_CAPACITY && waiting[current_floor - 1] > 0) {
            elevator_load++; // Add person to elevator
            waiting[current_floor - 1]--; // Remove person from waiting count 
            printf("Person picked up at floor %d\n", current_floor);
        }
        move_elevator(&current_floor, &elevator_load, &num_people, waiting); // Move elevator to next floor
        if (elevator_load > 0 && new_person.destination_floor == current_floor) {
            elevator_load--; // Remove person from elevator
            printf("Person dropped off at floor %d\n", current_floor);
        }
    }
    printf("Simulation complete!\n");
    return 0;
}

/* Function to move elevator to next floor */
void move_elevator(int* current_floor, int* elevator_load, int* num_people, int* waiting) {
    if (*elevator_load == 0 && *waiting == 0) { // Stop if no one waiting or on elevator
        return;
    }
    if (*current_floor == NUM_FLOORS) { // If at top floor, go down
        *current_floor -= 1;
    } else if (*current_floor == 1) { // If at bottom floor, go up
        *current_floor += 1;
    } else {
        int direction = (rand() % 2 == 0) ? 1 : -1; // Random direction
        *current_floor += direction;
    }
    printf("Elevator at floor %d\n", *current_floor);
}