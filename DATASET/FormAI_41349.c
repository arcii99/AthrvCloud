//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Constant for converting degrees to radians
#define DEG_TO_RAD 0.01745329252

// Struct for holding GPS coordinates
typedef struct {
    double lat; // Latitude in degrees
    double lon; // Longitude in degrees
} GPSCoordinates;

// Function to calculate the distance between two GPS coordinates in meters
double distance(GPSCoordinates coord1, GPSCoordinates coord2) {
    double R = 6371000; // Earth's radius in meters
    double phi1 = coord1.lat * DEG_TO_RAD;
    double phi2 = coord2.lat * DEG_TO_RAD;
    double delta_phi = (coord2.lat - coord1.lat) * DEG_TO_RAD;
    double delta_lambda = (coord2.lon - coord1.lon) * DEG_TO_RAD;

    double a = sin(delta_phi/2) * sin(delta_phi/2) +
              cos(phi1) * cos(phi2) *
              sin(delta_lambda/2) * sin(delta_lambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return R * c;
}

// Function to simulate GPS navigation
void simulateNavigation(GPSCoordinates destination) {
    // Initialize current location to a random location
    GPSCoordinates currentLocation = {.lat = rand() % 90, .lon = rand() % 180};
    double totalDistance = distance(currentLocation, destination);

    // Move towards destination until we reach it
    while (distance(currentLocation, destination) > 10) {
        double bearing = atan2(destination.lon - currentLocation.lon, 
                               destination.lat - currentLocation.lat);
        double distanceToMove = totalDistance * 0.01;
        currentLocation.lon += distanceToMove * sin(bearing);
        currentLocation.lat += distanceToMove * cos(bearing);
        printf("Current location: (%lf, %lf)\n", currentLocation.lat, currentLocation.lon);
    }

    printf("Arrived at destination: (%lf, %lf)\n", destination.lat, destination.lon);
}

int main() {
    GPSCoordinates destination = {.lat = 53.4808, .lon = -2.2426}; // Coordinates of Manchester, UK
    simulateNavigation(destination);
    return 0;
}