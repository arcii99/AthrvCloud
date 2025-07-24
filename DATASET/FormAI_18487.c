//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10

typedef struct {
    int floor;
    bool up;
    bool down;
} Request;

typedef struct {
    Request requests[NUM_FLOORS];
    int num_requests;
    int current_floor;
    bool moving_up;
    bool moving_down;
} Elevator;

void init_elevator(Elevator *e) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        e->requests[i].floor = i;
        e->requests[i].up = false;
        e->requests[i].down = false;
    }
    e->num_requests = 0;
    e->current_floor = 0;
    e->moving_up = false;
    e->moving_down = false;
}

void add_request(Elevator *e, int floor, bool up, bool down) {
    e->requests[floor].up |= up;
    e->requests[floor].down |= down;
    e->num_requests++;
}

void remove_request(Elevator *e, int floor) {
    e->requests[floor].up = false;
    e->requests[floor].down = false;
    e->num_requests--;
}

void handle_requests(Elevator *e) {
    if (e->current_floor == 0) {
        e->moving_up = true;
        e->moving_down = false;
    }
    else if (e->current_floor == NUM_FLOORS - 1) {
        e->moving_down = true;
        e->moving_up = false;
    }
    if (e->requests[e->current_floor].up || e->requests[e->current_floor].down) {
        printf("Stopping at floor %d\n", e->current_floor);
        remove_request(e, e->current_floor);
    }
    if (e->moving_up) {
        e->current_floor++;
    }
    else if (e->moving_down) {
        e->current_floor--;
    }
}

int main() {
    Elevator e;
    init_elevator(&e);

    // Add requests
    add_request(&e, 3, true, false);
    add_request(&e, 5, false, true);
    add_request(&e, 7, true, true);

    // Start elevator
    while (e.num_requests > 0) {
        handle_requests(&e);
    }
    printf("Elevator simulation complete\n");

    return 0;
}