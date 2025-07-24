//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LATITUDE_CONSTANT 111.045
#define LONGITUDE_CONSTANT 82.945

typedef struct{
    double latitude;
    double longitude;
} location;

double calculateDistance(location start, location end);

int main(){
    location a, b;
    printf("Enter the latitude and longitude of location A: ");
    scanf("%lf %lf", &a.latitude, &a.longitude);
    printf("Enter the latitude and longitude of location B: ");
    scanf("%lf %lf", &b.latitude, &b.longitude);
    double distance = calculateDistance(a, b);
    printf("The distance between A and B is %.2lf km.\n", distance);
    return 0;
}

double calculateDistance(location start, location end){
    double latitude_difference = fabs(start.latitude - end.latitude);
    double longitude_difference = fabs(start.longitude - end.longitude);
    double latitude_distance = latitude_difference * LATITUDE_CONSTANT;
    double longitude_distance = longitude_difference * LONGITUDE_CONSTANT;
    double distance = sqrt(latitude_distance * latitude_distance + longitude_distance * longitude_distance);
    return distance;
}