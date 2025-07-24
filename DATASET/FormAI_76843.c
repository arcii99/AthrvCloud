//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOOR_COUNT 10
#define ELEVATOR_CAPACITY 5

typedef enum {IDLE, UP, DOWN} Direction;

typedef struct {
    int current_floor;
    Direction direction;
    int passengers[ELEVATOR_CAPACITY];
    int num_passengers;
} Elevator;

void move_elevator(Elevator* elevator) {
    if (elevator->direction == UP) {
        elevator->current_floor++;
    } else if (elevator->direction == DOWN) {
        elevator->current_floor--;
    }
}

void open_doors(Elevator* elevator) {
    printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
    if (elevator->num_passengers > 0) {
        printf("Passengers exiting elevator...\n");
        for (int i = 0; i < elevator->num_passengers; i++) {
            printf("Passenger %d has exited at floor %d.\n", elevator->passengers[i], elevator->current_floor);
        }
        elevator->num_passengers = 0;
    }
}

void close_doors(Elevator* elevator) {
    printf("Doors closing.\n");
}

void add_passenger(Elevator* elevator, int floor_number) {
    if (elevator->num_passengers < ELEVATOR_CAPACITY) {
        elevator->passengers[elevator->num_passengers++] = floor_number;
    }
}

int main() {
    srand(time(NULL));
    Elevator elevator = {
        .current_floor = rand() % FLOOR_COUNT + 1,
        .direction = IDLE,
        .num_passengers = 0
    };
    printf("Elevator starts at floor %d.\n", elevator.current_floor);
    int num_passengers_waiting[FLOOR_COUNT] = {0};
    for (int i = 0; i < FLOOR_COUNT; i++) {
        num_passengers_waiting[i] = rand() % (ELEVATOR_CAPACITY - elevator.num_passengers + 1);
    }
    printf("Elevator is now running.\n");
    while (1) {
        if (elevator.num_passengers == 0) {
            elevator.direction = IDLE;
        } else if (elevator.current_floor == FLOOR_COUNT) {
            elevator.direction = DOWN;
        } else if (elevator.current_floor == 1) {
            elevator.direction = UP;
        }
        if (elevator.direction == IDLE) {
            for (int i = elevator.current_floor - 1; i < FLOOR_COUNT; i++) {
                if (num_passengers_waiting[i] > 0) {
                    elevator.direction = UP;
                    break;
                }
            }
            if (elevator.direction == IDLE) {
                for (int i = elevator.current_floor - 1; i >= 0; i--) {
                    if (num_passengers_waiting[i] > 0) {
                        elevator.direction = DOWN;
                        break;
                    }
                }
            }
        }
        if (elevator.direction == UP) {
            move_elevator(&elevator);
            if (num_passengers_waiting[elevator.current_floor - 1] > 0) {
                open_doors(&elevator);
                for (int i = 0; i < num_passengers_waiting[elevator.current_floor - 1]; i++) {
                    add_passenger(&elevator, elevator.current_floor);
                }
                num_passengers_waiting[elevator.current_floor - 1] = 0;
                close_doors(&elevator);
            }
        } else if (elevator.direction == DOWN) {
            move_elevator(&elevator);
            if (num_passengers_waiting[elevator.current_floor - 1] > 0) {
                open_doors(&elevator);
                for (int i = 0; i < num_passengers_waiting[elevator.current_floor - 1]; i++) {
                    add_passenger(&elevator, elevator.current_floor);
                }
                num_passengers_waiting[elevator.current_floor - 1] = 0;
                close_doors(&elevator);
            }
        }

        // random passengers waiting
        int rand_index = rand() % FLOOR_COUNT;
        while (num_passengers_waiting[rand_index] < ELEVATOR_CAPACITY) {
            num_passengers_waiting[rand_index]++;
            if (rand() % 2 == 0) {
                break;
            }
            rand_index = (rand_index + 1) % FLOOR_COUNT;
        }
    }
    return 0;
}