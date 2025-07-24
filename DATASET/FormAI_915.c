//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the remote control vehicle
#define VEHICLE_LENGTH 10
#define VEHICLE_WIDTH 5

// Define the maximum signal range of the remote control
#define SIGNAL_RANGE 100

// Define the starting position of the vehicle
#define START_X 0
#define START_Y 0

// Define the maximum number of obstacles in the environment
#define MAX_OBSTACLES 5

// Define the size of the environment
#define ENVIRONMENT_LENGTH 50
#define ENVIRONMENT_WIDTH 50

// Define the character symbols for printing the environment
#define OBSTACLE_SYMBOL '#'
#define VEHICLE_SYMBOL 'V'
#define EMPTY_SYMBOL '.'

// Define the commands for controlling the vehicle
#define TURN_LEFT 'L'
#define TURN_RIGHT 'R'
#define MOVE_FORWARD 'F'
#define MOVE_BACKWARD 'B'

// Define the structure for the environment
typedef struct _Environment {
    int obstacles[MAX_OBSTACLES][2];
    int num_obstacles;
} Environment;

// Define the structure for the vehicle
typedef struct _Vehicle {
    int x_pos;
    int y_pos;
    int direction; // 0 = North, 1 = East, 2 = South, 3 = West
} Vehicle;

// Function to initialize the environment with random obstacles
void initialize_environment(Environment *env) {
    srand(time(NULL));
    env->num_obstacles = rand() % MAX_OBSTACLES + 1;
    for (int i=0; i<env->num_obstacles; i++) {
        env->obstacles[i][0] = rand() % ENVIRONMENT_LENGTH;
        env->obstacles[i][1] = rand() % ENVIRONMENT_WIDTH;
    }
}

// Function to print the environment
void print_environment(Environment env, Vehicle veh) {
    for (int i=0; i<ENVIRONMENT_LENGTH; i++) {
        for (int j=0; j<ENVIRONMENT_WIDTH; j++) {
            char symbol = EMPTY_SYMBOL;
            for (int k=0; k<env.num_obstacles; k++) {
                if (env.obstacles[k][0] == i && env.obstacles[k][1] == j) {
                    symbol = OBSTACLE_SYMBOL;
                }
            }
            if (veh.x_pos == i && veh.y_pos == j) {
                symbol = VEHICLE_SYMBOL;
            }
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

// Function to check if the vehicle can move in the given direction
int can_move(Environment env, Vehicle veh, int direction) {
    int new_x_pos = veh.x_pos;
    int new_y_pos = veh.y_pos;
    switch (direction) {
        case 0: // North
            new_x_pos -= 1;
            break;
        case 1: // East
            new_y_pos += 1;
            break;
        case 2: // South
            new_x_pos += 1;
            break;
        case 3: // West
            new_y_pos -= 1;
            break;
    }
    if (new_x_pos < 0 || new_x_pos >= ENVIRONMENT_LENGTH || new_y_pos < 0 || new_y_pos >= ENVIRONMENT_WIDTH) {
        return 0;
    }
    for (int i=0; i<env.num_obstacles; i++) {
        if (env.obstacles[i][0] == new_x_pos && env.obstacles[i][1] == new_y_pos) {
            return 0;
        }
    }
    return 1;
}

// Function to handle the TURN_LEFT command
void handle_turn_left(Vehicle *veh) {
    veh->direction -= 1;
    if (veh->direction < 0) {
        veh->direction = 3;
    }
}

// Function to handle the TURN_RIGHT command
void handle_turn_right(Vehicle *veh) {
    veh->direction += 1;
    if (veh->direction > 3) {
        veh->direction = 0;
    }
}

// Function to handle the MOVE_FORWARD command
void handle_move_forward(Environment env, Vehicle *veh) {
    if (can_move(env, *veh, veh->direction)) {
        switch (veh->direction) {
            case 0: // North
                veh->x_pos -= 1;
                break;
            case 1: // East
                veh->y_pos += 1;
                break;
            case 2: // South
                veh->x_pos += 1;
                break;
            case 3: // West
                veh->y_pos -= 1;
                break;
        }
    }
}

// Function to handle the MOVE_BACKWARD command
void handle_move_backward(Environment env, Vehicle *veh) {
    int opposite_direction = (veh->direction + 2) % 4;
    if (can_move(env, *veh, opposite_direction)) {
        switch (opposite_direction) {
            case 0: // North
                veh->x_pos -= 1;
                break;
            case 1: // East
                veh->y_pos += 1;
                break;
            case 2: // South
                veh->x_pos += 1;
                break;
            case 3: // West
                veh->y_pos -= 1;
                break;
        }
    }
}

int main() {

    Environment env;
    Vehicle veh = {START_X, START_Y, 0};

    initialize_environment(&env);

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Your vehicle is located at position (%d, %d).\n", veh.x_pos, veh.y_pos);
    printf("You can send the following commands to the vehicle:\n");
    printf("- 'L' to turn left.\n");
    printf("- 'R' to turn right.\n");
    printf("- 'F' to move forward.\n");
    printf("- 'B' to move backward.\n");
    printf("\n");

    print_environment(env, veh);

    while (1) {

        printf("Enter a command: ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case TURN_LEFT:
                handle_turn_left(&veh);
                printf("Vehicle turned left.\n");
                break;
            case TURN_RIGHT:
                handle_turn_right(&veh);
                printf("Vehicle turned right.\n");
                break;
            case MOVE_FORWARD:
                handle_move_forward(env, &veh);
                printf("Vehicle moved forward.\n");
                break;
            case MOVE_BACKWARD:
                handle_move_backward(env, &veh);
                printf("Vehicle moved backward.\n");
                break;
            default:
                printf("Invalid command. Please try again.\n");
                continue;
        }

        print_environment(env, veh);

        // Check if the vehicle is still within signal range
        int distance_squared = veh.x_pos * veh.x_pos + veh.y_pos * veh.y_pos;
        if (distance_squared > SIGNAL_RANGE * SIGNAL_RANGE) {
            printf("Signal lost. Vehicle out of range.\n");
            break;
        }

        // Check if the vehicle has reached any obstacles
        for (int i=0; i<env.num_obstacles; i++) {
            if (veh.x_pos == env.obstacles[i][0] && veh.y_pos == env.obstacles[i][1]) {
                printf("Vehicle crashed into an obstacle.\n");
                break;
            }
        }

    }

    return 0;
}