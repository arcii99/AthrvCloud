//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>

void send_elevator(int floor) {
    printf("Elevator called to floor %d\n", floor);
}

void move_elevator(int start_floor, int end_floor) {
    printf("Moving elevator from floor %d to floor %d\n", start_floor, end_floor);
    printf("Elevator has arrived at floor %d\n", end_floor);
}

int main() {
    int current_floor = 1;
    int destination_floor;
    while (1) {
        printf("Current floor: %d\n", current_floor);
        printf("Enter destination floor: ");
        scanf("%d", &destination_floor);
        if (destination_floor < 1 || destination_floor > 10) {
            printf("Invalid floor number. Please select a floor between 1 and 10.\n");
            continue;
        }
        if (destination_floor == current_floor) {
            printf("Elevator is already on floor %d\n", current_floor);
            continue;
        }
        send_elevator(destination_floor);
        move_elevator(current_floor, destination_floor);
        current_floor = destination_floor;
    }
    return 0;
}