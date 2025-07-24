//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371000

typedef struct {
    double lat;
    double lon;
} GPSPoint;

double degToRad(double deg) {
    return deg / 180.0 * M_PI;
}

GPSPoint calculateDestinationPoint(GPSPoint start, double bearing, double distance) {
    double lat1 = degToRad(start.lat);
    double lon1 = degToRad(start.lon);
    bearing = degToRad(bearing);
    distance /= EARTH_RADIUS;
    double lat2 = asin(sin(lat1) * cos(distance) + cos(lat1) * sin(distance) * cos(bearing));
    double lon2 = lon1 + atan2(sin(bearing) * sin(distance) * cos(lat1), cos(distance) - sin(lat1) * sin(lat2));
    return (GPSPoint){lat2 * 180.0 / M_PI, lon2 * 180.0 / M_PI};
}

double calculateDistance(GPSPoint p1, GPSPoint p2) {
    double lat1 = degToRad(p1.lat);
    double lon1 = degToRad(p1.lon);
    double lat2 = degToRad(p2.lat);
    double lon2 = degToRad(p2.lon);
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main() {
    GPSPoint start = {40.712776, -74.005974}; // New York City
    double bearing = 45; // degrees
    double distance = 10000; // meters
    GPSPoint end = calculateDestinationPoint(start, bearing, distance);
    printf("Start: %f,%f\n", start.lat, start.lon);
    printf("End: %f,%f\n", end.lat, end.lon);
    printf("Distance: %fm\n", calculateDistance(start, end));
    return 0;
}