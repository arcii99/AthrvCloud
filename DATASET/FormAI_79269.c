//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

// Define a structure to represent a GPS coordinate
typedef struct {
    double lat;
    double lon;
} location;

// Define the main function
int main() {
    // Initialize the starting point
    location start;
    start.lat = 39.7392 * (PI / 180);
    start.lon = -104.9903 * (PI / 180);
    printf("Starting location: (%f, %f)\n", start.lat, start.lon);

    // Initialize the destination point
    location dest;
    dest.lat = 37.7749 * (PI / 180);
    dest.lon = -122.4194 * (PI / 180);
    printf("Destination location: (%f, %f)\n", dest.lat, dest.lon);

    // Calculate the distance between the starting and destination points using the Haversine formula
    double delta_lat = dest.lat - start.lat;
    double delta_lon = dest.lon - start.lon;
    double a = pow(sin(delta_lat / 2), 2) + cos(start.lat) * cos(dest.lat) * pow(sin(delta_lon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c;
    printf("Distance between locations: %f km\n", distance);

    // Simulate navigation by generating random movements
    srand(time(NULL)); // Seed the random number generator
    double current_lat = start.lat;
    double current_lon = start.lon;
    double total_distance = 0;
    while (distance > 0) {
        double move_lat = ((double)rand() / RAND_MAX) / 100;
        double move_lon = ((double)rand() / RAND_MAX) / 100;
        current_lat += move_lat;
        current_lon += move_lon;
        double delta_lat = dest.lat - current_lat;
        double delta_lon = dest.lon - current_lon;
        distance = 6371 * 2 * atan2(sqrt(pow(sin(delta_lat / 2), 2) + cos(current_lat) * cos(dest.lat) * pow(sin(delta_lon / 2), 2)), sqrt(1 - pow(sin(delta_lat / 2), 2) - cos(current_lat) * cos(dest.lat) * pow(sin(delta_lon / 2), 2)));
        total_distance += sqrt(pow(move_lat, 2) + pow(move_lon, 2)) * 6371;
        printf("Current location: (%f, %f)\n", current_lat, current_lon);
        printf("Distance to destination: %f km\n", distance);
    }
    printf("Total distance traveled: %f km\n", total_distance);

    return 0;
}