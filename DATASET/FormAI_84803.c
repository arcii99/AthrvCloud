//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>

int main() {
    
    int speed = 0;
    int distance_to_travel = 50;
    
    printf("How fast do you want to travel? (Enter a number between 1 and 10): ");
    scanf("%d", &speed);
    
    if(speed < 1 || speed > 10) {
        printf("Invalid speed entry. Program exiting.\n");
        return 0;
    }
    
    printf("Travelling at speed %d.\n", speed);
    
    while(distance_to_travel > 0) {
        printf("Distance to travel: %d\n", distance_to_travel);
        distance_to_travel -= speed;
        main(); // recursive call
    }
    
    printf("Arrived at destination!\n");
    return 0;
}