//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

struct Location {
    double latitude;
    double longitude;
};

double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

double distanceBetweenLocations(struct Location locA, struct Location locB) {
    double aLat = toRadians(locA.latitude);
    double bLat = toRadians(locB.latitude);
    double deltaLon = toRadians(locB.longitude - locA.longitude);
    double cosDeltaLon = cos(deltaLon);
    double sinALat = sin(aLat);
    double cosALat = cos(aLat);
    double sinBLat = sin(bLat);
    double cosBLat = cos(bLat);
    double deltaCos = cosBLat * cosDeltaLon - cosALat * sinBLat;
    double deltaSin = sinALat * sinBLat + cosALat * cosBLat * cosDeltaLon;
    double distance = atan2(sqrt(deltaCos * deltaCos + deltaSin * deltaSin), 
                           sin(deltaSin)) * 6371.0;
    return distance;
}

int main() {
    struct Location start = {41.3917, 2.1649}; // Barcelona
    struct Location end = {48.8566, 2.3522}; // Paris
    double distance = distanceBetweenLocations(start, end);
    printf("Distance between Barcelona and Paris: %f km\n", distance);
    return 0;
}