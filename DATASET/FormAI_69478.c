//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 15
#define WAIT_TIME 2

typedef struct {
    int from;
    int to;
} Passenger;

typedef struct {
    int num_passengers;
    Passenger passengers[MAX_PASSENGERS];
} Floor;

typedef struct {
    Floor floors[MAX_FLOORS];
    bool up_button[MAX_FLOORS];
    bool down_button[MAX_FLOORS];
    int num_floors;
    int num_passengers;
    int capacity;
    int current_floor;
    int direction; // 1 for up, -1 for down
} Elevator;

void init(Floor *floor) {
    floor->num_passengers = rand() % MAX_PASSENGERS + 1;
    for (int i = 0; i < floor->num_passengers; i++) {
        floor->passengers[i].from = rand() % MAX_FLOORS;
        do {
            floor->passengers[i].to = rand() % MAX_FLOORS;
        } while (floor->passengers[i].to == floor->passengers[i].from);
    }
}

void print_passenger(Passenger *p) {
    printf("(%d -> %d)", p->from, p->to);
}

void print_floor(Floor *floor) {
    printf("[ ");
    for (int i = 0; i < floor->num_passengers; i++) {
        print_passenger(&floor->passengers[i]);
    }
    printf(" ]");
}

void print_elevator(Elevator *elevator) {
    printf("Floor: %d\n", elevator->current_floor);
    printf("Direction: %s\n", elevator->direction == 1 ? "up" : "down");
    printf("Passengers: [ ");
    for (int i = 0; i < elevator->num_passengers; i++) {
        print_passenger(&elevator->floors[elevator->current_floor].passengers[i]);
    }
    printf(" ]\n");
}

void init_elevator(Elevator *elevator) {
    elevator->num_floors = rand() % MAX_FLOORS + 1;
    elevator->capacity = rand() % MAX_PASSENGERS + 1;
    elevator->current_floor = 0;
    elevator->direction = 1;
    for (int i = 0; i < elevator->num_floors; i++) {
        init(&elevator->floors[i]);
        elevator->up_button[i] = rand() % 2;
        elevator->down_button[i] = rand() % 2;
    }
    elevator->num_passengers = 0;
}

bool can_enter(Elevator *elevator, Passenger *p) {
    if (elevator->num_passengers >= elevator->capacity) {
        return false;
    }
    if (elevator->direction == 1) {
        if (p->from >= elevator->current_floor && p->to >= elevator->current_floor) {
            return true;
        }
    } else { // direction is -1
        if (p->from <= elevator->current_floor && p->to <= elevator->current_floor) {
            return true;
        }
    }
    return false;
}

bool can_exit(Elevator *elevator, Passenger *p) {
    return elevator->current_floor == p->to;
}

void board_passengers(Elevator *elevator) {
    Floor *floor = &elevator->floors[elevator->current_floor];
    int i = 0;
    while (i < floor->num_passengers) {
        Passenger *p = &floor->passengers[i];
        if (can_enter(elevator, p)) {
            printf("Passenger ");
            print_passenger(p);
            printf(" enters elevator\n");
            elevator->floors[elevator->current_floor].num_passengers--;
            elevator->floors[elevator->current_floor].passengers[i] = elevator->floors[elevator->current_floor].passengers[floor->num_passengers-1];
            floor->num_passengers--;
            elevator->num_passengers++;
            elevator->direction = elevator->floors[elevator->current_floor].passengers[i].to > elevator->current_floor ? 1 : -1;
        } else {
            i++;
        }
    }
}

void exit_passengers(Elevator *elevator) {
    int i = 0;
    while (i < elevator->num_passengers) {
        Passenger *p = &elevator->floors[elevator->current_floor].passengers[i];
        if (can_exit(elevator, p)) {
            printf("Passenger ");
            print_passenger(p);
            printf(" exits elevator\n");
            elevator->floors[elevator->current_floor].num_passengers++;
            elevator->floors[elevator->current_floor].passengers[elevator->floors[elevator->current_floor].num_passengers-1] = *p;
            elevator->num_passengers--;
            elevator->floors[elevator->current_floor].passengers[i] = elevator->floors[elevator->current_floor].passengers[elevator->num_passengers];
        } else {
            i++;
        }
    }
}

void move(Elevator *elevator) {
    if (elevator->direction == 1) {
        elevator->current_floor++;
        if (elevator->current_floor == elevator->num_floors-1) {
            elevator->direction = -1;
        }
    } else { // direction is -1
        elevator->current_floor--;
        if (elevator->current_floor == 0) {
            elevator->direction = 1;
        }
    }
}

bool has_passengers(Elevator *elevator) {
    return elevator->num_passengers > 0;
}

bool has_waiting_passengers(Elevator *elevator) {
    for (int i = 0; i < elevator->num_floors; i++) {
        if (elevator->floors[i].num_passengers > 0) {
            return true;
        }
    }
    return false;
}

void press_buttons(Elevator *elevator) {
    if (elevator->direction == 1) {
        for (int i = elevator->current_floor+1; i < elevator->num_floors; i++) {
            if (elevator->floors[i].num_passengers > 0 || elevator->up_button[i]) {
                elevator->up_button[i] = true;
            }
        }
    } else { // direction is -1
        for (int i = elevator->current_floor-1; i >= 0; i--) {
            if (elevator->floors[i].num_passengers > 0 || elevator->down_button[i]) {
                elevator->down_button[i] = true;
            }
        }
    }
}

void elevator_simulation() {
    Elevator elevator;
    init_elevator(&elevator);
    while (has_passengers(&elevator) || has_waiting_passengers(&elevator)) {
        printf("------------------------------\n");
        print_elevator(&elevator);
        for (int i = 0; i < elevator.num_floors; i++) {
            printf("Floor %d: ", i);
            print_floor(&elevator.floors[i]);
            printf("\n");
        }
        press_buttons(&elevator);
        if (has_passengers(&elevator)) {
            exit_passengers(&elevator);
        }
        if (has_waiting_passengers(&elevator)) {
            board_passengers(&elevator);
        }
        move(&elevator);
        sleep(WAIT_TIME);
    }
    printf("------------------------------\n");
    printf("Elevator is now empty\n");
}

int main() {
    elevator_simulation();
    return 0;
}