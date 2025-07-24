//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define Earth radius in kilometers
#define EARTH_RADIUS 6371.0

// Define a structure to hold GPS coordinates
typedef struct GPS_Coordinates {
    double latitude;
    double longitude;
} GPS_Coordinates;

// Define a function to calculate distance between two GPS coordinates
double distance(GPS_Coordinates start, GPS_Coordinates end) {
    double lat1 = start.latitude * M_PI / 180.0; // Convert to radians
    double lon1 = start.longitude * M_PI / 180.0;
    double lat2 = end.latitude * M_PI / 180.0;
    double lon2 = end.longitude * M_PI / 180.0;
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = EARTH_RADIUS * c; // Convert to kilometers
    return d;
}

int main() {
    GPS_Coordinates start = {37.7749295, -122.4194155}; // San Francisco
    GPS_Coordinates end1 = {40.7127753, -74.0059728}; // New York City
    GPS_Coordinates end2 = {-33.8688197, 151.2092955}; // Sydney
    
    printf("Distance from San Francisco to New York City: %.2f km\n", distance(start, end1));
    printf("Distance from San Francisco to Sydney: %.2f km\n", distance(start, end2));
    return 0;
}