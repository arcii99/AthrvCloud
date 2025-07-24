//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

double radian(double degree) {
    return degree * PI / 180.0;
}

double distance(Coordinate a, Coordinate b) {
    double R = 6371.0; // Earth radius in km

    double lat_a = radian(a.latitude);
    double long_a = radian(a.longitude);
    double lat_b = radian(b.latitude);
    double long_b = radian(b.longitude);

    double d_lat = lat_b - lat_a;
    double d_long = long_b - long_a;

    double a1 = sin(d_lat / 2.0) * sin(d_lat / 2.0) +
               cos(lat_a) * cos(lat_b) *
               sin(d_long / 2.0) * sin(d_long / 2.0);
    double c = 2.0 * atan2(sqrt(a1), sqrt(1.0 - a1));
    double d = R * c;
    return d;
}

int main() {
    printf("GPS Navigation Simulation\n");

    Coordinate start = {0.0, 0.0};
    printf("Start position: (%lf, %lf)\n", start.latitude, start.longitude);

    Coordinate end = {45.0, 90.0};
    printf("End position: (%lf, %lf)\n", end.latitude, end.longitude);

    double d = distance(start, end);
    printf("Distance between start and end: %lf km\n", d);

    return 0;
}