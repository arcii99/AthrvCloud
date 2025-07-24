//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>    

// Maximum floor number
#define MAX_FLOORS 10

// Time for elevator to move from one floor to another (in seconds)
#define MOVE_TIME 1

// Time for door to open or close (in seconds) 
#define DOOR_TIME 2

// Enumeration representing the direction of movement of elevator
typedef enum {
    UP,
    DOWN,
    STOP
} direction;

// Structure representing each floor
typedef struct Floor {
    int number;                     // Floor number
    bool up_button_pressed;         // Whether up button on floor is pressed
    bool down_button_pressed;       // Whether down button on floor is pressed
} floor_t;

// Structure representing the elevator
typedef struct Elevator {
    int current_floor;              // The current floor of the elevator
    direction current_direction;    // The direction in which the elevator is moving
    bool door_open;                 // Whether the elevator door is open or closed
    bool up_button_pressed;         // Whether up button inside elevator is pressed
    bool down_button_pressed;       // Whether down button inside elevator is pressed
} elevator_t;

// Function to simulate pressing a button inside the elevator
void press_button(elevator_t *elevator, floor_t floors[]) {
    if (elevator->current_floor != 0 && elevator->current_floor != MAX_FLOORS - 1) {
        if (elevator->current_direction == UP) {
            elevator->up_button_pressed = true;
        } else if (elevator->current_direction == DOWN) {
            elevator->down_button_pressed = true;
        } else {
            if (floors[elevator->current_floor].up_button_pressed) {
                elevator->up_button_pressed = true;
            } else if (floors[elevator->current_floor].down_button_pressed) {
                elevator->down_button_pressed = true;
            }
        }
        printf("Button pressed inside elevator");
    }
}

// Function to simulate opening/closing the elevator door
void simulate_door(elevator_t *elevator) {
    elevator->door_open = true;
    printf("Door is opening...\n");
    sleep(DOOR_TIME);
    elevator->door_open = false;
    printf("Door is closing...\n");
    sleep(DOOR_TIME);
}

// Function to simulate moving the elevator from one floor to another
void simulate_move(elevator_t *elevator) {
    if (elevator->current_direction == UP) {
        elevator->current_floor++;
    } else if (elevator->current_direction == DOWN) {
        elevator->current_floor--;
    }
    printf("Elevator is moving...\n");
    sleep(MOVE_TIME);
}

int main() {
    // Create floors and initialize them
    floor_t floors[MAX_FLOORS];
    for (int i = 0; i < MAX_FLOORS; i++) {
        floors[i].number = i;
        floors[i].up_button_pressed = false;
        floors[i].down_button_pressed = false;
    }

    // Create elevator and initialize it
    elevator_t elevator;
    elevator.current_floor = 0;
    elevator.current_direction = STOP;
    elevator.door_open = false;
    elevator.up_button_pressed = false;
    elevator.down_button_pressed = false;

    // Simulation loop
    while (true) {
        // Check if there are any up/down button pressed outside the elevator
        for (int i = 0; i < MAX_FLOORS; i++) {
            if (floors[i].up_button_pressed) {
                elevator.current_direction = UP;
            } else if (floors[i].down_button_pressed) {
                elevator.current_direction = DOWN;
            }
        }

        // Check if there are any up/down button pressed inside the elevator
        if (elevator.up_button_pressed || elevator.down_button_pressed) {
            elevator.current_direction = elevator.up_button_pressed ? UP : DOWN;
        }

        // Move the elevator if necessary
        if (elevator.current_direction == UP || elevator.current_direction == DOWN) {
            simulate_door(&elevator);
            simulate_move(&elevator);
        } else {
            printf("Waiting for button press...\n");
            sleep(1);
        }

        // Check if elevator has reached a floor and needs to stop
        if (elevator.current_direction == UP) {
            floors[elevator.current_floor].up_button_pressed = false;
            if (floors[elevator.current_floor].down_button_pressed || elevator.down_button_pressed) {
                simulate_door(&elevator);
                press_button(&elevator, floors);
            }
        } else if (elevator.current_direction == DOWN) {
            floors[elevator.current_floor].down_button_pressed = false;
            if (floors[elevator.current_floor].up_button_pressed || elevator.up_button_pressed) {
                simulate_door(&elevator);
                press_button(&elevator, floors);
            }
        }

        // Check if elevator has reached top/bottom floor and needs to stop
        if (elevator.current_floor == 0 || elevator.current_floor == MAX_FLOORS - 1) {
            elevator.current_direction = STOP;
            if (elevator.up_button_pressed || elevator.down_button_pressed) {
                simulate_door(&elevator);
                press_button(&elevator, floors);
            }
        }
    }

    return 0;
}