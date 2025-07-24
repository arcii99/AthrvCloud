//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define RADIAN_CONV 0.017453 // Conversion factor for degrees to radians
#define EARTH_RADIUS 6371.009 // Earth's radius in kilometers

// Function to calculate great circle distance between two points on Earth
double calculateDistance(double lat1, double long1, double lat2, double long2) {
    lat1 *= RADIAN_CONV;
    long1 *= RADIAN_CONV;
    lat2 *= RADIAN_CONV;
    long2 *= RADIAN_CONV;
    double deltaLong = long2 - long1;
    double deltaLat = lat2 - lat1;
    double a = pow(sin(deltaLat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLong/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

int main() {
    double lat1, long1, lat2, long2, distance;
    printf("\nEnter the latitude of starting point: ");
    scanf("%lf", &lat1);
    printf("Enter the longitude of starting point: ");
    scanf("%lf", &long1);
    printf("Enter the latitude of destination point: ");
    scanf("%lf", &lat2);
    printf("Enter the longitude of destination point: ");
    scanf("%lf", &long2);
    distance = calculateDistance(lat1, long1, lat2, long2);
    printf("\nDistance between the points is %lf kilometers.\n", distance);
    return 0;
}