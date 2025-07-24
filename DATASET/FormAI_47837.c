//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Enums
typedef enum { direction_none, direction_up, direction_down } direction_t;
typedef enum { door_closed, door_open } door_state_t;
typedef enum { state_stopped, state_moving } elevator_state_t;

// Structs
typedef struct {
    int id;
    int current_floor;
    bool destinations[NUM_FLOORS];
    direction_t direction;
    elevator_state_t state;
    door_state_t door;
} elevator_t;

// Function prototypes
void initialize_elevators(elevator_t elevators[]);
void print_elevator_status(elevator_t elevators[]);
void make_request(elevator_t elevators[]);

int main() {
    // Initialize elevators and request queue
    elevator_t elevators[NUM_ELEVATORS];
    initialize_elevators(elevators);

    while (true) {
        // Print current elevator statuses
        print_elevator_status(elevators);

        // Get elevator requests from input
        make_request(elevators);
    }

    return 0;
}

// Initializes each elevator to its defaults
void initialize_elevators(elevator_t elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].current_floor = 0;
        for (int j = 0; j < NUM_FLOORS; j++) {
            elevators[i].destinations[j] = false;
        }
        elevators[i].direction = direction_none;
        elevators[i].state = state_stopped;
        elevators[i].door = door_closed;
    }
}

// Prints out the current status of each elevator
void print_elevator_status(elevator_t elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: \n", i);
        printf("  Current floor: %d\n", elevators[i].current_floor);
        printf("  Destinations: ");
        for (int j = 0; j < NUM_FLOORS; j++) {
            if (elevators[i].destinations[j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
        printf("  Direction: ");
        switch (elevators[i].direction) {
            case direction_up:
                printf("Up\n");
                break;
            case direction_down:
                printf("Down\n");
                break;
            default:
                printf("None\n");
                break;
        }
        printf("  State: ");
        switch (elevators[i].state) {
            case state_stopped:
                printf("Stopped\n");
                break;
            case state_moving:
                printf("Moving\n");
                break;
        }
        printf("  Door: ");
        switch (elevators[i].door) {
            case door_closed:
                printf("Closed\n");
                break;
            case door_open:
                printf("Open\n");
                break;
        }
        printf("\n");
    }
}

// Gets an elevator request from the user and adds it to the appropriate elevator's queue
void make_request(elevator_t elevators[]) {
    int elevator_id, floor_num;
    direction_t direction;

    printf("Enter elevator id: ");
    scanf("%d", &elevator_id);
    if (elevator_id < 0 || elevator_id >= NUM_ELEVATORS) {
        printf("Invalid elevator id.\n");
        return;
    }

    printf("Enter floor number: ");
    scanf("%d", &floor_num);
    if (floor_num < 0 || floor_num >= NUM_FLOORS) {
        printf("Invalid floor number.\n");
        return;
    }

    printf("Enter direction (0=none, 1=up, 2=down): ");
    scanf("%d", &direction);
    if (direction < 0 || direction > 2) {
        printf("Invalid direction.\n");
        return;
    }

    elevators[elevator_id].destinations[floor_num] = true;
    elevators[elevator_id].direction = direction;
}