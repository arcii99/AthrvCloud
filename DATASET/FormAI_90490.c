//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371 // Earth's radius in kilometers

struct Coordinate {
    double latitude;
    double longitude;
};

double toRadians(double degrees) {
    return (degrees * M_PI) / 180.0;
}

double computeDistance(struct Coordinate c1, struct Coordinate c2) {
    double lat1 = toRadians(c1.latitude);
    double lat2 = toRadians(c2.latitude);
    double deltaLat = toRadians(c2.latitude - c1.latitude);
    double deltaLong = toRadians(c2.longitude - c1.longitude);
    
    double a = pow(sin(deltaLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLong / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return RADIUS * c;
}

int main() {
    struct Coordinate start, end;
    double distance;
    
    printf("Enter the starting latitude: ");
    scanf("%lf", &start.latitude);
    printf("Enter the starting longitude: ");
    scanf("%lf", &start.longitude);
    printf("Enter the ending latitude: ");
    scanf("%lf", &end.latitude);
    printf("Enter the ending longitude: ");
    scanf("%lf", &end.longitude);
    
    distance = computeDistance(start, end);
    
    printf("The distance between the two points is %.2lf km.\n", distance);
    
    return 0;
}