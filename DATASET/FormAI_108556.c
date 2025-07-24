//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOCATIONS 10

struct location {
    double latitude;
    double longitude;
    char name[256];
};

struct location locations[MAX_LOCATIONS];

int num_locations = 0;

void add_location(double lat, double lon, const char *name) {
    if (num_locations < MAX_LOCATIONS) {
        locations[num_locations].latitude = lat;
        locations[num_locations].longitude = lon;
        snprintf(locations[num_locations].name, sizeof(locations[num_locations].name), "%s", name);
        num_locations++;
    } else {
        printf("Cannot add location %s, maximum number of locations reached.\n", name);
    }
}

void list_locations() {
    printf("List of Locations:\n");
    for (int i = 0; i < num_locations; i++) {
        printf("%d. %s (Lat: %f, Lon: %f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

int main() {
    add_location(40.7128, -74.0060, "New York");
    add_location(51.5074, -0.1278, "London");
    add_location(35.6895, 139.6917, "Tokyo");

    list_locations();

    return 0;
}