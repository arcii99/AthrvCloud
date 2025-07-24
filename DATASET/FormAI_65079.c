//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLOORS 10

void print_elevator(bool floors[], int current_floor) {
    for (int i = FLOORS-1; i >= 0; i--) {
        if (i == current_floor) {
            printf("[E] ");
        } else {
            if (floors[i]) {
                printf("[*] ");
            } else {
                printf("[ ] ");
            }
        }
    }
    printf("\n");
}

int main() {

    bool floors[FLOORS] = {false};  // All floors are initially empty
    int current_floor = 0;          // Elevator starts at the ground floor
    int destination_floor = 0;

    while (true) {

        print_elevator(floors, current_floor);

        printf("Enter destination floor (0-%d): ", FLOORS-1);
        scanf("%d", &destination_floor);

        if (destination_floor == current_floor) {
            printf("Elevator is already on that floor.\n");
            continue;
        }

        if (destination_floor < 0 || destination_floor >= FLOORS) {
            printf("Invalid floor.\n");
            continue;
        }

        printf("Elevator going to floor %d.\n", destination_floor);

        while (current_floor != destination_floor) {

            printf("Elevator at floor %d.\n", current_floor);

            if (floors[current_floor]) {
                printf("People getting off at floor %d.\n", current_floor);
                floors[current_floor] = false;
            }

            if (current_floor < destination_floor) {
                current_floor++;
            } else {
                current_floor--;
            }
        }

        printf("Elevator at floor %d.\n", current_floor);
        printf("People getting off at floor %d.\n", current_floor);
        floors[current_floor] = false;

        print_elevator(floors, current_floor);

        printf("Continue? (y/n)");
        char answer;
        scanf(" %c", &answer);
        if (answer != 'y' && answer != 'Y') {
            printf("Exiting.\n");
            break;
        }
    }

    return 0;
}