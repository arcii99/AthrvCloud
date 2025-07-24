//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert degrees to radians
double degToRad(double degree) {
    return degree * M_PI / 180.0;
}

// Function to calculate distance between two points using haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    // Earth's radius = 6,371 km
    double r = 6371;

    // Convert latitudes and longitudes from degrees to radians
    double lat_rad1 = degToRad(lat1), lon_rad1 = degToRad(lon1);
    double lat_rad2 = degToRad(lat2), lon_rad2 = degToRad(lon2);

    // Calculate differences between latitudes and longitudes in radians
    double lat_diff = lat_rad2 - lat_rad1, lon_diff = lon_rad2 - lon_rad1;

    // Calculate haversine of half the central angle between two points
    double a = sin(lat_diff / 2) * sin(lat_diff / 2) + cos(lat_rad1) * cos(lat_rad2) * sin(lon_diff / 2) * sin(lon_diff / 2);

    // Calculate great circle distance in km
    double d = 2 * r * asin(sqrt(a));

    return d;
}

int main() {
    // Set starting point coordinates
    double start_lat = 52.2296756, start_lon = 21.0122287;

    // Set waypoints
    double waypoints[4][2] = {
        {52.406374, 16.9251681},  // Poznan, Poland
        {55.755825, 37.6172983},  // Moscow, Russia
        {37.7749295, -122.4194155},  // San Francisco, USA
        {-33.859972, 151.2111111}  // Sydney, Australia
    };

    int num_waypoints = 4;

    // Print starting point coordinates
    printf("Starting point: (%lf, %lf)\n\n", start_lat, start_lon);

    // Print waypoint coordinates and distance from starting point
    double total_distance = 0;
    for(int i = 0; i < num_waypoints; i++) {
        printf("Waypoint %d: (%lf, %lf)\n", i+1, waypoints[i][0], waypoints[i][1]);
        double distance = haversine(start_lat, start_lon, waypoints[i][0], waypoints[i][1]);
        printf("Distance from starting point: %lf km\n\n", distance);
        total_distance += distance;
        start_lat = waypoints[i][0];
        start_lon = waypoints[i][1];
    }

    // Print total distance traveled
    printf("Total distance traveled: %lf km\n", total_distance);

    return 0;
}