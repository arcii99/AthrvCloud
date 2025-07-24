//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371 // Earth's radius in kilometers
#define PI 3.14159265358979323846 // PI constant

struct Location {
    double latitude;
    double longitude;
};

// Calculates the distance between two locations using the Haversine formula
double calculate_distance(struct Location loc1, struct Location loc2) {
    double d_lat = (loc2.latitude - loc1.latitude) * PI / 180.0;
    double d_lon = (loc2.longitude - loc1.longitude) * PI / 180.0;
    double a = sin(d_lat/2) * sin(d_lat/2) + cos(loc1.latitude * PI / 180.0) * cos(loc2.latitude * PI / 180.0) * sin(d_lon/2) * sin(d_lon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

// Simulates the GPS navigation from the current location to the destination location
void gps_navigation(struct Location current_location, struct Location destination_location) {
    printf("GPS Navigation started...\n\n");
    double distance = calculate_distance(current_location, destination_location);
    printf("Distance to destination: %.2f km\n\n", distance);
    printf("Please follow the directions provided by the GPS system.\n\n");
    printf("Driving....\n");
    printf("Driving....\n");
    printf("Driving....\n\n");
    printf("You have arrived at your destination!\n\n");
    printf("GPS Navigation completed.\n");
}

int main() {
    struct Location current_location = {45.50884, -73.58781}; // Current location in Montreal, Canada
    struct Location destination_location = {51.50722, -0.127758}; // Destination location in London, UK
    gps_navigation(current_location, destination_location);
    return 0;
}