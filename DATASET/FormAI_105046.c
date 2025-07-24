//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

/* Define a structure to hold GPS coordinates */
typedef struct {
    double latitude;
    double longitude;
} GPSCoords;

/* Function to calculate the distance between two GPS coordinates in kilometers */
double calc_distance(GPSCoords coord1, GPSCoords coord2) {
    double lat1 = coord1.latitude * PI / 180.0;
    double lon1 = coord1.longitude * PI / 180.0;
    double lat2 = coord2.latitude * PI / 180.0;
    double lon2 = coord2.longitude * PI / 180.0;
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c;
    return distance;
}

/* Program entry point */
int main() {
    /* Define two GPS coordinates */
    GPSCoords coord1 = {37.7749, -122.4194};
    GPSCoords coord2 = {40.7128, -74.0060};

    /* Calculate the distance between the two coordinates */
    double distance = calc_distance(coord1, coord2);

    /* Print the distance */
    printf("The distance between the two coordinates is: %lf km\n", distance);

    /* Exit the program */
    return 0;
}