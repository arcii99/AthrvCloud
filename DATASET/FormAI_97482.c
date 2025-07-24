//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOOR_MAX 5 // total number of floors in the building
#define ELEVATOR_MAX 3 // total number of elevators in the building

enum Direction {UP, DOWN, HOLD}; // elevator Direction
enum State {IDLE, BUSY}; // elevator State

typedef struct {
    int id;
    int currentFloor;
    int targetFloor;
    enum Direction direction;
    enum State state;
} Elevator;

Elevator elevators[ELEVATOR_MAX]; // array of elevators
int requests[FLOOR_MAX] = {0}; // array of requests on each floor

void move_elevator(Elevator *elevator, int targetFloor);
void process_requests();
void display_building_status();

int main() {
    srand(time(NULL)); // seed the random number generator
    
    // initialize elevators
    for (int i=0; i<ELEVATOR_MAX; i++) {
        elevators[i].id = i + 1;
        elevators[i].currentFloor = 1;
        elevators[i].targetFloor = 1;
        elevators[i].direction = HOLD;
        elevators[i].state = IDLE;
    }
    
    // simulate elevator requests for 10 minutes
    for (int i=0; i<10; i++) {
        int floor = rand() % FLOOR_MAX + 1;
        int direction = rand() % 2;
        requests[floor-1] |= (1 << direction);
        printf("Request received on Floor %d, going %s.\n", floor, direction == UP ? "UP" : "DOWN");
    }
    
    // process requests until all elevators are idle
    while (1) {
        process_requests();
        display_building_status();
        int idle_count = 0;
        for (int i=0; i<ELEVATOR_MAX; i++) {
            if (elevators[i].state == IDLE) {
                idle_count++;
            }
        }
        if (idle_count == ELEVATOR_MAX) {
            break;
        }
    }
    
    printf("All elevators are idle. Simulation ended.");
    
    return 0;
}

void move_elevator(Elevator *elevator, int targetFloor) {
    if (elevator->currentFloor == targetFloor) {
        elevator->state = IDLE;
        printf("Elevator %d has arrived at Floor %d.\n", elevator->id, targetFloor);
        return;
    }
    
    elevator->state = BUSY;
    if (elevator->currentFloor < targetFloor) {
        elevator->currentFloor++;
        elevator->direction = UP;
    }
    else {
        elevator->currentFloor--;
        elevator->direction = DOWN;
    }
    printf("Elevator %d is at Floor %d, going %s.\n", elevator->id, elevator->currentFloor, elevator->direction == UP ? "UP" : "DOWN");
}

void process_requests() {
    // for each floor, check if there are any requests going up or down
    for (int i=0; i<FLOOR_MAX; i++) {
        if (requests[i] != 0) {
            for (int j=0; j<ELEVATOR_MAX; j++) {
                Elevator *elevator = &elevators[j];
                if (elevator->state == IDLE) {
                    int direction = requests[i] & (1 << elevator->currentFloor-1);
                    if (direction) {
                        elevator->targetFloor = i + 1;
                        move_elevator(elevator, elevator->targetFloor);
                        requests[i] &= ~(1 << elevator->targetFloor-1);
                        break;
                    }
                }
                else {
                    if ((elevator->direction == UP && i+1 > elevator->currentFloor && i+1 < elevator->targetFloor) ||
                        (elevator->direction == DOWN && i+1 < elevator->currentFloor && i+1 > elevator->targetFloor)) {
                        elevator->targetFloor = i + 1;
                        requests[i] &= ~(1 << elevator->targetFloor-1);
                        break;
                    }
                }
            }
        }
    }
}

void display_building_status() {
    printf("\n");
    for (int i=FLOOR_MAX; i>=1; i--) {
        printf("Floor %d | ", i);
        for (int j=0; j<ELEVATOR_MAX; j++) {
            if (elevators[j].currentFloor == i) {
                printf("[E%d]", elevators[j].id);
            }
            else {
                printf("[   ]");
            }
        }
        if (requests[i-1] & (1 << UP)) {
            printf("  ^");
        }
        if (requests[i-1] & (1 << DOWN)) {
            printf("  v");
        }
        printf("\n");
    }
    printf("        ");
    for (int i=0; i<ELEVATOR_MAX; i++) {
        printf("---- ");
    }
    printf("\n");
    printf("        ");
    for (int i=1; i<=ELEVATOR_MAX; i++) {
        printf("E%d   ", i);
    }
    printf("\n");
}