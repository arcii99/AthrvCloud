//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 10
#define ELEVATOR_SPEED 3
#define MAX_SIMULATION_TIME 60

// Function to simulate the elevator movement
void simulateElevator(bool floors[MAX_FLOORS][MAX_CAPACITY]) {
    int floor = 0;
    bool directionUp = true;
    int time = 0;
    printf("Elevator starts at floor 0\n");

    while(time < MAX_SIMULATION_TIME) {
        // Check if there are any passengers on the current floor
        bool passengersOnFloor = false;
        for(int i = 0; i < MAX_CAPACITY; i++) {
            if(floors[floor][i]) {
                passengersOnFloor = true;
                break;
            }
        }

        // If there are passengers, open the doors
        if(passengersOnFloor) {
            printf("Elevator doors opened on floor %d\n", floor);
            // Let the passengers in
            for(int i = 0; i < MAX_CAPACITY; i++) {
                if(floors[floor][i]) {
                    printf("Passenger %d entered the elevator on floor %d\n", i+1, floor);
                    floors[floor][i] = false;
                }
            }
        }

        // Check if all the passengers have reached their destinations
        bool passengersReachedDestination = true;
        for(int i = 0; i < MAX_FLOORS; i++) {
            for(int j = 0; j < MAX_CAPACITY; j++) {
                if(floors[i][j]) {
                    passengersReachedDestination = false;
                    break;
                }
            }
            if(!passengersReachedDestination) {
                break;
            }
        }

        // If all the passengers have reached their destinations, end the simulation
        if(passengersReachedDestination) {
            break;
        }

        // Move the elevator to the next floor
        if(directionUp) {
            if(floor < MAX_FLOORS - 1) {
                floor++;
                printf("Elevator moved up to floor %d\n", floor);
            } else {
                printf("Elevator reached the top floor and is going down\n");
                directionUp = false;
                floor--;
                printf("Elevator moved down to floor %d\n", floor);
            }
        } else {
            if(floor > 0) {
                floor--;
                printf("Elevator moved down to floor %d\n", floor);
            } else {
                printf("Elevator reached the bottom floor and is going up\n");
                directionUp = true;
                floor++;
                printf("Elevator moved up to floor %d\n", floor);
            }
        }

        time += ELEVATOR_SPEED;
    }
}

int main() {
    srand(time(NULL));

    // Initialize the floors array
    bool floors[MAX_FLOORS][MAX_CAPACITY];
    for(int i = 0; i < MAX_FLOORS; i++) {
        for(int j = 0; j < MAX_CAPACITY; j++) {
            floors[i][j] = false;
        }
    }

    // Generate random passengers
    for(int t = 0; t < MAX_SIMULATION_TIME; t++) {
        int passengersOnGroundFloor = rand() % 10;
        for(int i = 0; i < passengersOnGroundFloor; i++) {
            int destination = rand() % MAX_FLOORS;
            for(int j = 0; j < MAX_CAPACITY; j++) {
                if(!floors[0][j]) {
                    floors[0][j] = true;
                    printf("Passenger %d on floor 0 wants to go to floor %d\n", j+1, destination);
                    break;
                }
            }
        }
    }

    // Simulate the elevator movement
    simulateElevator(floors);

    return 0;
}