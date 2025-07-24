//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371 // Earth's radius in kilometers

struct Location {
    double latitude; // in degrees
    double longitude; // in degrees
};

double degToRad(double deg) {
    return deg * (M_PI / 180);
}

double calculateDistance(struct Location location1, struct Location location2) {
    double lat1 = degToRad(location1.latitude);
    double lat2 = degToRad(location2.latitude);
    double lon1 = degToRad(location1.longitude);
    double lon2 = degToRad(location2.longitude);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = pow(sin(dLat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = RADIUS * c;

    return distance;
}

int main() {
    struct Location start = {40.7128, -74.0060}; // New York City
    struct Location end = {34.0522, -118.2437}; // Los Angeles

    double distance = calculateDistance(start, end);

    printf("The distance from New York City to Los Angeles is %.2f km.\n", distance);

    return 0;
}