//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
/* C GPS Navigation Simulation */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_LOCATIONS 10

// Location struct
struct Location {
    char name[50];
    double lat;
    double lon;
};

// Distance Calculation Function
double calculateDistance(struct Location loc1, struct Location loc2) {
    double R = 6371e3; // radius of earth in meters
    double phi1 = loc1.lat * M_PI / 180;
    double phi2 = loc2.lat * M_PI / 180;
    double deltaPhi = (loc2.lat - loc1.lat) * M_PI / 180;
    double deltaLambda = (loc2.lon - loc1.lon) * M_PI / 180;

    double a = sin(deltaPhi / 2) * sin(deltaPhi / 2) +
              cos(phi1) * cos(phi2) *
              sin(deltaLambda / 2) * sin(deltaLambda / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double d = R * c;

    return d;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Locations
    struct Location locations[MAX_LOCATIONS] = {
        {"Los Angeles", 34.0522, -118.2437},
        {"New York", 40.7128, -74.0060},
        {"Toronto", 43.6532, -79.3832},
        {"Austin", 30.2672, -97.7431},
        {"Seattle", 47.6062, -122.3321},
        {"Chicago", 41.8781, -87.6298},
        {"San Francisco", 37.7749, -122.4194},
        {"Vancouver", 49.2827, -123.1207},
        {"Denver", 39.7392, -104.9903},
        {"Miami", 25.7617, -80.1918}
    };

    int numLocations = sizeof(locations) / sizeof(locations[0]);

    // Choose two random locations
    int randIndex1 = rand() % numLocations;
    int randIndex2 = rand() % numLocations;
    while (randIndex2 == randIndex1) {
        randIndex2 = rand() % numLocations;
    }

    struct Location loc1 = locations[randIndex1];
    struct Location loc2 = locations[randIndex2];

    // Calculate distance between the two locations
    double distance = calculateDistance(loc1, loc2);

    // Print results
    printf("Starting Location: %s (%.4f, %.4f)\n", loc1.name, loc1.lat, loc1.lon);
    printf("Destination: %s (%.4f, %.4f)\n", loc2.name, loc2.lat, loc2.lon);
    printf("Distance: %.2f km\n", distance / 1000);

    return 0;
}