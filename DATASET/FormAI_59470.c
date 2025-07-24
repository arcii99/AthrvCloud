//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Structs
struct Person {
    int current_floor;
    int desired_floor;
};

struct Elevator {
    int current_floor;
    int num_people;
    int capacity;
    struct Person people[10];
    int direction;
};

// Function prototypes
void initialize_elevators(struct Elevator elevators[]);
void print_building_state(struct Elevator elevators[]);
void choose_direction(struct Elevator *elevator);
void move_elevator(struct Elevator *elevator);
void add_person_to_elevator(struct Elevator *elevator, struct Person person);
void remove_people_from_elevator(struct Elevator *elevator);
void generate_people(struct Elevator elevators[]);

int main() {
    srand(time(NULL));

    struct Elevator elevators[NUM_ELEVATORS];
    initialize_elevators(elevators);

    int current_time = 0;
    while (current_time <= 100) {
        // Generate new people
        generate_people(elevators);

        // Move elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            choose_direction(&elevators[i]);
            move_elevator(&elevators[i]);
        }

        // Remove people from elevators at their desired floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            remove_people_from_elevator(&elevators[i]);
        }

        // Print building state
        printf("Time: %d\n", current_time);
        print_building_state(elevators);

        // Increment time
        current_time++;
    }

    return 0;
}

// Initialize elevators
void initialize_elevators(struct Elevator elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].num_people = 0;
        elevators[i].capacity = 10;
        elevators[i].direction = 0;
    }
}

// Print building state
void print_building_state(struct Elevator elevators[]) {
    for (int i = NUM_FLOORS; i >= 1; i--) {
        printf("Floor %d: [", i);

        // Print people waiting on this floor
        for (int e = 0; e < NUM_ELEVATORS; e++) {
            for (int j = 0; j < elevators[e].num_people; j++) {
                if (elevators[e].people[j].current_floor == i) {
                    printf("* ");
                }
            }
        }

        // Print elevators on this floor
        for (int e = 0; e < NUM_ELEVATORS; e++) {
            if (elevators[e].current_floor == i) {
                printf("E%d ", e);
            }
        }

        printf("]\n");
    }
    printf("\n");
}

// Choose direction for elevator
void choose_direction(struct Elevator *elevator) {
    // If elevator is empty, go to ground floor
    if (elevator->num_people == 0) {
        elevator->direction = -1;
        return;
    }

    // If elevator is full, go to floor of first person added
    if (elevator->num_people == elevator->capacity) {
        elevator->direction = elevator->people[0].current_floor - elevator->current_floor;
        return;
    }

    // Determine shortest distance to next person (up or down)
    int shortest_distance = NUM_FLOORS + 1;
    for (int i = 0; i < elevator->num_people; i++) {
        int distance = abs(elevator->people[i].current_floor - elevator->current_floor);
        if (distance < shortest_distance) {
            shortest_distance = distance;
        }
    }

    // Move elevator in direction of next person
    for (int i = 0; i < elevator->num_people; i++) {
        if (elevator->people[i].current_floor > elevator->current_floor) {
            elevator->direction = 1;
            return;
        }
        if (elevator->people[i].current_floor < elevator->current_floor) {
            elevator->direction = -1;
            return;
        }
    }

    // If no people waiting, go to next floor
    elevator->direction = -1;
}

// Move elevator
void move_elevator(struct Elevator *elevator) {
    elevator->current_floor += elevator->direction;
}

// Add person to elevator
void add_person_to_elevator(struct Elevator *elevator, struct Person person) {
    elevator->people[elevator->num_people] = person;
    elevator->num_people++;
}

// Remove people from elevator at their desired floor
void remove_people_from_elevator(struct Elevator *elevator) {
    for (int i = 0; i < elevator->num_people; i++) {
        if (elevator->people[i].desired_floor == elevator->current_floor) {
            elevator->num_people--;
            elevator->people[i] = elevator->people[elevator->num_people];
            i--;
        }
    }
}

// Generate new people
void generate_people(struct Elevator elevators[]) {
    int num_new_people = rand() % 5;

    for (int i = 0; i < num_new_people; i++) {
        struct Person new_person;
        new_person.current_floor = rand() % NUM_FLOORS + 1;
        do {
            new_person.desired_floor = rand() % NUM_FLOORS + 1;
        } while (new_person.desired_floor == new_person.current_floor);

        int closest_elevator = -1;
        int closest_distance = NUM_FLOORS + 1;
        for (int e = 0; e < NUM_ELEVATORS; e++) {
            if (elevators[e].num_people == elevators[e].capacity) {
                // Elevator is full
                continue;
            }
            if (abs(elevators[e].current_floor - new_person.current_floor) < closest_distance) {
                closest_distance = abs(elevators[e].current_floor - new_person.current_floor);
                closest_elevator = e;
            }
        }

        if (closest_elevator == -1) {
            // No available elevators, person waits on their floor
            add_person_to_elevator(&elevators[new_person.current_floor - 1], new_person);
        } else {
            // Add person to closest elevator
            add_person_to_elevator(&elevators[closest_elevator], new_person);
        }
    }
}