//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: thoughtful
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371.0 // average radius of the earth in km

struct Location {
    double latitude;
    double longitude;
};

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

// calculates the great circle distance between two points in km
double calculateDistance(struct Location location1, struct Location location2) {
    double lat1 = toRadians(location1.latitude);
    double lat2 = toRadians(location2.latitude);
    double lon1 = toRadians(location1.longitude);
    double lon2 = toRadians(location2.longitude);

    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;

    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double distance = EARTH_RADIUS * c;
    return distance;
}

int main() {
    struct Location currentLocation = {48.858238, 2.294514}; // Paris, France
    struct Location destinationLocation = {51.509865, -0.118092}; // London, UK

    double distance = calculateDistance(currentLocation, destinationLocation);

    printf("Distance from Paris to London: %.2f km\n", distance);

    return 0;
}