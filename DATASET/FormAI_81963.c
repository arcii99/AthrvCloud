//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ELEVATOR_CAPACITY 10
#define ELEVATOR_FLOORS 10

int main()
{
    srand(time(NULL)); // seed the random number generator
    int elevator[ELEVATOR_CAPACITY]; // array representing the elevator
    int currentFloor = 1; // initialize the elevator to be on the first floor
    int numPeople = 0; // initialize the number of people inside the elevator to be 0
    bool elevatorGoingUp = true; // initialize the direction of the elevator to be up

    // infinite loop to simulate the elevator running indefinitely
    while (true)
    {
        // check if there are people on the current floor who want to go up
        if (elevatorGoingUp)
        {
            int numPeopleWaiting = rand() % (ELEVATOR_CAPACITY - numPeople + 1); // randomly choose a number of people to add to the elevator
            printf("%d people want to go up on floor %d\n", numPeopleWaiting, currentFloor);

            // add as many people as possible to the elevator
            int i;
            for (i = 0; i < numPeopleWaiting && numPeople < ELEVATOR_CAPACITY; i++)
            {
                elevator[numPeople] = 1; // add the person to the elevator
                numPeople++; // increment the number of people inside the elevator
            }
        }
        // check if there are people on the current floor who want to go down
        else
        {
            int numPeopleWaiting = rand() % (ELEVATOR_CAPACITY - numPeople + 1); // randomly choose a number of people to add to the elevator
            printf("%d people want to go down on floor %d\n", numPeopleWaiting, currentFloor);

            // add as many people as possible to the elevator
            int i;
            for (i = 0; i < numPeopleWaiting && numPeople < ELEVATOR_CAPACITY; i++)
            {
                elevator[numPeople] = -1; // add the person to the elevator
                numPeople++; // increment the number of people inside the elevator
            }
        }

        // check if the elevator is full or if there are no more people waiting
        if (numPeople == ELEVATOR_CAPACITY || (elevatorGoingUp && currentFloor == ELEVATOR_FLOORS) || (!elevatorGoingUp && currentFloor == 1))
        {
            printf("The elevator is full. Going to %s\n", elevatorGoingUp ? "the top" : "the bottom");
            // empty the elevator and reset numPeople to 0
            int i;
            for (i = 0; i < ELEVATOR_CAPACITY; i++)
            {
                elevator[i] = 0;
            }
            numPeople = 0;
            // change the direction of the elevator
            elevatorGoingUp = !elevatorGoingUp;
        }

        // move the elevator to the next floor
        currentFloor += elevatorGoingUp ? 1 : -1;
        printf("Elevator is now on floor %d\n", currentFloor);
    }

    return 0;
}