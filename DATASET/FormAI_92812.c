//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 20

// Struct for representing a person waiting for an elevator
typedef struct {
    int floor; // the floor the person is waiting on
    bool going_up; // whether the person wants to go up or down
} Person;

// Struct for representing an elevator
typedef struct {
    int current_floor; // the floor the elevator is currently on
    bool going_up; // whether the elevator is currently going up or down
    int capacity; // the maximum number of people the elevator can hold
    int num_people; // the number of people currently in the elevator
    Person people[MAX_PEOPLE]; // array to store the people currently in the elevator
} Elevator;

// Function to simulate a person arriving and waiting for an elevator
Person wait_for_elevator(void) {
    Person p;
    p.floor = rand() % MAX_FLOORS + 1; // choose a random floor for the person to wait on
    p.going_up = rand() % 2; // randomly decide whether the person wants to go up or down
    printf("Person on floor %d wants to go %s\n", p.floor, p.going_up ? "up" : "down");
    return p;
}

// Function to simulate the elevator moving between floors
void move_elevator(Elevator *e) {
    // If the elevator is going up and it's not on the top floor, move up one floor
    if (e->going_up && e->current_floor < MAX_FLOORS) {
        e->current_floor++;
    }
    // If the elevator is going down and it's not on the bottom floor, move down one floor
    else if (!e->going_up && e->current_floor > 1) {
        e->current_floor--;
    }
    // Otherwise, change direction
    else {
        e->going_up = !e->going_up;
    }
    
    // Check if any people in the elevator want to get off at this floor
    int i;
    for (i = 0; i < e->num_people; i++) {
        if (e->people[i].floor == e->current_floor) {
            printf("Person on floor %d got off the elevator\n", e->current_floor);
            e->num_people--;
            e->people[i] = e->people[e->num_people];
        }
    }
    
    // Check if there are any people waiting on this floor who want to get on
    for (i = 0; i < e->num_people; i++) {
        if (e->people[i].floor == e->current_floor && e->num_people < e->capacity) {
            printf("Person on floor %d got on the elevator\n", e->current_floor);
            e->num_people++;
        }
    }
}

int main(void) {
    srand(time(NULL)); // seed the random number generator with the current time
    Elevator e = {1, true, MAX_PEOPLE, 0, {0}}; // initialize the elevator to start on the first floor, going up, and empty
    
    // Loop to simulate people arriving and waiting for the elevator
    int num_people_waiting = 0;
    while (true) {
        if (num_people_waiting < MAX_PEOPLE && rand() % 3 == 0) {
            e.people[e.num_people++] = wait_for_elevator();
            num_people_waiting++;
        }
        
        // Move the elevator every second
        move_elevator(&e);
        printf("Elevator on floor %d going %s with %d people\n", e.current_floor, e.going_up ? "up" : "down", e.num_people);
        sleep(1);
    }
    
    return 0;
}