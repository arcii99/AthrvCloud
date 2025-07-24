//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double toRadians(double degrees) {
    return degrees * (PI / 180);
}

double toDegrees(double radians) {
    return radians * (180 / PI);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat = toRadians(lat2 - lat1);
    double deltaLon = toRadians(lon2 - lon1);
    double a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos(toRadians(lat1)) * cos(toRadians(lat2)) * sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;
    return d;
}

double bearing(double lat1, double lon1, double lat2, double lon2) {
    double y = sin(toRadians(lon2 - lon1)) * cos(toRadians(lat2));
    double x = cos(toRadians(lat1)) * sin(toRadians(lat2)) - sin(toRadians(lat1)) * cos(toRadians(lat2)) * cos(toRadians(lon2 - lon1));
    double brng = atan2(y, x);
    return toDegrees(brng);
}

int main() {
    double lat1 = 40.7128; // New York City latitude in degrees
    double lon1 = -74.0060; // New York City longitude in degrees
    double lat2 = 34.0522; // Los Angeles latitude in degrees
    double lon2 = -118.2437; // Los Angeles longitude in degrees
    printf("The distance between New York City and Los Angeles is %.2f kilometers\n", distance(lat1, lon1, lat2, lon2));
    printf("The bearing from New York City to Los Angeles is %.2f degrees\n", bearing(lat1, lon1, lat2, lon2));
    return 0;
}