//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define constants for locations
#define LONDON 0
#define PARIS 1
#define BERLIN 2
#define AMSTERDAM 3
#define ROME 4

// Define array of locations
char* locations[] = {"London", "Paris", "Berlin", "Amsterdam", "Rome"};

// Define function to get distance between two locations
double getDistance(int start, int end) {
    double distances[5][5] = {{0, 213.26, 930.31, 429.85, 1419.53},
                             {213.26, 0, 876.96, 431.36, 1103.13},
                             {930.31, 876.96, 0, 640.02, 1188.27},
                             {429.85, 431.36, 640.02, 0, 1447.71},
                             {1419.53, 1103.13, 1188.27, 1447.71, 0}};
    return distances[start][end];
}

// Define function to simulate GPS navigation
void startNavigation(int start, int end) {
    printf("Starting navigation from %s to %s...\n", locations[start], locations[end]);
    double distance = getDistance(start, end);
    printf("The total distance is %.2f kilometers.\n", distance);
    double time = distance / 70; // Assuming an average speed of 70km/h
    printf("The expected travel time is %.2f hours.\n", time);
}

int main() {
    int start, end;
    printf("Please enter the starting location:\n");
    printf("0 - London\n1 - Paris\n2 - Berlin\n3 - Amsterdam\n4 - Rome\n");
    scanf("%d", &start);
    printf("Please enter the destination:\n");
    printf("0 - London\n1 - Paris\n2 - Berlin\n3 - Amsterdam\n4 - Rome\n");
    scanf("%d", &end);
    startNavigation(start, end);
    return 0;
}