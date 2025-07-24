//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371 // Earth's radius in Km

// Structure representing a GPS coordinate
typedef struct { 
    double latitude;
    double longitude;
} GPS;

/**
 * Function that calculates the distance between two GPS coordinates using the Haversine formula
 * @param gps1 First GPS coordinate
 * @param gps2 Second GPS coordinate
 * @return Distance between the two GPS coordinates in Km
 */
double calculateDistance(GPS gps1, GPS gps2) {
    double latitude1 = gps1.latitude * M_PI / 180.0;
    double longitude1 = gps1.longitude * M_PI / 180.0;
    double latitude2 = gps2.latitude * M_PI / 180.0;
    double longitude2 = gps2.longitude * M_PI / 180.0;
    
    double deltaLatitude = latitude2 - latitude1;
    double deltaLongitude = longitude2 - longitude1;
    
    double a = pow(sin(deltaLatitude / 2), 2) + cos(latitude1) * cos(latitude2) * pow(sin(deltaLongitude / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    double distance = EARTH_RADIUS * c;
    return distance;
}

// Main function
int main() {
    // Two GPS coordinates to calculate distance
    GPS gps1 = { 52.516667, 13.383333 }; // Berlin, Germany
    GPS gps2 = { 48.856667, 2.350987 }; // Paris, France
    
    double distance = calculateDistance(gps1, gps2);
    
    printf("Distance between Berlin and Paris: %lf Km", distance);
    
    return 0;
}