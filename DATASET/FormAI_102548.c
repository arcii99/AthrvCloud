//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TOWER_COUNT 5  // number of Wi-Fi towers
#define MAX_SIGNAL_STRENGTH 100  // maximum signal strength

// define a struct to hold information about each tower
typedef struct Tower {
    char name[10];
    double x;
    double y;
    double signalStrength;
} Tower;

// function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main() {
    // create an array of towers
    Tower towers[TOWER_COUNT];
    
    // initialize the towers with random location and signal strength values
    strcpy(towers[0].name, "Tower 1");
    towers[0].x = 2.5;
    towers[0].y = 4.3;
    towers[0].signalStrength = rand() % MAX_SIGNAL_STRENGTH + 1;
    
    strcpy(towers[1].name, "Tower 2");
    towers[1].x = 6.1;
    towers[1].y = 8.9;
    towers[1].signalStrength = rand() % MAX_SIGNAL_STRENGTH + 1;
    
    strcpy(towers[2].name, "Tower 3");
    towers[2].x = 9.4;
    towers[2].y = 3.7;
    towers[2].signalStrength = rand() % MAX_SIGNAL_STRENGTH + 1;
    
    strcpy(towers[3].name, "Tower 4");
    towers[3].x = 1.8;
    towers[3].y = 9.0;
    towers[3].signalStrength = rand() % MAX_SIGNAL_STRENGTH + 1;
    
    strcpy(towers[4].name, "Tower 5");
    towers[4].x = 7.2;
    towers[4].y = 1.5;
    towers[4].signalStrength = rand() % MAX_SIGNAL_STRENGTH + 1;
    
    // get user's current location
    printf("Enter your current coordinates (x y): ");
    double currentX, currentY;
    scanf("%lf %lf", &currentX, &currentY);
    
    // calculate distance and signal strength from each tower
    printf("\n%s\n", "Tower\t\tDistance\tSignal Strength");
    double totalDistance = 0;
    double weightedSignalStrength = 0;
    for (int i = 0; i < TOWER_COUNT; i++) {
        double d = distance(currentX, currentY, towers[i].x, towers[i].y);
        double ss = towers[i].signalStrength / d;
        printf("%s\t%.2f\t\t%.2f\n", towers[i].name, d, ss);
        totalDistance += d;
        weightedSignalStrength += ss;
    }
    
    // calculate the average of the weighted signal strengths
    double avgSignalStrength = weightedSignalStrength / TOWER_COUNT;
    
    // print the final signal strength
    printf("\nYour current Wi-Fi signal strength is: %.2f\n", avgSignalStrength);
    
    return 0;
}