//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793

struct Point {
    double latitude;
    double longitude;
};

double distance(struct Point a, struct Point b) {
    double lat1 = a.latitude * PI / 180.0;
    double lat2 = b.latitude * PI / 180.0;
    double dlat = (b.latitude - a.latitude) * PI / 180.0;
    double dlon = (b.longitude - a.longitude) * PI / 180.0;
    double A = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double C = 2 * atan2(sqrt(A), sqrt(1 - A));
    double distance = 6371 * C;
    return distance;
}

int main() {
    struct Point a = { 51.5074, 0.1278 };
    struct Point b = { 48.8566, 2.3522 };
    double dist = distance(a, b);
    printf("Distance between London and Paris is %lf km\n", dist);

    return 0;
}