//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
#include <stdio.h>

struct location {
    float lat;
    float lon;
};

struct waypoint {
    char name[20];
    struct location loc;
};

void print_location(struct location loc) {
    printf("Latitude: %f, Longitude: %f\n", loc.lat, loc.lon);
}

void navigate(struct location current_loc, struct waypoint destination) {
    printf("Navigating from current location to %s\n", destination.name);
    print_location(current_loc);
    print_location(destination.loc);
}

int main() {
    struct location current_loc = {40.7128, -74.0060}; // New York City coordinates
    struct waypoint destination = {"Statue of Liberty", {40.6892, -74.0445}}; // Statue of Liberty coordinates
    
    navigate(current_loc, destination);
    
    return 0;
}