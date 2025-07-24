//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOOR 30
#define MIN_FLOOR 1

int elevator_position = 10; // starting position of elevator
int direction = 1;          // 1 is up, -1 is down
int floor_requests[MAX_FLOOR];

int get_floor_request(int floor) {
    return floor_requests[floor-1];
}

void set_floor_request(int floor, int value) {
    floor_requests[floor-1] = value;
}

void move_elevator() {
    if(elevator_position == MAX_FLOOR) {
        direction = -1;
    } else if(elevator_position == MIN_FLOOR) {
        direction = 1;
    }
    elevator_position += direction;
}

void handle_requests() {
    printf("Elevator at Floor %d\n", elevator_position);
    int floor_request = get_floor_request(elevator_position);
    if(floor_request) {
        printf("Opening Doors...\n");
        sleep(1);
        printf("Closing Doors...\n");
        set_floor_request(elevator_position, 0);
    }
}

int main() {
    printf("Welcome to the Futuristic Elevator Simulation!\n");

    int run_count = 0;
    while(run_count < 100) {
        move_elevator();
        handle_requests();
        run_count++;
        sleep(1);
    }

    printf("Simulation Complete.\n");

    return 0;
}