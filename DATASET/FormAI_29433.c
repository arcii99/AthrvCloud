//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time

    int maxFloor = 7; // max number of floors in the castle
    int elevatorFloor = 1; // starting floor of the elevator
    int targetFloor = elevatorFloor; // floor where the elevator is heading
    int elevatorDirection = 0; // 0 for stationary, 1 for up, -1 for down
    int elevatorOccupancy = 0; // number of people in the elevator
    int maxOccupancy = 8; // max capacity of the elevator

    printf("Welcome to the medieval castle elevator!\n");

    while(1) {
        printf("Elevator is on floor %d\n", elevatorFloor);
        
        if(elevatorOccupancy == 0) { // if elevator is empty, look for people to pick up
            int people = rand() % 6; // randomly determine number of people on current floor
            if(people != 0) {
                printf("Elevator door opens. %d person(s) get in.\n", people);
                elevatorOccupancy += people;
                targetFloor = rand() % maxFloor + 1; // randomly choose a floor to go to
                if(targetFloor > elevatorFloor) {
                    elevatorDirection = 1;
                }
                else if(targetFloor < elevatorFloor) {
                    elevatorDirection = -1;
                }
            }
        }
        else { // if elevator has people, move towards target floor
            printf("Elevator is heading towards floor %d\n", targetFloor);
            if(elevatorFloor == targetFloor) { // elevator has reached target floor
                printf("Elevator door opens. %d person(s) get out.\n", elevatorOccupancy);
                elevatorOccupancy = 0;
                elevatorDirection = 0;
            }
            else if(elevatorDirection == 1) { // elevator is moving up
                elevatorFloor++;
            }
            else if(elevatorDirection == -1) { // elevator is moving down
                elevatorFloor--;
            }
        }

        // random delay before next loop iteration
        int delay = rand() % 3 + 1;
        printf("Waiting for %d seconds.\n\n", delay);
        sleep(delay);
    }

    return 0;
}