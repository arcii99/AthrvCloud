//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Macros for the size of the environment
#define ENV_WIDTH 20
#define ENV_HEIGHT 10

// Simulation environment
char environment[ENV_HEIGHT][ENV_WIDTH];

// Vehicle position
int v_x = ENV_WIDTH/2;
int v_y = ENV_HEIGHT/2;

// Vehicle direction
int v_dir = 0; // 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT

// Function to initialize environment
void initialize_environment() {
    for (int y = 0; y < ENV_HEIGHT; y++) {
        for (int x = 0; x < ENV_WIDTH; x++) {
            if (x == 0 || x == ENV_WIDTH-1 || y == 0 || y == ENV_HEIGHT-1) {
                environment[y][x] = '#'; // Border walls
            }
            else {
                environment[y][x] = ' '; // Empty space
            }
        }
    }
}

// Function to print the environment
void print_environment() {
    for (int y = 0; y < ENV_HEIGHT; y++) {
        for (int x = 0; x < ENV_WIDTH; x++) {
            printf("%c", environment[y][x]);
        }
        printf("\n");
    }
}

// Function to move the vehicle
void move_vehicle() {
    bool valid_move = false;
    switch (v_dir) {
        case 0: // UP
            if (v_y > 1 && environment[v_y-1][v_x] == ' ') {
                environment[v_y][v_x] = ' ';
                v_y--;
                environment[v_y][v_x] = '^';
                valid_move = true;
            }
            break;
        case 1: // RIGHT
            if (v_x < ENV_WIDTH-2 && environment[v_y][v_x+1] == ' ') {
                environment[v_y][v_x] = ' ';
                v_x++;
                environment[v_y][v_x] = '>';
                valid_move = true;
            }
            break;
        case 2: // DOWN
            if (v_y < ENV_HEIGHT-2 && environment[v_y+1][v_x] == ' ') {
                environment[v_y][v_x] = ' ';
                v_y++;
                environment[v_y][v_x] = 'v';
                valid_move = true;
            }
            break;
        case 3: // LEFT
            if (v_x > 1 && environment[v_y][v_x-1] == ' ') {
                environment[v_y][v_x] = ' ';
                v_x--;
                environment[v_y][v_x] = '<';
                valid_move = true;
            }
            break;
    }
    if (!valid_move) {
        printf("Invalid move!\n");
    }
}

// Function to turn the vehicle left
void turn_left() {
    v_dir = (v_dir + 3) % 4;
    switch (v_dir) {
        case 0: // UP
            environment[v_y][v_x] = '^';
            break;
        case 1: // RIGHT
            environment[v_y][v_x] = '>';
            break;
        case 2: // DOWN
            environment[v_y][v_x] = 'v';
            break;
        case 3: // LEFT
            environment[v_y][v_x] = '<';
            break;
    }
}

// Function to turn the vehicle right
void turn_right() {
    v_dir = (v_dir + 1) % 4;
    switch (v_dir) {
        case 0: // UP
            environment[v_y][v_x] = '^';
            break;
        case 1: // RIGHT
            environment[v_y][v_x] = '>';
            break;
        case 2: // DOWN
            environment[v_y][v_x] = 'v';
            break;
        case 3: // LEFT
            environment[v_y][v_x] = '<';
            break;
    }
}

// Main function
int main() {
    initialize_environment();
    environment[v_y][v_x] = '^'; // Initial vehicle direction is UP
    print_environment();
    
    // Simulation loop
    while (true) {
        char command;
        printf("Enter command (m = move, l = turn left, r = turn right, q = quit): ");
        scanf(" %c", &command);
        if (command == 'm') {
            move_vehicle();
        }
        else if (command == 'l') {
            turn_left();
        }
        else if (command == 'r') {
            turn_right();
        }
        else if (command == 'q') {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid command!\n");
        }
        print_environment();
    }
    
    return 0;
}