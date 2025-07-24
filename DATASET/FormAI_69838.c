//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define ELEVATOR_SPEED 1 // in seconds
#define DOORS_OPEN_TIME 3 // in seconds

int current_floor = 0;
bool doors_open = false;

void open_doors() {
    doors_open = true;
    printf("Doors opening...\n");
    sleep(DOORS_OPEN_TIME);
    printf("Doors closing...\n");
    doors_open = false;
}

void move_elevator(int floor) {
    int direction = (floor > current_floor) ? 1 : -1;
    printf("Going ");
    while(current_floor != floor) {
        current_floor += direction;
        printf("%d... ", current_floor);
        sleep(ELEVATOR_SPEED);
    }
    printf("\n");
    open_doors();
}

int main() {
    int floors[] = {2, 5, 8, 0, 7, 1};
    int num_floors = sizeof(floors) / sizeof(floors[0]);

    printf("Elevator starting on floor %d.\n", current_floor);
    sleep(1);

    for(int i = 0; i < num_floors; i++) {
        move_elevator(floors[i]);
    }

    printf("Elevator returning to ground floor.\n");
    move_elevator(0);

    printf("Elevator simulation complete.\n");

    return 0;
}