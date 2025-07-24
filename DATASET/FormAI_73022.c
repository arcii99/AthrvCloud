//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

struct Location {
    double latitude;
    double longitude;
};

typedef struct Location Location;

double calc_distance(Location loc1, Location loc2) {
    double lat_diff = loc1.latitude - loc2.latitude;
    double lon_diff = loc1.longitude - loc2.longitude;
    double distance = sqrt(lat_diff*lat_diff + lon_diff*lon_diff);
    return distance;
}

void navigate(Location curr_pos, Location destination) {
    double distance_to_dest = calc_distance(curr_pos, destination);
    printf("Distance to destination is %.2f km\n", distance_to_dest);

    while (distance_to_dest > 0.1) {
        printf("Current position: %.5f, %.5f\n", curr_pos.latitude, curr_pos.longitude);
        printf("Enter new latitude: ");
        scanf("%lf", &curr_pos.latitude);
        printf("Enter new longitude: ");
        scanf("%lf", &curr_pos.longitude);

        distance_to_dest = calc_distance(curr_pos, destination);
        printf("Distance to destination is %.2f km\n", distance_to_dest);
    }

    printf("Destination reached! You have arrived at %.5f, %.5f\n", destination.latitude, destination.longitude);
}

int main() {
    Location curr_pos = {40.712776, -74.005974}; // New York City
    Location destination = {51.507351, -0.127758}; // London
    navigate(curr_pos, destination);
    return 0;
}