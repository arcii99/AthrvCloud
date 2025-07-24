//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 8

typedef struct {
    int passengers[ELEVATOR_CAPACITY];
    int passenger_count;
    int current_floor;
    int direction; // 0 for stay, 1 for up, -1 for down
} elevator;

void add_passenger(elevator *e) {
    if (e->passenger_count < ELEVATOR_CAPACITY) {
        e->passengers[e->passenger_count] = 1;
        e->passenger_count++;
    } else {
        printf("Elevator is full, cannot add more passengers.\n");
    }
}

void remove_passenger(elevator *e) {
    if (e->passenger_count > 0) {
        e->passengers[e->passenger_count - 1] = 0;
        e->passenger_count--;
    } else {
        printf("Elevator is empty, cannot remove any passengers.\n");
    }
}

void move_elevator(elevator *e) {
    if (e->direction == 1) {
        e->current_floor++;
        if (e->current_floor == MAX_FLOORS) {
            e->direction = -1;
            printf("Elevator reached the top floor and is now going down.\n");
        }
    } else if (e->direction == -1) {
        e->current_floor--;
        if (e->current_floor == 0) {
            e->direction = 1;
            printf("Elevator reached the ground floor and is now going up.\n");
        }
    }
}

void print_building(elevator *e) {
    for (int i = MAX_FLOORS; i > 0; i--) {
        printf("Floor %d:", i);
        if (i == e->current_floor) {
            printf(" [Elevator]");
            for (int j = 0; j < ELEVATOR_CAPACITY; j++) {
                if (e->passengers[j] == 1) {
                    printf(" [#]");
                } else {
                    printf(" [ ]");
                }
            }
        }
        printf("\n");
    }
}

int main() {

    srand(time(NULL));

    elevator e;
    e.passenger_count = 0;
    e.current_floor = 0;
    e.direction = 1;

    int tick_counter = 0;
    int add_counter = 0;
    int remove_counter = 0;

    while (1) {

        printf("--------------------\n");

        if (tick_counter % 10 == 0) {
            if (rand() % 2 == 0) {
                add_passenger(&e);
                add_counter++;
            } else {
                remove_passenger(&e);
                remove_counter++;
            }
        }

        if (tick_counter % 20 == 0) {
            move_elevator(&e);
        }

        print_building(&e);

        printf("--------------------\n");

        if (add_counter == 10) {
            printf("Passenger addition limit reached.\n");
            break;
        }

        if (remove_counter == 10) {
            printf("Passenger removal limit reached.\n");
            break;
        }

        tick_counter++;
    }

    return 0;
}