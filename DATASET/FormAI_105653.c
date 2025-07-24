//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
// Claude Shannon Style Elevator Simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_floors 10
#define MIN_floors 5
#define MAX_people 20
#define MIN_people 5
#define ELEVATOR_CAPACITY 12

// Function to generate random integer from minimum to maximum
int randomInt(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

// Function to display the status of the elevator
void printStatus(int floor, int direction, int people)
{
    printf("Elevator Status: Floor %d, Going %s, %d People on Board\n", floor, direction == 1 ? "Up" : "Down", people);
}

// Main Function
int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Define variables
    int floors = randomInt(MIN_floors, MAX_floors);
    int peopleCount = randomInt(MIN_people, MAX_people);
    int peopleWaiting[MAX_floors];
    for(int i = 0; i < floors; i++) peopleWaiting[i] = randomInt(0, peopleCount);

    // Initialize variables
    int currentFloor = 1;
    int direction = 1; // 1 means up, -1 means down
    int peopleOnBoard = 0;

    // Main Elevator Loop
    while(1)
    {
        // Check if elevator is at top floor
        if(currentFloor == floors)
        {
            printf("Elevator is at top floor. Going down!\n");
            direction = -1; // Change direction
        }

        // Check if elevator is at ground floor
        else if(currentFloor == 1)
        {
            printf("Elevator is at ground floor. Going up!\n");
            direction = 1; // Change direction
        }

        // Print elevator status
        printStatus(currentFloor, direction, peopleOnBoard);

        // Check if there are people waiting on current floor
        if(peopleWaiting[currentFloor - 1] > 0 && peopleOnBoard < ELEVATOR_CAPACITY)
        {
            int peopleToAdd = peopleWaiting[currentFloor - 1]; // Number of people to add to elevator
            if(peopleToAdd > ELEVATOR_CAPACITY - peopleOnBoard) peopleToAdd = ELEVATOR_CAPACITY - peopleOnBoard; // Check if there is enough space in elevator
            peopleWaiting[currentFloor - 1] -= peopleToAdd; // Update number of people waiting
            peopleOnBoard += peopleToAdd; // Add people to elevator
            printf("%d people entered the elevator on floor %d\n", peopleToAdd, currentFloor);
        }

        // Check if there are people in the elevator
        if(peopleOnBoard > 0)
        {
            int peopleToDropOff = randomInt(0, peopleOnBoard); // Number of people to drop off
            printf("%d people left the elevator on floor %d\n", peopleToDropOff, currentFloor);
            peopleOnBoard -= peopleToDropOff; // Update number of people in the elevator
        }

        // Move elevator to next floor
        currentFloor += direction;

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}