//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef enum { UP, DOWN, STOPPED } State;

typedef struct {
    int src_floor;
    int dest_floor;
} Passenger;

typedef struct {
    State state;
    int current_floor;
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers;
} Elevator;

void move_elevator(Elevator* e, int dest) {
    if (e->state == STOPPED) {
        if (e->current_floor < dest) {
            e->state = UP;
        } else if (e->current_floor > dest) {
            e->state = DOWN;
        } // else: already on correct floor, stay STOPPED
    }
    while (e->current_floor != dest) {
        if (e->state == UP) {
            e->current_floor++;
        } else if (e->state == DOWN) {
            e->current_floor--;
        } // else: should not happen
        printf("Current floor: %d\n", e->current_floor);
    }
    printf("Arrived at destination floor %d\n", dest);
    e->state = STOPPED;
}

void add_passenger(Elevator* e, Passenger p) {
    if (e->num_passengers < MAX_PASSENGERS) {
        e->passengers[e->num_passengers++] = p;
        printf("Passenger added (from %d to %d)\n", p.src_floor, p.dest_floor);
    } else {
        printf("Elevator is full, cannot add passenger\n");
    }
}

void remove_passenger(Elevator* e, int index) {
    if (index >= 0 && index < e->num_passengers) {
        printf("Passenger removed (from %d to %d)\n", e->passengers[index].src_floor, e->passengers[index].dest_floor);
        e->num_passengers--;
        // shift remaining passengers to fill gap
        for (int i = index; i < e->num_passengers; i++) {
            e->passengers[i] = e->passengers[i+1];
        }
    }
}

void output_passengers(Elevator* e) {
    printf("Elevator currently has %d passengers:\n", e->num_passengers);
    for (int i = 0; i < e->num_passengers; i++) {
        printf("  - from floor %d to floor %d\n", e->passengers[i].src_floor, e->passengers[i].dest_floor);
    }
}

int main() {
    Elevator e;
    e.state = STOPPED;
    e.current_floor = 0;
    e.num_passengers = 0;
    printf("Starting elevator at floor %d\n", e.current_floor);

    // simulate some passengers
    add_passenger(&e, (Passenger){ 0, 5 });
    add_passenger(&e, (Passenger){ 2, 7 });
    add_passenger(&e, (Passenger){ 4, 1 });
    add_passenger(&e, (Passenger){ 9, 2 });
    output_passengers(&e);

    // move to floor 5
    move_elevator(&e, 5);
    remove_passenger(&e, 0);
    output_passengers(&e);

    // move to floor 7
    move_elevator(&e, 7);
    remove_passenger(&e, 0);
    output_passengers(&e);

    // move to floor 1
    move_elevator(&e, 1);
    remove_passenger(&e, 0);
    output_passengers(&e);

    // move to floor 2
    move_elevator(&e, 2);
    remove_passenger(&e, 0);
    output_passengers(&e);

    printf("Elevator is now empty\n");
    return 0;
}