//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define MAX_PEOPLE 20

int main(void) {
    int currentFloor = 1;
    int peopleOnBoard = 0;
    int peopleWaiting[FLOORS] = {0};
    int destination[FLOORS] = {0};
    int totalPeople = 0;
    int totalFloorsTraveled = 0;
    int currentStatus = 0; // 0 = idle, 1 = going up, -1 = going down
    srand(time(0));
    
    printf("Starting elevator simulation...\n");
    
    while(1) {
        //Check if there are people waiting on the current floor
        if(peopleWaiting[currentFloor-1] != 0) {
            int numPeople = peopleWaiting[currentFloor-1];
            for(int i=0; i<numPeople; i++) {
                if(peopleOnBoard < MAX_PEOPLE) {
                    peopleOnBoard++;
                    destination[currentFloor-1] = rand() % FLOORS + 1;
                    printf("Person %d boarded at floor %d, heading to floor %d\n", totalPeople+1, currentFloor, destination[currentFloor-1]);
                    totalPeople++;
                } else {
                    printf("Elevator is full. Person %d on floor %d has to wait.\n", i+1, currentFloor);
                }
            }
            peopleWaiting[currentFloor-1] = 0; // Clear the waiting array for that floor
        }
        
        // Move elevator to its destination
        if(currentStatus == 1) { // Elevator is going up
            if(destination[currentFloor-1] > currentFloor) {
                currentFloor++;
                totalFloorsTraveled++;
                printf("Elevator going up, now on floor %d.\n", currentFloor);
            } else if(destination[currentFloor-1] < currentFloor) {
                currentStatus = -1; // Reverse direction
            } else {
                printf("Elevator arrived at floor %d, people getting off...\n", currentFloor);
                peopleOnBoard = 0; // Clear people on board array
                destination[currentFloor-1] = 0; // Clear destination array for that floor
            }
        } else if(currentStatus == -1) { // Elevator is going down
            if(currentFloor > 1) {
                currentFloor--;
                totalFloorsTraveled++;
                printf("Elevator going down, now on floor %d.\n", currentFloor);
            } else if(destination[currentFloor-1] != 0) {
                currentStatus = 1; // Reverse direction
            } else {
                currentStatus = 0; // Reached ground floor and no more destinations, idle
            }
        } else { // Elevator is idle
            int peopleWaitingTotal = 0;
            for(int i=0; i<FLOORS; i++) {
                peopleWaitingTotal += peopleWaiting[i];
            }
            if(peopleWaitingTotal > 0) {
                for(int i=0; i<FLOORS; i++) {
                    if(peopleWaiting[i] != 0) {
                        destination[i] = rand() % FLOORS + 1;
                        printf("Elevator picking up people from floor %d, heading to floor %d\n", i+1, destination[i]);
                        currentStatus = (destination[i] > currentFloor) ? 1 : -1; // Set direction
                        break; // Only pick up from 1 floor at a time
                    }
                }
            } else {
                printf("Idle...\n");
                break; // End the simulation loop once all people have reached their destination
            }
        }
    }
    
    printf("Elevator simulation completed. Total floors traveled: %d.\n", totalFloorsTraveled);
    
    return 0;
}