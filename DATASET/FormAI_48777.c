//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

// Define PI Constant
#define PI 3.14159265358979323846

// Define Earth's radius in kilometers
#define EARTH_RADIUS_KM 6371.0

// Define structure to hold GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} GPS_Position;

// Define function to convert degrees to radians
double deg2rad(double degrees) {
    return degrees * (PI / 180.0);
}

// Define function to calculate the distance between two GPS positions
double gpsDistance(GPS_Position pos1, GPS_Position pos2) {
    double lat1 = deg2rad(pos1.latitude);
    double lon1 = deg2rad(pos1.longitude);
    double lat2 = deg2rad(pos2.latitude);
    double lon2 = deg2rad(pos2.longitude);
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS_KM * c;
    return distance;
}

// Define main function
int main() {
    GPS_Position starting_position = {40.7128, -74.0060}; // New York City
    GPS_Position ending_position = {37.7749, -122.4194}; // San Francisco
    double distance = gpsDistance(starting_position, ending_position);
    printf("The distance between New York City and San Francisco is %.2lf kilometers.\n", distance);
    return 0;
}