//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#define MAX_FLOORS 10
#define MAX_PEOPLE 5

int main() {
    //Initialize variables
    int elevatorPosition = 1;
    int nPeople = 0;
    int currentFloor = 1;
    int destination[MAX_PEOPLE];
    int peopleOnFloor[MAX_FLOORS] = { 0 };

    printf("Elevator Simulation starting...\n");
    //Loop until all people have reached their destination
    while (nPeople < MAX_PEOPLE) {
        //Check if anyone is waiting on current floor
        if (peopleOnFloor[currentFloor-1] > 0) {
            //Add people to elevator and update destination floors
            for (int i = 0; i < peopleOnFloor[currentFloor-1]; i++) {
                if (nPeople < MAX_PEOPLE) {
                    destination[nPeople] = rand() % MAX_FLOORS + 1;
                    printf("Person %d has entered the elevator on floor %d. Destination: Floor %d\n", 
                            nPeople+1, currentFloor, destination[nPeople]);
                    nPeople++;
                }
            }
            //Remove people from current floor
            peopleOnFloor[currentFloor-1] = 0;
        }
        //Determine direction of elevator movement
        int direction = 0;
        if (elevatorPosition > currentFloor) {
            direction = -1;
        } else if (elevatorPosition < currentFloor) {
            direction = 1;
        }
        //Move elevator to next floor
        elevatorPosition += direction;
        printf("Elevator moving from Floor %d to Floor %d\n", currentFloor, elevatorPosition);
        currentFloor = elevatorPosition;
        //Check if anyone has reached their destination
        int remainingPeople = nPeople;
        for (int i = 0; i < nPeople; i++) {
            if (destination[i] == currentFloor) {
                printf("Person %d has exited the elevator on floor %d\n", i+1, currentFloor);
                remainingPeople--;
            } else {
                destination[i-direction] = destination[i];
            }
        }
        nPeople = remainingPeople;
        //Check if anyone is waiting on new floor
        if (peopleOnFloor[currentFloor-1] > 0) {
            //Add people to elevator and update destination floors
            for (int i = 0; i < peopleOnFloor[currentFloor-1]; i++) {
                if (nPeople < MAX_PEOPLE) {
                    destination[nPeople] = rand() % MAX_FLOORS + 1;
                    printf("Person %d has entered the elevator on floor %d. Destination: Floor %d\n", 
                            nPeople+1, currentFloor, destination[nPeople]);
                    nPeople++;
                }
            }
            //Remove people from current floor
            peopleOnFloor[currentFloor-1] = 0;
        }
    }
    printf("All people have reached their destination.\n");
    return 0;
}