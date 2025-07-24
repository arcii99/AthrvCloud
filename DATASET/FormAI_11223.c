//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FLOOR_MAX 5   // number of floors
#define ELEVATOR_CAPACITY 10    // max number of people in elevator
#define FLOOR_DISABLED -1   // Status indicating that the floor is not accessible by the elevator

static int current_floor = 1;
static bool is_door_open = false;
static bool is_elevator_in_operation = false;
static int number_of_people_inside_elevator = 0;
static bool mov_up = true;
static bool buttons[FLOOR_MAX]; // Floor button flag array (true if someone on that floor wants to go up, false if it wants to go down)

// Changes the elevator's direction based on the status of the floor buttons
void change_direction() {
    int i;
    bool flag = false; // true if a floor with requested operations is found
    if (current_floor == FLOOR_MAX) {
        mov_up = false;
    } else if (current_floor == 1) {
        mov_up = true;
    } else {
        if (mov_up) {
            for (i = current_floor; i < FLOOR_MAX; i++) {
                if (buttons[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                for (i = current_floor - 1; i >= 1; i--) {
                    if (buttons[i]) {
                        mov_up = false;
                        break;
                    }
                }
            }
        } else {
            for (i = current_floor - 2; i >= 0; i--) {
                if (buttons[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                for (i = current_floor - 1; i < FLOOR_MAX - 1; i++) {
                    if (buttons[i]) {
                        mov_up = true;
                        break;
                    }
                }
            }
        }
    }
}

// Print elevator status
void print_status() {
    system("clear"); // clear the terminal screen
    if (is_door_open) {
        printf("Door is open\n");
    } else {
        printf("Door is closed\n");
    }
    printf("Current floor is %d\n", current_floor);
    printf("Number of people inside elevator is %d\n", number_of_people_inside_elevator);
    printf("Direction: ");
    if (mov_up) {
        printf("UP\n");
    } else {
        printf("DOWN\n");
    }
    printf("Floor buttons:\n");
    int i;
    for (i = FLOOR_MAX - 1; i >= 0; i--) {
        if (buttons[i]) {
            printf("Floor %d: ON\n", i + 1);
        } else {
            printf("Floor %d: OFF\n", i + 1);
        }
    }
}

// Perform elevator operations
void operate_elevator() {
    print_status();
    if (is_door_open) { // If door is open, close it
        is_door_open = false;
        printf("Door is being closed\n");
        return;
    }
    if (number_of_people_inside_elevator == 0 && !buttons[current_floor - 1]) { // If there are no pending operations, wait for button press
        printf("Elevator is waiting...\n");
        return;
    }
    if (number_of_people_inside_elevator < ELEVATOR_CAPACITY) {
        // If there are people waiting on current floor, allow them to enter
        if (buttons[current_floor - 1]) {
            buttons[current_floor - 1] = false; // reset floor button flag
            number_of_people_inside_elevator++;
            printf("People are entering into the elevator\n");
            return;
        }
        // If there are people who want to go to a floor beyond the current floor in current direction, let them enter
        if (mov_up) {
            int i;
            for (i = current_floor; i < FLOOR_MAX; i++) {
                if (buttons[i]) {
                    number_of_people_inside_elevator++;
                    buttons[i] = false; // reset floor button flag
                    printf("People are entering into the elevator\n");
                    return;
                }
            }
        } else {
            int i;
            for (i = current_floor - 2; i >= 0; i--) {
                if (buttons[i]) {
                    number_of_people_inside_elevator++;
                    buttons[i] = false; // reset floor button flag
                    printf("People are entering into the elevator\n");
                    return;
                }
            }
        }
    }
    // If the elevator is full or no one is waiting, change direction
    change_direction();
    printf("Elevator is changing direction\n");
}

int main() {
    int i;
    is_elevator_in_operation = true;
    printf("Welcome to the Elevator Simulation Program!\n");
    printf("Press [CTRL+C] to stop the simulation\n");
    for (i = 0; i < FLOOR_MAX; i++) {
        buttons[i] = false;
    }
    while (is_elevator_in_operation) {
        operate_elevator();
        if (mov_up) {
            if (current_floor != FLOOR_MAX) {
                printf("Elevator is moving up to floor %d\n", current_floor + 1);
                current_floor++;
            }
        } else {
            if (current_floor != 1) {
                printf("Elevator is moving down to floor %d\n", current_floor - 1);
                current_floor--;
            }
        }
    }
    printf("Elevator simulation stopped!\n");
    return 0;
}