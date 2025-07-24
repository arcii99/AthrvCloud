//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define CAPACITY 8

int main() {
    int currentFloor = 0;
    int destination = 0;
    int numPassengers = 0;
    bool goingUp = true;
    bool doorsOpen = false;
    bool buttons[NUM_FLOORS] = { false };
    int passengers[NUM_FLOORS] = { 0 };
    int stops[NUM_FLOORS] = { 0 };
    
    printf("Welcome to the Elevator Simulator!\n\n");
    
    printf("There are %d floors in this building.\n", NUM_FLOORS);
    printf("The elevator can hold up to %d passengers.\n\n", CAPACITY);
    
    while(true) {
        printf("Current floor: %d\n", currentFloor);
        printf("Destination floor: %d\n", destination);
        printf("Number of passengers: %d\n", numPassengers);
        
        printf("Floor buttons: ");
        for(int i = 0; i < NUM_FLOORS; i++) {
            printf("%d ", buttons[i]);
        }
        printf("\n");
        
        printf("Passenger counts: ");
        for(int i = 0; i < NUM_FLOORS; i++) {
            printf("%d ", passengers[i]);
        }
        printf("\n");
        
        printf("Stops: ");
        for(int i = 0; i < NUM_FLOORS; i++) {
            printf("%d ", stops[i]);
        }
        printf("\n\n");
        
        // simulate passengers entering and exiting
        if(doorsOpen) {
            if(destination == currentFloor) {
                numPassengers -= stops[currentFloor];
                passengers[currentFloor] = 0;
                stops[currentFloor] = 0;
                doorsOpen = false;
                printf("Passengers exiting at floor %d...\n", currentFloor);
                printf("Doors closing...\n");
            } else if(numPassengers < CAPACITY && buttons[currentFloor]) {
                passengers[currentFloor]++;
                numPassengers++;
                stops[currentFloor]++;
                buttons[currentFloor] = false;
                printf("Passenger entering at floor %d...\n", currentFloor);
            } else {
                printf("Waiting for passengers to exit or for room to board...\n");
            }
        } else {
            if(stops[currentFloor] > 0) {
                doorsOpen = true;
                printf("Doors opening...\n");
            } else {
                int direction = goingUp ? 1 : -1;
                int nextStop = currentFloor + direction;
                if(nextStop < 0 || nextStop == NUM_FLOORS) {
                    goingUp = !goingUp;
                    direction = goingUp ? 1 : -1;
                    nextStop = currentFloor + direction;
                }
                if(stops[nextStop] > 0) {
                    destination = nextStop;
                    printf("Moving to floor %d...\n", destination);
                } else {
                    printf("Waiting for passenger input...\n");
                }
            }
        }
    }
    
    return 0;
}