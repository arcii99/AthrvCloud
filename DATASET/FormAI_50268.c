//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

struct coordinates {
    double latitude;
    double longitude;
};

double toRadians(double degree) {
    return degree * (PI / 180.0);
}

double distance(struct coordinates a, struct coordinates b) {
    double lat1 = toRadians(a.latitude);
    double lon1 = toRadians(a.longitude);
    double lat2 = toRadians(b.latitude);
    double lon2 = toRadians(b.longitude);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double distance = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    distance = 2 * asin(sqrt(distance));

    double radius = 6371; // Earth's radius in km
    distance *= radius;

    return distance;
}

int main() {
    struct coordinates destination = { 51.5074, -0.1278 }; // London, UK
    struct coordinates current = { 40.7128, -74.0060 };     // New York City, USA

    double distanceTravelled = distance(destination, current);
    
    printf("Distance to destination: %lf km\n", distanceTravelled);

    return 0;
}