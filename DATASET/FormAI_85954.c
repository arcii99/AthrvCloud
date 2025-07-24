//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>

// function to simulate pressing a button
void pressButton(char *button)
{
    printf("Pressed %s button.\n", button);
}

// recursive function to control vehicle movements
void controlVehicle(int distance)
{
    if (distance <= 0) {
        return; // base case
    }

    printf("Vehicle moves forward %d inches.\n", distance);
    controlVehicle(distance - 10); // recursive call

    // after returning from recursive call, simulate pressing back button to move vehicle back same distance
    printf("Vehicle moves back %d inches.\n", distance);
    pressButton("Back");
}

int main()
{
    printf("Remote Control Vehicle Simulation\n\n");
    controlVehicle(50); // starting distance
    return 0;
}