//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Alan Touring
#include <stdio.h>

// struct to hold GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} GPS;

// function to calculate distance between two GPS points
double calculate_distance(GPS a, GPS b) {
    // implementation goes here
}

int main() {
    // define starting and destination coordinates
    GPS start = {40.7128, -74.0060}; // New York City, USA
    GPS dest = {51.5074, -0.1278}; // London, UK

    // calculate distance between start and destination
    double distance = calculate_distance(start, dest);

    // output distance to user
    printf("Distance between New York City and London is %.2f km\n", distance);

    // more simulation features could be added here, such as prompting user for current location,
    // updating the distance as user moves, suggesting alternate routes, etc.

    return 0;
}