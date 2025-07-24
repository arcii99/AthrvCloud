//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Sherlock Holmes
#include <stdio.h>

int current_floor = 1;
int destination_floor = 0;

void move_elevator() {
    printf("The elevator is now moving from floor %d to floor %d.\n", current_floor, destination_floor);
    current_floor = destination_floor;
}

void open_doors() {
    printf("The elevator doors are now opening on floor %d.\n", current_floor);
}

void close_doors() {
    printf("The elevator doors are now closing.\n");
}

void request_floor() {
    printf("Please enter the floor you would like to go to: ");
    scanf("%d", &destination_floor);
}

int main() {
    printf("Welcome to the Sherlock Holmes Elevator Simulation!\n");
    printf("The elevator is currently on the ground floor.\n");
    printf("You can request a floor by pressing the corresponding button.\n");
  
    while (1) {
        if (destination_floor == current_floor) {
            open_doors();
            request_floor();
            close_doors();
            move_elevator();
        } else if (destination_floor > current_floor) {
            move_elevator();
        } else {
            current_floor--;
            move_elevator();
        }
    }

    return 0;
}