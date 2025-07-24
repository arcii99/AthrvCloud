//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
/*
* GPS Navigation Simulation Program
* By: [Your Name Here]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10 // Size of the map (square)

// Function to generate random coordinates
void getRandCoords(int* x, int* y) {
    *x = rand() % MAP_SIZE;
    *y = rand() % MAP_SIZE;
}

// Function to calculate the distance between two coordinates
double getDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main() {
    srand(time(0)); // Seed random number generator with current time
    
    int startX, startY, endX, endY;
    
    // Get random starting and ending coordinates
    getRandCoords(&startX, &startY);
    getRandCoords(&endX, &endY);
    
    double distance = getDistance(startX, startY, endX, endY);
    
    printf("GPS Navigation Simulation\n");
    printf("Start Coordinates: (%d, %d)\n", startX, startY);
    printf("End Coordinates: (%d, %d)\n", endX, endY);
    printf("Distance to Destination: %.2f miles\n\n", distance);
    
    // Navigate to destination
    int x = startX, y = startY;
    while (x != endX || y != endY) {
        // Move towards destination
        if (x < endX) x++;
        else if (x > endX) x--;
        if (y < endY) y++;
        else if (y > endY) y--;

        // Print current coordinates
        printf("Current Coordinates: (%d, %d)\n", x, y);
        double currDistance = getDistance(x, y, endX, endY);
        printf("Distance to Destination: %.2f miles\n\n", currDistance);
    }

    printf("You have arrived at your destination!\n");

    return 0;
}