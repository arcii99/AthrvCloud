//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define R 6371.0

struct Location {
    double latitude;
    double longitude;
};

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double distanceBetweenLocations(struct Location loc1, struct Location loc2) {
    double lat1 = toRadians(loc1.latitude);
    double lon1 = toRadians(loc1.longitude);
    double lat2 = toRadians(loc2.latitude);
    double lon2 = toRadians(loc2.longitude);
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c;
    return distance;
}

int main() {
    struct Location currentLocation = {25.3333, 55.3999};
    struct Location destinationLocation = {41.3888, 2.1590};
    double distance = distanceBetweenLocations(currentLocation, destinationLocation);
    printf("Distance from Current Location to Destination: %lf km\n", distance);
    return 0;
}