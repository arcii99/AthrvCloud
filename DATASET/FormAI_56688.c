//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 2
#define MAX_ELEVATORS 4
#define MIN_ELEVATORS 1
#define MAX_PEOPLE 30
#define MIN_PEOPLE 5

enum Direction { UP, DOWN };

typedef struct {
    int from_floor;
    int to_floor;
} TravelRequest;

typedef struct {
    int current_floor;
    enum Direction direction;
    TravelRequest current_request;
    int time_remaining;
} Elevator;

typedef struct {
    int current_floor;
    int requested_floor;
    int time_waiting;
} Person;

Elevator elevators[MAX_ELEVATORS];
Person people[MAX_PEOPLE];
int num_elevators;
int num_people;

void print_building() {
    for (int i = MAX_FLOORS; i >= MIN_FLOORS; i--) {
        printf("%2d ", i);
        for (int j = 0; j < num_elevators; j++) {
            if (elevators[j].current_floor == i) {
                printf("| X ");
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
    }
    printf("   ");
    for (int j = 0; j < num_elevators; j++) {
        printf("----");
    }
    printf("\n    ");
    for (int j = 0; j < num_elevators; j++) {
        printf(" %d  ", j + 1);
    }
    printf("\n");
}

void move_elevator(int elevator_index) {
    Elevator *elevator = &elevators[elevator_index];
    if (elevator->time_remaining > 0) {
        elevator->time_remaining--;
        return;
    }
    if (elevator->current_request.to_floor > elevator->current_floor) {
        elevator->current_floor++;
        elevator->direction = UP;
    } else if (elevator->current_request.to_floor < elevator->current_floor) {
        elevator->current_floor--;
        elevator->direction = DOWN;
    } else {
        printf("Elevator %d done traveling from %d to %d\n",
                elevator_index + 1, elevator->current_request.from_floor,
                elevator->current_request.to_floor);
        elevator->current_request = (TravelRequest) { -1, -1 };
        elevator->time_remaining = 0;
    }
}

void process_elevator_requests() {
    for (int i = 0; i < num_elevators; i++) {
        if (elevators[i].current_request.from_floor == -1 &&
                elevators[i].current_request.to_floor == -1) {
            for (int j = 0; j < num_people; j++) {
                if (people[j].requested_floor != -1) {
                    elevators[i].current_request.from_floor =
                            elevators[i].current_floor;
                    elevators[i].current_request.to_floor =
                            people[j].requested_floor;
                    printf("Elevator %d traveling from %d to %d\n", i + 1,
                            elevators[i].current_request.from_floor,
                            elevators[i].current_request.to_floor);
                    people[j].requested_floor = -1;
                    break;
                }
            }
        }
        move_elevator(i);
    }
}

int add_person(int requested_floor) {
    for (int i = 0; i < num_people; i++) {
        if (people[i].requested_floor == -1) {
            people[i].current_floor = 1;
            people[i].requested_floor = requested_floor;
            printf("Person %d waiting on floor %d for elevator\n", i + 1,
                    people[i].current_floor);
            return 1;
        }
    }
    return 0;
}

void process_people_requests() {
    for (int i = 0; i < num_people; i++) {
        if (people[i].requested_floor == -1) {
            continue;
        }
        if (people[i].time_waiting > 10) {
            printf("Person %d got tired of waiting and left\n", i + 1);
            people[i].requested_floor = -1;
        } else {
            people[i].time_waiting++;
        }
    }
}

void simulate() {
    for (int i = 0; i < 300; i++) {
        printf("--- Minute %d ---\n", i);
        if ((rand() % 10) < 2 && add_person(rand() % MAX_FLOORS + 1)) {
            printf("New person added\n");
        }
        process_people_requests();
        process_elevator_requests();
        print_building();
    }
}

int main() {
    srand(time(NULL));
    num_elevators = MIN_ELEVATORS +
            (rand() % (MAX_ELEVATORS - MIN_ELEVATORS + 1));
    printf("Number of elevators: %d\n", num_elevators);
    for (int i = 0; i < num_elevators; i++) {
        elevators[i] = (Elevator) { 1, UP, -1, -1 };
    }
    num_people = MIN_PEOPLE + (rand() % (MAX_PEOPLE - MIN_PEOPLE + 1));
    printf("Number of people: %d\n", num_people);
    for (int i = 0; i < num_people; i++) {
        people[i] = (Person) { 1, -1, 0 };
    }
    simulate();
    return 0;
}