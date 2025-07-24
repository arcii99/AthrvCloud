//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define PI 3.14159265
#define EARTH_RADIUS_KM 6371.0

// Define function to convert degrees to radians
double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

// Define function to calculate distance between two points using haversine formula
double getDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(toRadians(lat1)) * cos(toRadians(lat2)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS_KM * c;
    return distance;
}

int main() {
    // Define variables for destination coordinates
    double destLat = 40.7128;
    double destLon = -74.0060;

    // Define variables for current position
    double currentLat = 37.7749;
    double currentLon = -122.4194;

    // Calculate distance between current position and destination
    double distance = getDistance(currentLat, currentLon, destLat, destLon);

    // Print distance to destination
    printf("Distance to destination: %.2f km\n", distance);

    return 0;
}