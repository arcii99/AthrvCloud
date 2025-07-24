//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>

// function prototype for the recursive function
void flyDrone(int distance);

int main() {
    int distance;
    printf("Enter the distance (in meters) to fly the drone: ");
    scanf("%d", &distance);
    flyDrone(distance); // call to recursive function
    return 0;
}

void flyDrone(int distance) {
    // base case
    if (distance <= 0) {
        printf("Drone has reached the destination!\n");
        return;
    }
    else {
        printf("Flying drone %d meters...\n", distance);
        flyDrone(distance - 10); // recursive call
    }
}