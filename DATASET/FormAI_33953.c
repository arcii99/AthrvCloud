//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOORS 10

int num_floors = MAX_FLOORS;
int current_floor = 1;
bool going_up = true;

int main() {
    printf("Welcome to the Elevator Simulation!\n");
    printf("Please enter the number of floors in the building (maximum %d): ", MAX_FLOORS);
    scanf("%d", &num_floors);
    printf("Great! This building has %d floors.\n", num_floors);

    while (true) {
        printf("\n[Elevator on floor %d]\n", current_floor);
        printf("Where would you like to go? (Please enter floor number or 'q' to quit)\n");
        char input[10];
        scanf("%s", input);

        if (input[0] == 'q') {
            printf("\nThank you for using the Elevator Simulation. Have a nice day!\n");
            break;
        } else {
            int destination = atoi(input);
            if (destination > num_floors || destination < 1) {
                printf("\nThat is not a valid floor number.\n");
            } else {
                printf("\nGoing %s to floor %d...\n", (destination > current_floor) ? "up" : "down", destination);
                while (current_floor != destination) {
                    if (going_up) {
                        current_floor++;
                    } else {
                        current_floor--;
                    }
                    printf("Now on floor %d.\n", current_floor);
                }
                printf("You have arrived at your destination.\n");
                going_up = !going_up;
            }
        }
    }

    return 0;
}