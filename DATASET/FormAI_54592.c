//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* locationName;
    double latitude;
    double longitude;
} Location;

typedef struct {
    char* instruction;
    Location location;
    double distance;
} Navigation;

void printNavigation(Navigation* navigation) {
    printf("%s: Go to %s, which is %.2lfkm away at (%.6lf, %.6lf)\n", 
        navigation->instruction, navigation->location.locationName, navigation->distance, 
        navigation->location.latitude, navigation->location.longitude);
}

int main() {
    int numLocations = 5;
    const double EARTH_RADIUS = 6371.0; // in km
    char* searchQuery = "Stockholm";
    Location locations[5] = {
        {"Göteborg", 57.719668, 11.950507},
        {"Stockholm", 59.326232, 18.073676},
        {"Malmö", 55.605127, 13.003906},
        {"Umeå", 63.825848, 20.266477},
        {"Lund", 55.702357, 13.192314}
    };

    // Search for location
    int searchIndex = -1;
    for (int i = 0; i < numLocations; i++) {
        if (strcmp(locations[i].locationName, searchQuery) == 0) {
            searchIndex = i;
            break;
        }
    }
    if (searchIndex == -1) {
        printf("Error: Could not find location '%s'\n", searchQuery);
        return 1;
    }

    // Calculate distances and generate navigation
    Navigation navigations[4];
    double distance;
    for (int i = 0; i < numLocations; i++) {
        if (i == searchIndex) continue;
        distance = EARTH_RADIUS * acos(sin(locations[i].latitude) * sin(locations[searchIndex].latitude) + 
            cos(locations[i].latitude) * cos(locations[searchIndex].latitude) * cos(locations[searchIndex].longitude - locations[i].longitude));
        if (distance <= 150.0) {
            navigations[i < searchIndex ? i : i - 1].instruction = "Turn left";
            navigations[i < searchIndex ? i : i - 1].location = locations[i];
            navigations[i < searchIndex ? i : i - 1].distance = distance;
        } else if (distance <= 300.0) {
            navigations[i < searchIndex ? i : i - 1].instruction = "Turn right";
            navigations[i < searchIndex ? i : i - 1].location = locations[i];
            navigations[i < searchIndex ? i : i - 1].distance = distance;
        } else {
            navigations[i < searchIndex ? i : i - 1].instruction = "Continue straight";
            navigations[i < searchIndex ? i : i - 1].location = locations[i];
            navigations[i < searchIndex ? i : i - 1].distance = distance;
        }
    }

    // Print navigation instructions
    printf("Starting at %s:\n", searchQuery);
    for (int i = 0; i < 4; i++) {
        printNavigation(&navigations[i]);
    }

    return 0;
}