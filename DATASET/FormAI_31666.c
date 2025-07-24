//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371.0 // Earth radius in km

typedef struct {
    double lat; // Latitude in degrees
    double lon; // Longitude in degrees
} GPSPosition;

double deg2rad(double deg) {
    return deg * M_PI / 180;
}

double distance(GPSPosition p1, GPSPosition p2) {
    double lat1 = deg2rad(p1.lat);
    double lon1 = deg2rad(p1.lon);
    double lat2 = deg2rad(p2.lat);
    double lon2 = deg2rad(p2.lon);
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return RADIUS * c;
}

int main() {
    GPSPosition start = {35.6785, 139.6823}; // Tokyo Tower coordinates
    GPSPosition end = {40.7851, -73.9683}; // Empire State Building coordinates

    double distance_km = distance(start, end);
    printf("Distance between Tokyo Tower and Empire State Building: %.2f km\n", distance_km);

    return 0;
}