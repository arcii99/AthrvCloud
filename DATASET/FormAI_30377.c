//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the distance between two GPS coordinates
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat, dlon, a, c, d;
    dlat = (lat2 - lat1) * PI / 180.0;
    dlon = (lon2 - lon1) * PI / 180.0;
    a = pow(sin(dlat/2),2) + cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) * pow(sin(dlon/2),2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = 6373 * c;
    return d;
}

int main() {
    // Set the initial GPS coordinates
    double lat = 39.9526; // Latitude of Washington, D.C.
    double lon = -75.1652; // Longitude of Washington, D.C.

    // Set the destination GPS coordinates
    double dest_lat = 37.7749; // Latitude of San Francisco, CA
    double dest_lon = -122.4194; // Longitude of San Francisco, CA

    // Calculate the initial distance from the destination
    double dist = distance(lat, lon, dest_lat, dest_lon);

    // Initialize variables for the simulation
    int iterations = 0;
    int max_iterations = 1000;
    double move_distance = 100.0; // The distance to move each iteration

    // Start the simulation loop
    while (dist > 10.0 && iterations < max_iterations) {
        printf("Iteration %d\n", iterations);
        printf("Distance to destination: %f km\n", dist);
        printf("Current GPS coordinates: (%f, %f)\n", lat, lon);

        // Calculate the bearing to the destination
        double dlat = (dest_lat - lat) * PI / 180.0;
        double dlon = (dest_lon - lon) * PI / 180.0;
        double bearing = atan2(sin(dlon)*cos(dest_lat * PI / 180.0), cos(lat * PI / 180.0)*sin(dest_lat * PI / 180.0) - sin(lat * PI / 180.0)*cos(dest_lat * PI / 180.0)*cos(dlon));
        bearing = bearing * 180.0 / PI; // Convert to degrees
        if (bearing < 0) {
            bearing = 360 + bearing;
        }
        printf("Bearing to destination: %f degrees\n", bearing);

        // Move towards the destination
        double lat1 = lat * PI / 180.0;
        double lon1 = lon * PI / 180.0;
        double d = dist * 1000.0; // Convert to meters
        double lat2 = asin(sin(lat1)*cos(d/6371000.0) + cos(lat1)*sin(d/6371000.0)*cos(bearing*PI/180.0));
        double lon2 = lon1 + atan2(sin(bearing*PI/180.0)*sin(d/6371000.0)*cos(lat1), cos(d/6371000.0)-sin(lat1)*sin(lat2));
        lat2 = lat2 * 180.0 / PI; // Convert to degrees
        lon2 = lon2 * 180.0 / PI; // Convert to degrees

        // Update the distance and GPS coordinates
        dist = distance(lat2, lon2, dest_lat, dest_lon);
        lat = lat2;
        lon = lon2;

        iterations++;
    }

    // Print the final GPS coordinates
    printf("Final GPS coordinates: (%f, %f)\n", lat, lon);

    return 0;
}