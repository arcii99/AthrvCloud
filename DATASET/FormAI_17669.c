//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>

void goUp(int currentFloor, int destinationFloor)
{
    if(currentFloor == destinationFloor)
    {
        printf("Elevator reached floor %d\n", currentFloor);
        return;
    }

    printf("Elevator is moving up, passing floor %d\n", currentFloor);
    goUp(currentFloor + 1, destinationFloor);
}

void goDown(int currentFloor, int destinationFloor)
{
    if(currentFloor == destinationFloor)
    {
        printf("Elevator reached floor %d\n", currentFloor);
        return;
    }

    printf("Elevator is moving down, passing floor %d\n", currentFloor);
    goDown(currentFloor - 1, destinationFloor);
}

int main()
{
    int currentFloor = 1;
    int destinationFloor;

    printf("Enter destination floor: ");
    scanf("%d", &destinationFloor);

    if(destinationFloor > currentFloor)
    {
        goUp(currentFloor, destinationFloor);
    }
    else if(destinationFloor < currentFloor)
    {
        goDown(currentFloor, destinationFloor);
    }
    else
    {
        printf("Elevator is already on the destination floor\n");
    }

    return 0;
}