//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include<stdio.h>

void main() {
    int currentLocation[2] = {0,0}; //initial coordinates
    int destination[2] = {10,10}; //destination coordinates
    char direction[4][10] = {"North", "East", "South", "West"}; //direction array
    int currentDirection = 0; //current direction initally set to North
    printf("GPS Navigation System Simulation.\n\n");
    printf("You are currently at (%d,%d)\n", currentLocation[0], currentLocation[1]);
    printf("Enter destination coordinates: ");
    scanf("%d,%d", &destination[0], &destination[1]);
    printf("Destination set to (%d,%d)\n", destination[0],destination[1]);
    //loop until current location and destination coordinates are same
    while(currentLocation[0] != destination[0] || currentLocation[1] != destination[1]) {
        //check which direction to move in
        if(destination[0] > currentLocation[0]) {
            printf("Move %s.\n", direction[1]);
            currentLocation[0]++;
            currentDirection = 1;
        }
        else if(destination[0] < currentLocation[0]) {
            printf("Move %s.\n", direction[3]);
            currentLocation[0]--;
            currentDirection = 3;
        }
        else if(destination[1] > currentLocation[1]) {
            printf("Move %s.\n", direction[0]);
            currentLocation[1]++;
            currentDirection = 0;
        }
        else if(destination[1] < currentLocation[1]) {
            printf("Move %s.\n", direction[2]);
            currentLocation[1]--;
            currentDirection = 2;
        }
        printf("You are currently at (%d,%d) facing %s.\n", currentLocation[0], currentLocation[1], direction[currentDirection]);
    }
    printf("\nDestination reached. Have a nice day!\n");
}