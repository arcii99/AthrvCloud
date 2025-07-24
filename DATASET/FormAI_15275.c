//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>

/* Declarations */
void connect_to_drone();
void take_off();
void land();
void move_forward(int distance);
void move_backward(int distance);
void move_left(int distance);
void move_right(int distance);
void turn_left(int degrees);
void turn_right(int degrees);
void disconnect();

/* Main Program */
int main() {
    connect_to_drone();
    take_off();
    move_forward(10);
    move_right(5);
    turn_left(90);
    move_forward(20);
    turn_right(45);
    move_backward(15);
    turn_left(45);
    move_left(7);
    land();
    disconnect();
    return 0;
}

/* Function Definitions */
void connect_to_drone() {
    printf("Connecting to drone...\n");
}

void take_off() {
    printf("Taking off...\n");
}

void land() {
    printf("Landing...\n");
}

void move_forward(int distance) {
    printf("Moving forward %d meters...\n", distance);
}

void move_backward(int distance) {
    printf("Moving backward %d meters...\n", distance);
}

void move_left(int distance) {
    printf("Moving left %d meters...\n", distance);
}

void move_right(int distance) {
    printf("Moving right %d meters...\n", distance);
}

void turn_left(int degrees) {
    printf("Turning left %d degrees...\n", degrees);
}

void turn_right(int degrees) {
    printf("Turning right %d degrees...\n", degrees);
}

void disconnect() {
    printf("Disconnecting from drone...\n");
}