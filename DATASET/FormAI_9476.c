//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define RADIUS 6371 // Earth radius in kilometers
#define PI 3.14159265359

// Function to convert from degrees to radians
double toRadians(double degree) {
    return degree * PI / 180;
}

// Function to calculate distance between two points on Earth
double calcDistance(double lat1, double long1, double lat2, double long2) {
    double dLat = toRadians(lat2 - lat1);
    double dLong = toRadians(long2 - long1);
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(toRadians(lat1)) * cos(toRadians(lat2)) *
               sin(dLong / 2) * sin(dLong / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = RADIUS * c;
    return distance;
}

int main() {
    double lat1, long1, lat2, long2;
    printf("Enter the latitude and longitude of point 1: ");
    scanf("%lf,%lf", &lat1, &long1);
    printf("Enter the latitude and longitude of point 2: ");
    scanf("%lf,%lf", &lat2, &long2);

    double distance = calcDistance(lat1, long1, lat2, long2);
    printf("The distance between point 1 and point 2 is: %lf km\n", distance);

    return 0;
}