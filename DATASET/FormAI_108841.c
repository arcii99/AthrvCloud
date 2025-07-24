//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct GPS_Location {
    float latitude;
    float longitude;
} GPS_Location;

float calculate_distance(GPS_Location A, GPS_Location B) {
    float lat_diff = A.latitude - B.latitude;
    float lon_diff = A.longitude - B.longitude;
    return sqrtf(lat_diff * lat_diff + lon_diff * lon_diff);
}

int main() {
    srand(time(NULL));
    GPS_Location current_location = { 42.3601f, -71.0589f };
    GPS_Location destination_location = { 37.7749f, -122.4194f };
    printf("You are currently at (%f, %f)\n", current_location.latitude, current_location.longitude);
    float distance_to_destination = calculate_distance(current_location, destination_location);
    printf("The distance to your destination is %f kilometers\n", distance_to_destination);
    while (distance_to_destination > 0.1f) {
        // Simulate movement
        float lat_offset = (rand() % 21 + 10) / 10000.0f;
        float lon_offset = (rand() % 21 + 10) / 10000.0f;
        if (rand() % 2 == 0) {
            lat_offset *= -1;
        }
        if (rand() % 2 == 0) {
            lon_offset *= -1;
        }
        current_location.latitude += lat_offset;
        current_location.longitude += lon_offset;
        distance_to_destination = calculate_distance(current_location, destination_location);
        printf("You moved to (%f, %f), distance remaining: %f kilometers\n",
               current_location.latitude, current_location.longitude, distance_to_destination);
    }
    printf("You have arrived at your destination!");
    return 0;
}