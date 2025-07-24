//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct to represent a location
typedef struct {
    float lat;
    float lng;
    char name[30];
} Location;

// Function to calculate the distance between two locations
float calcDistance(Location a, Location b) {
    float latDiff = abs(a.lat - b.lat);
    float lngDiff = abs(a.lng - b.lng);
    float distance = sqrt((latDiff * latDiff) + (lngDiff * lngDiff));
    return distance;
}

// Function to simulate GPS navigation
void navigate(Location current, Location destination) {
    printf("Calculating route...\n");
    printf("Starting at: %s\n", current.name);
    printf("Navigating to: %s\n", destination.name);
    printf("Distance to destination: %.2f km\n", calcDistance(current, destination));
    printf("Turn left.\n");
    printf("Turn right.\n");
    printf("Straight ahead.\n");
    printf("You have reached your destination!\n");
}

int main() {
    // Sample locations
    Location current = {37.7749, -122.4194, "San Francisco"};
    Location dest = {40.7128, -74.0060, "New York City"};

    // Simulate navigation
    navigate(current, dest);

    return 0;
}