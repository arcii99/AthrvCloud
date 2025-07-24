//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 10

/* Enumeration for the direction of the elevator */
enum direction {
    UP,
    DOWN
};

/* Struct for the request of an elevator */
typedef struct {
    int floor;
    enum direction dir;
} request;

/* Struct for the elevator */
typedef struct {
    int current_floor;
    enum direction dir;
    int queue[FLOORS];
    int queue_size;
} elevator;

/* Function to add a request to the elevator's queue */
void add_request(elevator *e, request req);

/* Function to remove a request from the elevator's queue */
void remove_request(elevator *e, int index);

/* Function to check if the elevator should stop at the current floor */
int should_stop(elevator *e);

/* Main function */
int main() {
    elevator e = {1, UP, {}, 0};
    request req1 = {3, UP};
    request req2 = {7, DOWN};
    add_request(&e, req1);
    add_request(&e, req2);
    while (e.queue_size > 0) {
        printf("Elevator at floor %d going %s\n", e.current_floor, e.dir == UP ? "up" : "down");
        if (should_stop(&e)) {
            printf("Stopping at floor %d\n", e.current_floor);
            for (int i = 0; i < e.queue_size; i++) {
                if (e.queue[i] == e.current_floor) {
                    remove_request(&e, i);
                    break;
                }
            }
        }
        if (e.dir == UP) {
            e.current_floor++;
            if (e.current_floor == FLOORS) {
                e.dir = DOWN;
            }
        } else {
            e.current_floor--;
            if (e.current_floor == 1) {
                e.dir = UP;
            }
        }
    }
    printf("Elevator idle at floor 1\n");
    return 0;
}

/* Function to add a request to the elevator's queue */
void add_request(elevator *e, request req) {
    if (req.floor == e->current_floor) {
        printf("Elevator already at floor %d\n", req.floor);
        return;
    }
    if (e->queue_size == 0) {
        e->dir = req.floor > e->current_floor ? UP : DOWN;
        e->queue[0] = req.floor;
        e->queue_size++;
    } else {
        int i;
        for (i = 0; i < e->queue_size; i++) {
            if (e->queue[i] == req.floor) {
                printf("Elevator already going to floor %d\n", req.floor);
                return;
            }
            if ((e->dir == UP && req.floor < e->queue[i]) || (e->dir == DOWN && req.floor > e->queue[i])) {
                break;
            }
        }
        for (int j = e->queue_size - 1; j >= i; j--) {
            e->queue[j+1] = e->queue[j];
        }
        e->queue[i] = req.floor;
        e->queue_size++;
    }
    printf("Request added to elevator queue: floor %d, going %s\n", req.floor, req.dir == UP ? "up" : "down");
}

/* Function to remove a request from the elevator's queue */
void remove_request(elevator *e, int index) {
    for (int i = index; i < e->queue_size - 1; i++) {
        e->queue[i] = e->queue[i+1];
    }
    e->queue_size--;
}

/* Function to check if the elevator should stop at the current floor */
int should_stop(elevator *e) {
    for (int i = 0; i < e->queue_size; i++) {
        if (e->queue[i] == e->current_floor) {
            return 1;
        }
    }
    return 0;
}