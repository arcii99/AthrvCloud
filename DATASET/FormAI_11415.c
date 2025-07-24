//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <math.h>

#define RADIUS 6371

double calculateDistance(double lat1, double lon1, double lat2, double lon2);

int main() {
    double lat1, lon1, lat2, lon2, distance;

    printf("Enter the latitude and longitude of the starting point: ");
    scanf("%lf %lf", &lat1, &lon1);

    printf("Enter the latitude and longitude of the destination: ");
    scanf("%lf %lf", &lat2, &lon2);

    distance = calculateDistance(lat1, lon1, lat2, lon2);

    printf("The distance between the two points is %lf kilometers.\n", distance);
    
    return 0;
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double lat1Radian = lat1 * M_PI/180;
    double lat2Radian = lat2 * M_PI/180;
    double deltaLat = (lat2-lat1) * M_PI/180;
    double deltaLon = (lon2-lon1) * M_PI/180;

    double a = sin(deltaLat/2) * sin(deltaLat/2) + cos(lat1Radian) * cos(lat2Radian) * sin(deltaLon/2) * sin(deltaLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = RADIUS * c;

    return distance;
}