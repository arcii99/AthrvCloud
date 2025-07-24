//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>

// define constants for max drone speed and range
#define MAX_SPEED 50
#define MAX_RANGE 5000

// function to send commands to drone
void send_command(char command[]) {
    printf("Sending Command: %s\n", command);
}

// function to take off drone
void take_off() {
    send_command("Take Off");
}

// function to land drone
void land() {
    send_command("Land");
}

// function to move drone forward with speed as parameter
void move_forward(int speed) {
    if (speed > MAX_SPEED) {
        printf("Speed cannot exceed %d\n", MAX_SPEED);
    } else {
        char command[100];
        sprintf(command, "Move Forward at Speed %d", speed);
        send_command(command);
    }
}

// function to move drone backward with speed as parameter
void move_backward(int speed) {
    if (speed > MAX_SPEED) {
        printf("Speed cannot exceed %d\n", MAX_SPEED);
    } else {
        char command[100];
        sprintf(command, "Move Backward at Speed %d", speed);
        send_command(command);
    }
}

// function to move drone left with speed as parameter
void move_left(int speed) {
    if (speed > MAX_SPEED) {
        printf("Speed cannot exceed %d\n", MAX_SPEED);
    } else {
        char command[100];
        sprintf(command, "Move Left at Speed %d", speed);
        send_command(command);
    }
}

// function to move drone right with speed as parameter
void move_right(int speed) {
    if (speed > MAX_SPEED) {
        printf("Speed cannot exceed %d\n", MAX_SPEED);
    } else {
        char command[100];
        sprintf(command, "Move Right at Speed %d", speed);
        send_command(command);
    }
}

// function to hover drone at current position
void hover() {
    send_command("Hover");
}

// function to return drone to base and land
void return_to_base() {
    send_command("Return to Base and Land");
}

// function to check drone range
void check_range(int current_range) {
    if (current_range > MAX_RANGE) {
        printf("Drone has exceeded maximum range of %d\n", MAX_RANGE);
        return_to_base();
    } else {
        printf("Current Range: %d\n", current_range);
    }
}

int main() {
    // sample drone control program
    take_off();
    move_forward(25);
    move_left(15);
    move_backward(30);
    move_right(20);
    hover();
    int current_range = 4500;
    check_range(current_range);
    land();
    return 0;
}