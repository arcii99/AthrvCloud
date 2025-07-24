//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884

typedef struct {
    double latitude;
    double longitude;
} Location;

double distance(Location location1, Location location2) {
    double lat1 = location1.latitude * PI / 180;
    double lat2 = location2.latitude * PI / 180;
    double lon1 = location1.longitude * PI / 180;
    double lon2 = location2.longitude * PI / 180;

    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos(lat1) * cos(lat2) * sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double distance = 6371 * c;

    return distance;
}

double speed(Location location1, Location location2, double time) {
    double distanceTravelled = distance(location1, location2);
    double speed = distanceTravelled / time;
    return speed;
}

double bearing(Location location1, Location location2) {
    double lat1 = location1.latitude * PI / 180;
    double lat2 = location2.latitude * PI / 180;
    double lon1 = location1.longitude * PI / 180;
    double lon2 = location2.longitude * PI / 180;

    double y = sin(lon2 - lon1) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1);

    double bearing = atan2(y, x) * 180 / PI;

    return bearing;
}

int main() {
    Location start = {35.689487, 139.691711}; // Tokyo Station
    Location end = {35.6585769, 139.7454506}; // Tokyo Tower

    double time = 30; // Time travelled in minutes

    double distanceTravelled = distance(start, end);
    double averageSpeed = speed(start, end, time);
    double bearingDirection = bearing(start, end);

    printf("Distance Travelled: %.2f km\n", distanceTravelled);
    printf("Average Speed: %.2f km/hr\n", averageSpeed * 60);
    printf("Bearing Direction: %.2f degrees\n", bearingDirection);

    return 0;
}