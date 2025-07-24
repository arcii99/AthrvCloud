//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int floor;
    bool is_direction_up;
} Request;

typedef struct {
    bool is_direction_up;
    int current_floor;
    bool is_open;
    int passengers;
} Elevator;

int main() {
    srand((unsigned int)time(NULL));
    Elevator elevator = {true, 0, false, 0};
    Request requests[MAX_FLOORS] = {0};
    bool is_request_made = false;

    // Print welcome message
    printf("Welcome to the Happy Elevator Simulation!\n");

    while (true) {
        // Check if elevator is at capacity
        if (elevator.passengers == ELEVATOR_CAPACITY) {
            printf("Elevator is at full capacity! Moving to next floor...\n");
            elevator.current_floor += elevator.is_direction_up ? 1 : -1;
            elevator.is_open = false;
            elevator.is_direction_up = elevator.current_floor == MAX_FLOORS - 1 ? false :
                                       elevator.current_floor == 0 ? true :
                                       elevator.is_direction_up;
            elevator.passengers = 0;
        }
        // Check if elevator is empty and there are pending requests
        else if (elevator.passengers == 0 && is_request_made) {
            elevator.is_direction_up = requests[0].floor > elevator.current_floor ? true :
                                       requests[0].floor < elevator.current_floor ? false :
                                       elevator.is_direction_up;
            printf("Elevator is empty! Going to handle pending request...\n");
            elevator.is_open = true;
            elevator.current_floor = requests[0].floor;
            is_request_made = false;
        }
        // Check if someone has requested to enter the elevator at current floor
        else if (requests[elevator.current_floor].is_direction_up == elevator.is_direction_up) {
            if (elevator.is_open && elevator.passengers < ELEVATOR_CAPACITY) {
                elevator.passengers++;
                requests[elevator.current_floor].is_direction_up = !elevator.is_direction_up;
                printf("Passenger entered the elevator on floor %d! Current passengers = %d\n",
                       elevator.current_floor, elevator.passengers);
            }
            else if (!elevator.is_open) {
                printf("Elevator door is closed on floor %d! Moving to next floor...\n", elevator.current_floor);
                elevator.current_floor += elevator.is_direction_up ? 1 : -1;
                elevator.is_direction_up = elevator.current_floor == MAX_FLOORS - 1 ? false :
                                           elevator.current_floor == 0 ? true :
                                           elevator.is_direction_up;
                elevator.is_open = true;
            }
        }
        // Check if someone has requested to exit the elevator at current floor
        else if (requests[elevator.current_floor].is_direction_up == !elevator.is_direction_up) {
            if (elevator.is_open && elevator.passengers > 0) {
                elevator.passengers--;
                requests[elevator.current_floor].is_direction_up = elevator.is_direction_up;
                printf("Passenger exited the elevator on floor %d! Current passengers = %d\n",
                       elevator.current_floor, elevator.passengers);
            }
            else if (!elevator.is_open) {
                printf("Elevator door is closed on floor %d! Moving to next floor...\n", elevator.current_floor);
                elevator.current_floor += elevator.is_direction_up ? 1 : -1;
                elevator.is_direction_up = elevator.current_floor == MAX_FLOORS - 1 ? false :
                                           elevator.current_floor == 0 ? true :
                                           elevator.is_direction_up;
                elevator.is_open = true;
            }
        }
        // Check for new requests on other floors
        else {
            int i, direction_count = 0;
            for (i = 0; i < MAX_FLOORS; i++) {
                if (requests[i].is_direction_up) {
                    direction_count++;
                }
            }
            if (elevator.is_direction_up && direction_count > 0) {
                printf("Moving to next floor...\n");
                elevator.current_floor++;
                if (requests[elevator.current_floor].is_direction_up) {
                    printf("Stopping at floor %d for request. Door opening...\n", elevator.current_floor);
                    elevator.is_open = true;
                }
            }
            else if (!elevator.is_direction_up && MAX_FLOORS - direction_count > 0) {
                printf("Moving to next floor...\n");
                elevator.current_floor--;
                if (requests[elevator.current_floor].is_direction_up == false) {
                    printf("Stopping at floor %d for request. Door opening...\n", elevator.current_floor);
                    elevator.is_open = true;
                }
            }
            else {
                printf("No requests made. Elevator is waiting...\n");
            }
        }

        // Make random requests from random floors
        if (rand() % 2) {
            Request r = {rand() % MAX_FLOORS, rand() % 2 == 0};
            requests[r.floor] = r;
            is_request_made = true;
            printf("New request made! Direction: %s, Floor: %d\n",
                   r.is_direction_up ? "up" : "down", r.floor);
        }
        
        // Pause for 1 second to simulate time passing between floors
        sleep(1);
    }

    return 0;
}