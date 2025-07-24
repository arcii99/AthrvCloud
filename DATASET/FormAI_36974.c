//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: automated
#include <stdio.h>

struct Location {
    double lat;
    double lon;
};

double toRadians(double degrees) {
    return degrees * 3.141592653589793 / 180.0;
}

double distanceBetweenLocations(struct Location loc1, struct Location loc2) {
    double lat1 = toRadians(loc1.lat);
    double lat2 = toRadians(loc2.lat);
    double deltaLat = toRadians(loc2.lat - loc1.lat);
    double deltaLon = toRadians(loc2.lon - loc1.lon);

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) +
        cos(lat1) * cos(lat2) *
        sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371e3 * c;

    return distance;
}

int main() {
    struct Location currentLocation = {40.763728, -73.972057}; // New York City
    struct Location destination = {51.509865, -0.118092}; // London, UK

    double distanceToDestination = distanceBetweenLocations(currentLocation, destination);
    printf("Distance to destination: %.2lf meters\n", distanceToDestination);

    return 0;
}