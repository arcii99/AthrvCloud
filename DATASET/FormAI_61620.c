//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

typedef struct {
    double lat;
    double lon;
} Coordinate;

double degreesToRadians(double degrees){
    return (degrees * PI / 180);
}

double distanceBetweenCoordinates(Coordinate coord1, Coordinate coord2){
    double dLat = degreesToRadians(coord2.lat - coord1.lat);
    double dLon = degreesToRadians(coord2.lon - coord1.lon);
    double a = sin(dLat/2) * sin(dLat/2) + cos(degreesToRadians(coord1.lat)) * cos(degreesToRadians(coord2.lat)) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6373 * c;
    return d;
}

int main(){
    Coordinate currentLocation = {47.606209, -122.332069}; 
    Coordinate destination = {37.779026, -122.419906};
    double distance = distanceBetweenCoordinates(currentLocation, destination);
    printf("Distance to destination: %f km\n", distance);
}