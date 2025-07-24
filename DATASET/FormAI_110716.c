//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EARTH_RADIUS 6371.0 // in km

struct Position {
    double latitude;
    double longitude;
};

double to_radians(double degree) {
    return degree * M_PI / 180.0;
}

double distance_between(struct Position start, struct Position end) {
    double lat1 = to_radians(start.latitude);
    double lat2 = to_radians(end.latitude);
    double diff_lat = to_radians(end.latitude - start.latitude);
    double diff_long = to_radians(end.longitude - start.longitude);

    double a = sin(diff_lat/2) * sin(diff_lat/2) + cos(lat1) * cos(lat2) * sin(diff_long/2) * sin(diff_long/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = EARTH_RADIUS * c;

    return d;
}

void navigate(struct Position current, struct Position destination) {
    double distance = distance_between(current, destination);
    printf("Distance to destination is %0.2lf km\n", distance);
}

int main() {
    struct Position current_location = {37.7749, -122.4194};
    struct Position destination = {40.7128, -74.0060};

    navigate(current_location, destination);

    return 0;
}