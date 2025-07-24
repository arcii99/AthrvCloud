//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371  // radius of the earth in km
#define PI 3.14159265358979323846

// function to convert degrees to radians
double deg2rad(double deg) {
    return (deg * PI / 180);
}

// function to calculate the distance between two points on earth given their latitude and longitude
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat, dlon, a, c, d;
    dlat = deg2rad(lat2 - lat1);
    dlon = deg2rad(lon2 - lon1);
    a = sin(dlat / 2) * sin(dlat / 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dlon / 2) * sin(dlon / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    d = RADIUS * c;
    return d;
}

int main() {
    double lat1, lon1, lat2, lon2, dist;
    printf("Enter the starting latitude: ");
    scanf("%lf", &lat1);
    printf("Enter the starting longitude: ");
    scanf("%lf", &lon1);
    printf("Enter the destination latitude: ");
    scanf("%lf", &lat2);
    printf("Enter the destination longitude: ");
    scanf("%lf", &lon2);
    dist = distance(lat1, lon1, lat2, lon2);
    printf("The distance between (%lf,%lf) and (%lf,%lf) is %lf km\n", lat1, lon1, lat2, lon2, dist);
    return 0;
}