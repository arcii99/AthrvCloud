//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define NUM_FLOORS 10
#define MAX_PEOPLE 20

// Structs
typedef struct Person {
    int floor;
    int dest_floor;
} Person;

// Globals
Person people[MAX_PEOPLE];
int num_people = 0;
int elevator_floor = 0;
int elevator_dir = 1; // 1 is up, -1 is down

// Get random number within range
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generates people for simulation
void generate_people() {
    int num_new_people = rand_range(0, 4);
    for (int i = 0; i < num_new_people; i++) {
        if (num_people < MAX_PEOPLE) {
            Person new_person;
            new_person.floor = rand_range(0, NUM_FLOORS - 1);
            do {
                new_person.dest_floor = rand_range(0, NUM_FLOORS - 1);
            } while (new_person.dest_floor == new_person.floor);
            people[num_people] = new_person;
            num_people++;
        }
    }
}

// Checks if elevator should change direction
void check_direction_change() {
    if (elevator_floor == 0) {
        elevator_dir = 1;
    } else if (elevator_floor == NUM_FLOORS - 1) {
        elevator_dir = -1;
    }
}

// Move elevator and pick up/drop off people
void move_elevator() {
    elevator_floor += elevator_dir;
    printf("Elevator is now on floor %d\n", elevator_floor);
    for (int i = 0; i < num_people; i++) {
        Person *person = &people[i];
        if (person->dest_floor == elevator_floor) {
            printf("Person from floor %d got off the elevator\n", person->floor);
            *person = people[num_people - 1];
            num_people--;
            i--;
        } else if (person->floor == elevator_floor) {
            printf("Person from floor %d got on the elevator\n", person->floor);
            *person = people[num_people - 1];
            num_people--;
            i--;
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    while (true) {
        generate_people();
        check_direction_change();
        move_elevator();
        printf("Current number of people waiting: %d\n", num_people);
        printf("Press enter to continue...");
        getchar();
    }
    return 0;
}