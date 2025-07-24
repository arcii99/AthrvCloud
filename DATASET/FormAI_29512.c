//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define struct for GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} GPS_coordinate;

// Define function for calculating distance between two GPS coordinates using Haversine formula
double calculate_distance(GPS_coordinate coord1, GPS_coordinate coord2) {
    double lat1 = coord1.latitude * PI / 180.0;
    double long1 = coord1.longitude * PI / 180.0;
    double lat2 = coord2.latitude * PI / 180.0;
    double long2 = coord2.longitude * PI / 180.0;
    
    double delta_lat = lat2 - lat1;
    double delta_long = long2 - long1;
    
    double a = sin(delta_lat / 2) * sin(delta_lat / 2) + cos(lat1) * cos(lat2) * sin(delta_long / 2) * sin(delta_long / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;
    
    return d;
}

int main() {
    // Define GPS coordinates for starting point and destination
    GPS_coordinate starting_point = {39.9075, 32.8560};
    GPS_coordinate destination = {41.0082, 28.9784};
    
    // Calculate distance between starting point and destination
    double distance = calculate_distance(starting_point, destination);
    
    if (distance > 1000) {
        printf("Destination is too far away. Please fly instead of driving.\n");
    } else {
        printf("Distance to destination: %.2lf km\n", distance);
    }
    
    return 0;
}