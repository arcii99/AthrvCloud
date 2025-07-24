//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371000 // radius of the earth in meters

struct Coordinate {
    double lat; // latitude in degrees
    double lon; // longitude in degrees
};

double to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double calculate_distance(struct Coordinate point1, struct Coordinate point2) {
    double lat1_r = to_radians(point1.lat);
    double lon1_r = to_radians(point1.lon);
    double lat2_r = to_radians(point2.lat);
    double lon2_r = to_radians(point2.lon);
    
    double delta_lon = lon2_r - lon1_r;
    double delta_lat = lat2_r - lat1_r;
    
    double a = sin(delta_lat/2) * sin(delta_lat/2) +
               cos(lat1_r) * cos(lat2_r) *
               sin(delta_lon/2) * sin(delta_lon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;
    
    return distance;
}

int main() {
    struct Coordinate starting_point = {37.7749, -122.4194}; // San Francisco
    struct Coordinate destination_point = {40.7128, -74.0060}; // New York City
    
    double distance = calculate_distance(starting_point, destination_point);
    printf("The distance between San Francisco and New York City is %f meters\n", distance);
    
    return 0;
}