//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

// Elevator status
enum Status {IDLE, RUNNING};

// Elevator structure
struct Elevator {
    int currentFloor;
    int destination;
    enum Status status;
};

// Call queue structure
struct CallQueue {
    int queue[MAX_FLOORS];
    int front;
    int rear;
};

// Initialization function for call queue
void initCallQueue(struct CallQueue *c) {
    c->front = 0;
    c->rear = -1;
}

// Insert function for call queue
void insertCallQueue(struct CallQueue *c, int call) {
    c->rear++;
    c->queue[c->rear] = call;
}

// Remove function for call queue
int removeCallQueue(struct CallQueue *c) {
    int call = c->queue[c->front];
    c->front++;
    return call;
}

// Elevator function
void elevator(int id, struct Elevator *e, struct CallQueue *c) {
    while (1) {
        if (e->status == IDLE) {
            if (c->front <= c->rear) {
                e->status = RUNNING;
                e->destination = removeCallQueue(c);
            }
        } else {
            if (e->currentFloor < e->destination) {
                ++e->currentFloor;
            } else if (e->currentFloor > e->destination) {
                --e->currentFloor;
            } else {
                e->status = IDLE;
                printf("Elevator %d is now at floor %d\n", id, e->currentFloor);
            }
        }
    }
}

int main(void) {
    struct Elevator elevators[MAX_ELEVATORS];
    struct CallQueue callQueues[MAX_FLOORS];
    int i, j;
    for (i = 0; i < MAX_ELEVATORS; ++i) {
        elevators[i].currentFloor = 0;
        elevators[i].destination = 0;
        elevators[i].status = IDLE;
    }

    for (i = 0; i < MAX_FLOORS; ++i) {
        initCallQueue(&callQueues[i]);
    }

    insertCallQueue(&callQueues[4], 1);
    insertCallQueue(&callQueues[0], 2);
    insertCallQueue(&callQueues[8], 3);

    for (i = 0; i < MAX_ELEVATORS; ++i) {
        elevator(i, &elevators[i], &callQueues[i]);
    }
    return 0;
}