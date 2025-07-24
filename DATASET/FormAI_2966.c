//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct location {
    double latitude;
    double longitude;
} location;

location currentLocation = {0, 0}; // Starting location

void navigateTo(location destination) {
    double distance = sqrt(pow(destination.latitude - currentLocation.latitude, 2) + pow(destination.longitude - currentLocation.longitude, 2));
    
    printf("Navigating from %.2f, %.2f to %.2f, %.2f.\n", currentLocation.latitude, currentLocation.longitude,
           destination.latitude, destination.longitude);
    printf("Distance to destination: %.2f km.\n", distance);
    
    // Update current location
    currentLocation = destination;
}

int main() {
    // Example navigation from Paris to Rome
    location paris = {48.8566, 2.3522};
    location rome = {41.9028, 12.4964};
    
    navigateTo(paris);
    navigateTo(rome);
    
    return 0;
}