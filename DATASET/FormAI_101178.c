//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants to represent the elevator status
#define IDLE 0
#define UP 1
#define DOWN -1

// Constants to represent floor numbers
#define FLOOR_MIN 0
#define FLOOR_MAX 10

// Constants to represent message types
#define REQUEST_FLOOR 1
#define REQUEST_DIRECTION 2

// Struct to represent a message
typedef struct Message {
    int type;       // Type of message (request floor or request direction)
    int floor;      // Floor number
    int direction;  // Elevator direction (up or down)
} Message;

// Struct to represent an elevator
typedef struct Elevator {
    int id;
    int floor;
    int status;
} Elevator;

// Function to print the status of an elevator
void print_elevator_status(Elevator *elevator) {
    printf("Elevator %d is currently on floor %d and is ", elevator->id, elevator->floor);

    if (elevator->status == IDLE) {
        printf("idle.\n");
    } else if (elevator->status == UP) {
        printf("going up.\n");
    } else if (elevator->status == DOWN) {
        printf("going down.\n");
    }
}

// Function to simulate moving an elevator up one floor
void move_elevator_up(Elevator *elevator) {
    elevator->floor++;
    printf("Elevator %d has moved up to floor %d.\n", elevator->id, elevator->floor);
}

// Function to simulate moving an elevator down one floor
void move_elevator_down(Elevator *elevator) {
    elevator->floor--;
    printf("Elevator %d has moved down to floor %d.\n", elevator->id, elevator->floor);
}

// Function to process messages and update the elevator status
void process_messages(Elevator *elevator, Message *message) {
    if (message->type == REQUEST_FLOOR) {
        printf("Elevator %d received request to go to floor %d.\n", elevator->id, message->floor);

        // Move elevator up or down to requested floor
        if (message->floor > elevator->floor) {
            elevator->status = UP;
            while (elevator->floor != message->floor) {
                move_elevator_up(elevator);
            }
        } else if (message->floor < elevator->floor) {
            elevator->status = DOWN;
            while (elevator->floor != message->floor) {
                move_elevator_down(elevator);
            }
        }

        printf("Elevator %d has arrived at floor %d.\n", elevator->id, elevator->floor);
        elevator->status = IDLE;

    } else if (message->type == REQUEST_DIRECTION) {
        printf("Elevator %d received request to go %s.\n", elevator->id, message->direction == UP ? "up" : "down");

        // Set status to requested direction
        elevator->status = message->direction;
    }
}

// Main program
int main() {
    // Initialize 3 elevators
    Elevator elevator1 = {1, 0, IDLE};
    Elevator elevator2 = {2, 5, IDLE};
    Elevator elevator3 = {3, 10, IDLE};

    // Print initial elevator status
    print_elevator_status(&elevator1);
    print_elevator_status(&elevator2);
    print_elevator_status(&elevator3);

    // Process messages to simulate elevator requests
    Message message1 = {REQUEST_FLOOR, 7, 0};
    Message message2 = {REQUEST_DIRECTION, 1, UP};
    Message message3 = {REQUEST_FLOOR, 2, 0};
    Message message4 = {REQUEST_FLOOR, 1, 0};
    Message message5 = {REQUEST_DIRECTION, 0, DOWN};
    Message message6 = {REQUEST_FLOOR, 5, 0};

    process_messages(&elevator1, &message1);
    process_messages(&elevator2, &message2);
    process_messages(&elevator3, &message3);
    process_messages(&elevator1, &message4);
    process_messages(&elevator1, &message5);
    process_messages(&elevator2, &message6);

    // Print final elevator status
    print_elevator_status(&elevator1);
    print_elevator_status(&elevator2);
    print_elevator_status(&elevator3);

    return 0;
}