//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

// Define constants for the width and height of the simulation board
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

// Define the commands that the remote control can send to the vehicle
typedef enum {
    FORWARD,
    BACKWARD,
    TURN_LEFT,
    TURN_RIGHT,
    STOP
} Command;

// Define the structure of the remote control, which stores the current command
typedef struct {
    Command current_command;
} RemoteControl;

// Define the structure of the vehicle, which stores its position and direction
typedef struct {
    int x, y;
    int direction; // 0 = north, 1 = east, 2 = south, 3 = west
} Vehicle;

// Define a function to initialize the vehicle to the starting position
void initialize_vehicle(Vehicle *vehicle) {
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->direction = 1; // start facing east
}

// Define a function to update the position of the vehicle based on its direction
bool update_vehicle(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case 0:
            if (vehicle->y > 0) {
                vehicle->y--;
                return true;
            }
            break;
        case 1:
            if (vehicle->x < BOARD_WIDTH - 1) {
                vehicle->x++;
                return true;
            }
            break;
        case 2:
            if (vehicle->y < BOARD_HEIGHT - 1) {
                vehicle->y++;
                return true;
            }
            break;
        case 3:
            if (vehicle->x > 0) {
                vehicle->x--;
                return true;
            }
            break;
    }
    return false; // cannot move in the current direction
}

// Define a function to rotate the vehicle left or right
void rotate_vehicle(Vehicle *vehicle, bool is_left) {
    if (is_left) {
        vehicle->direction--;
        if (vehicle->direction < 0) {
            vehicle->direction = 3;
        }
    } else {
        vehicle->direction++;
        if (vehicle->direction > 3) {
            vehicle->direction = 0;
        }
    }
}

// Define a function to print the current state of the simulation board
void print_board(Vehicle *vehicle) {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (x == vehicle->x && y == vehicle->y) {
                switch (vehicle->direction) {
                    case 0:
                        printf("^ ");
                        break;
                    case 1:
                        printf("> ");
                        break;
                    case 2:
                        printf("v ");
                        break;
                    case 3:
                        printf("< ");
                        break;
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Define the main function to run the simulation
int main() {
    RemoteControl remote_control;
    Vehicle vehicle;
    initialize_vehicle(&vehicle);
    while (true) {
        // Print the current state of the simulation board
        print_board(&vehicle);
        // Prompt the user for a command
        printf("Enter a command (F = forward, B = backward, L = left, R = right, S = stop): ");
        char command_char;
        scanf(" %c", &command_char);
        switch (command_char) {
            case 'F':
                remote_control.current_command = FORWARD;
                break;
            case 'B':
                remote_control.current_command = BACKWARD;
                break;
            case 'L':
                remote_control.current_command = TURN_LEFT;
                break;
            case 'R':
                remote_control.current_command = TURN_RIGHT;
                break;
            case 'S':
                remote_control.current_command = STOP;
                break;
            default:
                printf("Invalid command.\n");
                continue;
        }
        // Execute the current command on the vehicle
        switch (remote_control.current_command) {
            case FORWARD:
                if (update_vehicle(&vehicle)) {
                    printf("Vehicle moved forward.\n");
                } else {
                    printf("Cannot move forward in the current direction.\n");
                }
                break;
            case BACKWARD:
                rotate_vehicle(&vehicle, true);
                rotate_vehicle(&vehicle, true);
                if (update_vehicle(&vehicle)) {
                    printf("Vehicle moved backward.\n");
                } else {
                    printf("Cannot move backward in the current direction.\n");
                }
                break;
            case TURN_LEFT:
                rotate_vehicle(&vehicle, true);
                printf("Vehicle turned left.\n");
                break;
            case TURN_RIGHT:
                rotate_vehicle(&vehicle, false);
                printf("Vehicle turned right.\n");
                break;
            case STOP:
                printf("Vehicle stopped.\n");
                return 0;
        }
    }
}