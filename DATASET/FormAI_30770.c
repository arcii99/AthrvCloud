//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>

void moveUp(int floor, int destination);
void moveDown(int floor, int destination);

int main()
{
    int currentFloor, destinationFloor;
    printf("Enter current floor: ");
    scanf("%d", &currentFloor);
    printf("Enter destination floor: ");
    scanf("%d", &destinationFloor);
    
    if(currentFloor == destinationFloor)
    {
        printf("Elevator is already on the destination floor.");
        return 0;
    }
    
    if(destinationFloor > currentFloor)
        moveUp(currentFloor, destinationFloor);
    else
        moveDown(currentFloor, destinationFloor);
        
    return 0;
}

void moveUp(int floor, int destination)
{
    printf("Elevator is on floor %d\n", floor);
    if(floor == destination)
    {
        printf("Elevator has reached the destination floor.\n");
        return;
    }
    moveUp(floor+1, destination);
}

void moveDown(int floor, int destination)
{
    printf("Elevator is on floor %d\n", floor);
    if(floor == destination)
    {
        printf("Elevator has reached the destination floor.\n");
        return;
    }
    moveDown(floor-1, destination);
}