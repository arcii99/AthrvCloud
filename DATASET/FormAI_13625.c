//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: genious
// Elevator Simulation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

typedef struct {
    int floor;
    int destination;
} person_t;

typedef struct {
    int number;
    int floor;
    person_t people[MAX_PEOPLE];
} floor_t;

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down
    floor_t floors[MAX_FLOORS];
} elevator_t;

void initialize_elevator(elevator_t* elevator);
void initialize_people(person_t* people, int number);
void randomize_floor(person_t* person);
void run_simulation(elevator_t* elevator);
void move_elevator(elevator_t* elevator);
void add_people_to_elevator(elevator_t* elevator, floor_t* floor);
void remove_people_from_elevator(elevator_t* elevator);
void print_elevator_status(elevator_t* elevator);

int main() {
    elevator_t elevator;
    initialize_elevator(&elevator);
    run_simulation(&elevator);

    return 0;
}

void initialize_elevator(elevator_t* elevator) {
    elevator->current_floor = 0;
    elevator->direction = 1;

    srand(time(NULL));
    for (int i = 0; i < MAX_FLOORS; i++) {
        elevator->floors[i].number = i;
        elevator->floors[i].floor = i;
        initialize_people(elevator->floors[i].people, MAX_PEOPLE);
    }
}

void initialize_people(person_t* people, int number) {
    for (int i = 0; i < number; i++) {
        randomize_floor(&people[i]);
    }
}

void randomize_floor(person_t* person) {
    person->floor = rand() % MAX_FLOORS;
    do {
        person->destination = rand() % MAX_FLOORS;
    } while (person->destination == person->floor);
}

void run_simulation(elevator_t* elevator) {
    int count = 0;
    while (count < 100) {
        move_elevator(elevator);
        add_people_to_elevator(elevator, &elevator->floors[elevator->current_floor]);
        remove_people_from_elevator(elevator);
        print_elevator_status(elevator);
        count++;
    }
}

void move_elevator(elevator_t* elevator) {
    if (elevator->current_floor == MAX_FLOORS - 1) {
        elevator->direction = -1;
    } else if (elevator->current_floor == 0) {
        elevator->direction = 1;
    }
    elevator->current_floor += elevator->direction;
}

void add_people_to_elevator(elevator_t* elevator, floor_t* floor) {
    for (int i = 0; i < MAX_PEOPLE; i++) {
        if (floor->people[i].floor == elevator->current_floor) {
            int j = 0;
            while (j < MAX_PEOPLE && elevator->floors[elevator->current_floor].people[j].floor != -1) {
                j++;
            }
            if (j < MAX_PEOPLE) {
                elevator->floors[elevator->current_floor].people[j] = floor->people[i];
                floor->people[i].floor = -1;
            }
        }
    }
}

void remove_people_from_elevator(elevator_t* elevator) {
    for (int i = 0; i < MAX_PEOPLE; i++) {
        if (elevator->floors[elevator->current_floor].people[i].destination == elevator->current_floor) {
            elevator->floors[elevator->current_floor].people[i].floor = -1;
            elevator->floors[elevator->current_floor].people[i].destination = -1;
        }
    }
}

void print_elevator_status(elevator_t* elevator) {
    printf("ELEVATOR STATUS:\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Direction: %s\n", elevator->direction == 1 ? "UP" : "DOWN");
    printf("People: ");
    for (int i = 0; i < MAX_PEOPLE; i++) {
        if (elevator->floors[elevator->current_floor].people[i].floor != -1) {
            printf("(%d,%d) ", elevator->floors[elevator->current_floor].people[i].floor,
                   elevator->floors[elevator->current_floor].people[i].destination);
        }
    }
    printf("\n");
    printf("-----------------------------------------------------\n");
}