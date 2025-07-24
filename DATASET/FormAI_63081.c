//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10

enum Direction {
    UP = 1,
    DOWN = -1
};

typedef struct {
    int current_floor;
    int direction;
    int num_passengers;
    int passengers[ELEVATOR_CAPACITY];
} Elevator;

typedef struct {
    int floor_number;
    int num_waiting_passengers;
} Floor;

void init_elevator(Elevator* elevator) {
    elevator->current_floor = 1;
    elevator->direction = UP;
    elevator->num_passengers = 0;
}

void init_floors(Floor floors[NUM_FLOORS]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i].floor_number = i + 1;
        floors[i].num_waiting_passengers = rand() % ELEVATOR_CAPACITY;
    }
}

void print_elevator(Elevator* elevator) {
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Direction: %s\n", elevator->direction == UP ? "Up" : "Down");
    printf("Num Passengers: %d\n", elevator->num_passengers);
    printf("Passengers: ");
    for (int i = 0; i < elevator->num_passengers; i++) {
        printf("%d ", elevator->passengers[i]);
    }
}

void print_floors(Floor floors[NUM_FLOORS]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("Floor %d\tNum Waiting Passengers: %d\n", floors[i].floor_number, floors[i].num_waiting_passengers);
    }
}

void board_passengers(Elevator* elevator, Floor* floor) {
    int num_boarding_passengers = 0;
    for (int i = 0; i < floor->num_waiting_passengers && elevator->num_passengers < ELEVATOR_CAPACITY; i++) {
        elevator->passengers[elevator->num_passengers] = rand() % 1000;
        elevator->num_passengers++;
        num_boarding_passengers++;
    }
    floor->num_waiting_passengers -= num_boarding_passengers;
}

void disembark_passengers(Elevator* elevator, Floor* floor) {
    int num_disembarking_passengers = 0;
    for (int i = 0; i < elevator->num_passengers; i++) {
        if (elevator->passengers[i] == elevator->current_floor * 100) {
            num_disembarking_passengers++;
        } else {
            elevator->passengers[i - num_disembarking_passengers] = elevator->passengers[i];
        }
    }
    elevator->num_passengers -= num_disembarking_passengers;
}

void move_elevator(Elevator* elevator) {
    if (elevator->current_floor == NUM_FLOORS) {
        elevator->direction = DOWN;
    } else if (elevator->current_floor == 1) {
        elevator->direction = UP;
    }

    elevator->current_floor += elevator->direction;
}

int main() {
    Elevator elevator;
    Floor floors[NUM_FLOORS];

    init_elevator(&elevator);
    init_floors(floors);

    while (1) {
        system("clear");

        printf("Elevator Status:\n");
        print_elevator(&elevator);
        printf("\nFloor Status:\n");
        print_floors(floors);

        board_passengers(&elevator, &floors[elevator.current_floor - 1]);
        disembark_passengers(&elevator, &floors[elevator.current_floor - 1]);

        move_elevator(&elevator);

        getchar();
    }
}