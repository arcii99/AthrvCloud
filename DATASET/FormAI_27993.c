//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10 // Number of floors in our building
#define NUM_ELEVATORS 2 // Number of elevators in our building

enum State { IDLE, MOVING_UP, MOVING_DOWN, OPENING_DOORS, CLOSING_DOORS };

struct Elevator {
    int id;
    int current_floor;
    enum State state;
    int destination;
};

struct Floor {
    int floor_number;
    int waiting_passengers;
    enum State elevator_state[NUM_ELEVATORS];
};

struct Building {
    struct Elevator elevators[NUM_ELEVATORS];
    struct Floor floors[NUM_FLOORS];
};

void init_building(struct Building* building);
void print_elevator_state(struct Elevator elevator);
void print_floor_state(struct Floor floor);
void print_building_state(struct Building* building);
void elevator_tick(struct Elevator* elevator);
void floor_tick(struct Floor* floor, struct Elevator* elevators, int num_elevators);
void building_tick(struct Building* building);
void passenger_arrives(struct Floor* floor);
void set_destination(struct Elevator* elevator, int floor);

int main() {
    struct Building building;
    init_building(&building);

    printf("Initial state of the building:\n");
    print_building_state(&building);

    printf("\nPress Enter to start the simulation...\n");
    getchar();

    while (1) {
        // Generate some passengers randomly
        for (int i = 0; i < NUM_FLOORS; ++i) {
            if (rand() % 10 < 4) {
                passenger_arrives(&building.floors[i]);
            }
        }

        building_tick(&building);

        print_building_state(&building);

        printf("\nPress Enter to continue...\n");
        getchar();
    }

    return 0;
}

void init_building(struct Building* building) {
    // Initialize elevators
    for (int i = 0; i < NUM_ELEVATORS; ++i) {
        building->elevators[i].id = i;
        building->elevators[i].current_floor = 0;
        building->elevators[i].state = IDLE;
        building->elevators[i].destination = -1;
    }

    // Initialize floors
    for (int i = 0; i < NUM_FLOORS; ++i) {
        building->floors[i].floor_number = i;
        building->floors[i].waiting_passengers = 0;
        for (int j = 0; j < NUM_ELEVATORS; ++j) {
            building->floors[i].elevator_state[j] = IDLE;
        }
    }
}

void print_elevator_state(struct Elevator elevator) {
    printf("Elevator %d: %d -> %d (%s)\n", elevator.id, elevator.current_floor,
            elevator.destination, elevator.state == IDLE ? "idle" :
            elevator.state == MOVING_UP ? "moving up" :
            elevator.state == MOVING_DOWN ? "moving down" :
            elevator.state == OPENING_DOORS ? "opening doors" :
            elevator.state == CLOSING_DOORS ? "closing doors" : "");
}

void print_floor_state(struct Floor floor) {
    printf("Floor %d: %d passengers waiting\n", floor.floor_number, floor.waiting_passengers);
}

void print_building_state(struct Building* building) {
    printf("\n");
    for (int i = NUM_FLOORS - 1; i >= 0; --i) {
        print_floor_state(building->floors[i]);
    }
    printf("\n");
    for (int i = 0; i < NUM_ELEVATORS; ++i) {
        print_elevator_state(building->elevators[i]);
    }
}

void elevator_tick(struct Elevator* elevator) {
    switch (elevator->state) {
        case IDLE:
            if (elevator->destination != -1 && elevator->destination > elevator->current_floor) {
                elevator->state = MOVING_UP;
            } else if (elevator->destination != -1 && elevator->destination < elevator->current_floor) {
                elevator->state = MOVING_DOWN;
            }
            break;
        case MOVING_UP:
            elevator->current_floor++;
            if (elevator->current_floor == elevator->destination) {
                elevator->state = OPENING_DOORS;
            }
            break;
        case MOVING_DOWN:
            elevator->current_floor--;
            if (elevator->current_floor == elevator->destination) {
                elevator->state = OPENING_DOORS;
            }
            break;
        case OPENING_DOORS:
            elevator->state = CLOSING_DOORS;
            break;
        case CLOSING_DOORS:
            elevator->state = IDLE;
            elevator->destination = -1;
            break;
    }
}

void floor_tick(struct Floor* floor, struct Elevator* elevators, int num_elevators) {
    for (int i = 0; i < num_elevators; ++i) {
        if (elevators[i].current_floor == floor->floor_number) {
            floor->elevator_state[i] = OPENING_DOORS;
            elevators[i].destination = -1;
        } else if (floor->elevator_state[i] != CLOSING_DOORS) {
            floor->elevator_state[i] = IDLE;
        }
    }

    if (floor->waiting_passengers > 0) {
        for (int i = 0; i < num_elevators; ++i) {
            if (elevators[i].state == IDLE) {
                set_destination(&elevators[i], floor->floor_number);
                elevators[i].state = floor->floor_number < elevators[i].current_floor ? MOVING_DOWN :
                        floor->floor_number > elevators[i].current_floor ? MOVING_UP : IDLE;
                floor->waiting_passengers--;
                break;
            }
        }
    }
}

void building_tick(struct Building* building) {
    for (int i = 0; i < NUM_ELEVATORS; ++i) {
        elevator_tick(&building->elevators[i]);
    }

    for (int i = 0; i < NUM_FLOORS; ++i) {
        floor_tick(&building->floors[i], building->elevators, NUM_ELEVATORS);
    }
}

void passenger_arrives(struct Floor* floor) {
    floor->waiting_passengers++;
}

void set_destination(struct Elevator* elevator, int floor) {
    elevator->destination = floor;
}