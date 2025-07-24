//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: curious
/*
 * Author: Chatbot
 * Description: A curious simulation of an elevator using C programming language.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLOOR_COUNT 10

typedef struct elevator_t {
    int current_floor;
    int direction;
} elevator_t;

typedef struct button_t {
    bool is_pressed;
} button_t;

typedef struct floor_t {
    button_t up_button;
    button_t down_button;
} floor_t;

elevator_t elevator;
floor_t floors[FLOOR_COUNT];

void print_floor_options() {
    printf("\nPlease select an option:\n");
    printf("1) Press the up button.\n");
    printf("2) Press the down button.\n");
    printf("3) Quit the program.\n");
}

void handle_button_press(int floor_number, int button_type) {
    if (button_type == 1) {
        floors[floor_number].up_button.is_pressed = true;
    } else {
        floors[floor_number].down_button.is_pressed = true;
    }
}

void simulate_elevator() {
    while (true) {
        int destination_floor = -1;
        int distance_to_destination = FLOOR_COUNT + 1;

        for (int i = 0; i < FLOOR_COUNT; i++) {
            if (floors[i].up_button.is_pressed && i > elevator.current_floor) {
                int distance = i - elevator.current_floor;
                if (distance < distance_to_destination) {
                    distance_to_destination = distance;
                    destination_floor = i;
                }
            }

            if (floors[i].down_button.is_pressed && i < elevator.current_floor) {
                int distance = elevator.current_floor - i;
                if (distance < distance_to_destination) {
                    distance_to_destination = distance;
                    destination_floor = i;
                }
            }
        }

        if (destination_floor != -1) {
            printf("Elevator moving from floor %d to floor %d.\n", elevator.current_floor, destination_floor);
            elevator.current_floor = destination_floor;
            printf("Elevator arrived at floor %d.\n", elevator.current_floor);
            floors[destination_floor].up_button.is_pressed = false;
            floors[destination_floor].down_button.is_pressed = false;
        } else {
            printf("Elevator is idle at floor %d.\n", elevator.current_floor);
            break;
        }
    }
}

int main() {
    elevator.current_floor = 0;
    printf("Welcome to the elevator simulator!\n");

    while (true) {
        printf("\nYou are currently on floor %d.\n", elevator.current_floor);
        printf("Which floor would you like to go to?\n");

        for (int i = 0; i < FLOOR_COUNT; i++) {
            if (i == elevator.current_floor) {
                continue;
            }

            printf("%d) Floor %d\n", i + 1, i);
        }

        printf("%d) Quit the program.\n", FLOOR_COUNT + 1);

        int selection;
        scanf("%d", &selection);

        if (selection <= FLOOR_COUNT) {
            int floor_number = selection - 1;
            print_floor_options();

            int button_selection;
            scanf("%d", &button_selection);

            handle_button_press(floor_number, button_selection);

            simulate_elevator();
        } else {
            printf("Thank you for using the elevator simulator! Goodbye.\n");
            exit(0);
        }
    }

    return 0;
}