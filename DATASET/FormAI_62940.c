//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

int main() {
    int total_floors, current_floor, destination, floor_request;
    bool is_up_direction;

    printf("Enter the number of floors in the building: ");
    scanf("%d", &total_floors);

    printf("Enter the current floor: ");
    scanf("%d", &current_floor);

    printf("Enter the direction of travel (0 for down, 1 for up): ");
    scanf("%d", &is_up_direction);

    printf("Enter the floor number to go to: ");
    scanf("%d", &destination);

    if (destination == current_floor) {
        printf("You are already at floor number %d\n", current_floor);
        return 0;
    }

    floor_request = destination > current_floor ? 1 : -1;

    printf("Elevator coming...\n");

    while (current_floor != destination) {
        current_floor += floor_request;

        if (current_floor == total_floors + 1) {
            current_floor = total_floors;
            floor_request = -1;
        } else if (current_floor == 0) {
            current_floor = 1;
            floor_request = 1;
        }

        printf("Elevator at floor number %d\n", current_floor);
    }

    printf("You have reached your destination at floor number %d\n", current_floor);

    return 0;
}