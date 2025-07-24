//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

// Function to calculate the distance between two points
double distance(double lat1, double long1, double lat2, double long2){
    double dlat = (lat2-lat1)*PI/180.0;
    double dlong = (long2-long1)*PI/180.0;

    double a = pow(sin(dlat/2),2)+cos(lat1*PI/180.0)*cos(lat2*PI/180.0)*pow(sin(dlong/2),2);
    double c = 2*atan2(sqrt(a), sqrt(1-a));
    double d = 6371*c;
    return d;
}

int main() {
    double lat1, long1, lat2, long2;
    printf("Enter latitude and longitude of starting point (in degrees):\n");
    scanf("%lf %lf", &lat1, &long1);
    printf("Enter latitude and longitude of destination (in degrees):\n");
    scanf("%lf %lf", &lat2, &long2);
    double d = distance(lat1, long1, lat2, long2);
    printf("Distance between starting point and destination: %lf km\n", d);
    return 0;
}