//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct location {
    double latitude;
    double longitude;
};

double calculate_distance(struct location location1, struct location location2) {
    double lat_diff = abs(location1.latitude - location2.latitude);
    double long_diff = abs(location1.longitude - location2.longitude);
    return sqrt((lat_diff * lat_diff) + (long_diff * long_diff));
}

int main() {
    struct location current_location = {40.712776, -74.005974}; // starting location: New York City
    struct location destination_1 = {37.774929, -122.419416}; // San Francisco
    struct location destination_2 = {51.507351, -0.127758}; // London
    struct location destination_3 = {35.689487, 139.691711}; // Tokyo
    
    double distance_1 = calculate_distance(current_location, destination_1);
    double distance_2 = calculate_distance(current_location, destination_2);
    double distance_3 = calculate_distance(current_location, destination_3);
    
    printf("Current location: (%f, %f)\n", current_location.latitude, current_location.longitude);
    
    // Determine which location is closest
    double min_distance = distance_1;
    struct location closest_location = destination_1;
    
    if (distance_2 < min_distance) {
        min_distance = distance_2;
        closest_location = destination_2;
    }
    if (distance_3 < min_distance) {
        min_distance = distance_3;
        closest_location = destination_3;
    }
    
    printf("Closest location: (%f, %f)\n", closest_location.latitude, closest_location.longitude);
    printf("Distance to closest location: %f\n", min_distance);
    
    return 0;
}