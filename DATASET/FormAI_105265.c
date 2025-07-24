//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define MAX_PEOPLE 10
#define ELEVATOR_CAPACITY 5

int main() {
    int currentFloor = 1, nextFloor, peopleInElevator = 0, peopleWaiting = 0, peopleArrived = 0, i;
    int peopleOnEachFloor[FLOORS] = {0};
    int elevator[FLOORS][ELEVATOR_CAPACITY] = {0};
    srand(time(NULL));
    
    printf("Welcome to the Funny Elevator Simulator!\n");
    printf("Let's see if you can successfully transport everyone to their destination!\n\n");
    
    while (peopleArrived < MAX_PEOPLE) {
        // Check if anyone has arrived at their destination
        for (i = 0; i < ELEVATOR_CAPACITY; i++) {
            if (elevator[currentFloor-1][i] == currentFloor) {
                elevator[currentFloor-1][i] = 0;
                peopleInElevator--;
                peopleArrived++;
                printf("Person %d has arrived at their destination on floor %d!\n\n", i+1, currentFloor);
            }
        }
        
        // Check if anyone is waiting on current floor
        if (peopleOnEachFloor[currentFloor-1] > 0) {
            printf("%d person(s) are waiting on floor %d!\n", peopleOnEachFloor[currentFloor-1], currentFloor);
            if ((ELEVATOR_CAPACITY - peopleInElevator) >= peopleOnEachFloor[currentFloor-1]) {
                for (i = 0; i < peopleOnEachFloor[currentFloor-1]; i++) {
                    int remainingCapacity = ELEVATOR_CAPACITY - peopleInElevator;
                    if (remainingCapacity > 0) {
                        elevator[currentFloor-1][i+peopleInElevator] = currentFloor;
                        peopleWaiting--;
                        peopleInElevator++;
                        printf("Person %d has entered the elevator on floor %d!\n", i+1, currentFloor);
                    }
                }
            } else {
                printf("The elevator is full, cannot pick up everyone on floor %d!\n", currentFloor);
            }
        }
        
        // Determine next floor
        if (peopleInElevator == 0) {
            // Pick a random floor if elevator is empty
            nextFloor = (rand() % FLOORS) + 1;
        } else {
            // Check which floor people are going to and pick the closest one
            int closestDistance = FLOORS;
            for (i = 0; i < ELEVATOR_CAPACITY; i++) {
                if (elevator[currentFloor-1][i] != 0) {
                    int distance = abs(elevator[currentFloor-1][i] - currentFloor);
                    if (distance < closestDistance) {
                        closestDistance = distance;
                        nextFloor = elevator[currentFloor-1][i];
                    }
                }
            }
        }
        
        printf("\nThe elevator is currently on floor %d and going to floor %d!\n", currentFloor, nextFloor);
        currentFloor = nextFloor;
        
        // Add people randomly to each floor
        for (i = 0; i < FLOORS; i++) {
            if (peopleOnEachFloor[i] == 0 && rand() % 2 == 1) {
                peopleOnEachFloor[i] = rand() % 5;
                printf("%d person(s) have arrived on floor %d!\n", peopleOnEachFloor[i], i+1);
                peopleWaiting += peopleOnEachFloor[i];
            }
        }
        
        printf("\n\n");
    }
    
    printf("Congratulations, you have successfully transported everyone to their destination!\n");
    return 0;
}