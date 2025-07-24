//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {
    // Set initial position and destination coordinates (latitude, longitude)
    double lat1 = 52.5200;
    double long1 = 13.4050;
    double lat2 = 41.3851;
    double long2 = 2.1734;
    
    // Convert coordinates to radians
    double lat1rad = lat1 * PI/180;
    double lat2rad = lat2 * PI/180;
    double long1rad = long1 * PI/180;
    double long2rad = long2 * PI/180;
    
    // Compute the distance and bearing between the two points
    double dlat = lat2rad - lat1rad;
    double dlong = long2rad - long1rad;
    double a = pow(sin(dlat/2), 2) + cos(lat1rad) * cos(lat2rad) * pow(sin(dlong/2), 2);
    double c = 2 * asin(sqrt(a));
    double distance = 6371 * c;
    double y = sin(dlong) * cos(lat2rad);
    double x = cos(lat1rad) * sin(lat2rad) - sin(lat1rad) * cos(lat2rad) * cos(dlong);
    double bearing = atan2(y, x) * 180/PI;
    
    // Print out the results
    printf("Starting coordinates: (%f, %f)\n", lat1, long1);
    printf("Destination coordinates: (%f, %f)\n", lat2, long2);
    printf("Distance between locations: %f km\n", distance);
    printf("Bearing: %f\n", bearing);
    
    // Simulate the GPS navigation to the destination
    double currentLat = lat1;
    double currentLong = long1;
    while(distance >= 0.1) { // Keep navigating until within 0.1 km of the destination
        // Compute the next waypoint
        double latRad = currentLat * PI/180;
        double longRad = currentLong * PI/180;
        double nextLat = asin(sin(latRad) * cos(distance/6371) + cos(latRad) * sin(distance/6371) * cos(bearing * PI/180)) * 180/PI;
        double nextLong = longRad + atan2(sin(bearing * PI/180) * sin(distance/6371) * cos(latRad), cos(distance/6371) - sin(latRad) * sin(nextLat * PI/180)) * 180/PI;
        
        // Print out the next waypoint
        printf("Next waypoint: (%f, %f)\n", nextLat, nextLong);
        
        // Update the current position and compute the new distance and bearing
        currentLat = nextLat;
        currentLong = nextLong;
        dlat = lat2rad - currentLat * PI/180;
        dlong = long2rad - currentLong * PI/180;
        a = pow(sin(dlat/2), 2) + cos(lat2rad) * cos(currentLat * PI/180) * pow(sin(dlong/2), 2);
        c = 2 * asin(sqrt(a));
        distance = 6371 * c;
        y = sin(dlong) * cos(lat2rad);
        x = cos(currentLat * PI/180) * sin(lat2rad) - sin(currentLat * PI/180) * cos(lat2rad) * cos(dlong);
        bearing = atan2(y, x) * 180/PI;
    }
    
    // Print out arrival message
    printf("You have arrived at your destination!\n");
    
    return 0;
}