//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371  // Earth radius in kilometers

struct Location {
    double latitude;
    double longitude;
};

double toRadians(double degrees) {
    return degrees * (M_PI / 180);
}

double calculateDistance(struct Location l1, struct Location l2) {
    double lat1 = toRadians(l1.latitude);
    double lat2 = toRadians(l2.latitude);
    double lon1 = toRadians(l1.longitude);
    double lon2 = toRadians(l2.longitude);

    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;

    double a = pow(sin(deltaLat / 2), 2) +
               cos(lat1) * cos(lat2) *
               pow(sin(deltaLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return RADIUS * c;
}

int main() {
    struct Location currentLocation = {40.741895, -73.989308};  // Starting point: New York City
    struct Location destination = {51.509865, -0.118092};  // Destination: London

    double distance = calculateDistance(currentLocation, destination);
    printf("Distance between current location and destination: %.2lf km\n", distance);

    return 0;
}