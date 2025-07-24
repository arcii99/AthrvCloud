//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371  //Radius of earth in kilometers
#define DEG_TO_RAD 0.0174533  //Degree to radian conversion factor

// Structure to store the GPS coordinates of a location
typedef struct {
    double latitude;
    double longitude;
} Location;

// Helper function to convert degrees to radians
double deg_to_rad(double deg) {
    return deg * DEG_TO_RAD;
}

// Function to calculate the distance between two locations using Haversine formula
double distance(Location location1, Location location2) {
    double lat1 = deg_to_rad(location1.latitude);
    double lat2 = deg_to_rad(location2.latitude);
    double d_lat = deg_to_rad(location2.latitude - location1.latitude);
    double d_long = deg_to_rad(location2.longitude - location1.longitude);
    double a = pow(sin(d_lat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(d_long/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = RADIUS * c;
    return d;
}

// Function to simulate GPS navigation with given locations
void gps_navigation(Location* locations, int num_locations) {
    int i;
    double total_distance = 0;

    printf("Start Navigation:\n");

    for(i=0; i<num_locations-1; i++) {
        double d = distance(locations[i], locations[i+1]);  // Calculate distance between current and next location
        total_distance += d;
        printf("Go from (%f, %f) to (%f, %f). Distance: %f km.\n", locations[i].latitude, locations[i].longitude,
                locations[i+1].latitude, locations[i+1].longitude, d);
    }

    printf("Total distance covered: %f km.\n", total_distance);
}

int main() {
    Location locations[] = { {37.7749, -122.4194}, {38.5816, -121.4944}, {39.7392, -104.9903}, {41.8781, -87.6298} };
    int num_locations = sizeof(locations) / sizeof(locations[0]);

    gps_navigation(locations, num_locations);

    return 0;
}