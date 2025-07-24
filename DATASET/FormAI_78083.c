//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

void printLocations(Location locations[], int numLocations);
int getClosestLocation(Location locations[], int numLocations, double latitude, double longitude);

int main() {
    Location locations[MAX_LOCATIONS] = {
        {"New York", 40.7128, -74.0060},
        {"Los Angeles", 34.0522, -118.2437},
        {"Chicago", 41.8781, -87.6298},
        {"Houston", 29.7604, -95.3698},
        {"Phoenix", 33.4484, -112.0740},
        {"Philadelphia", 39.9526, -75.1652},
        {"San Antonio", 29.4241, -98.4936},
        {"San Diego", 32.7157, -117.1611},
        {"Dallas", 32.7767, -96.7970},
        {"San Jose", 37.3382, -121.8863}
    };
    int numLocations = 10;
    double latitude, longitude;
    
    printf("Welcome to GPS Navigation Simulation!\n\n");
    printLocations(locations, numLocations);
    
    while (true) {
        printf("\nPlease enter your current location's latitude (-90 to 90): ");
        scanf("%lf", &latitude);
        
        if (latitude < -90 || latitude > 90) {
            printf("Invalid latitude! Please enter a value between -90 and 90.\n");
            continue;
        }
        
        printf("Please enter your current location's longitude (-180 to 180): ");
        scanf("%lf", &longitude);
        
        if (longitude < -180 || longitude > 180) {
            printf("Invalid longitude! Please enter a value between -180 and 180.\n");
            continue;
        }
        
        int closestLocationIndex = getClosestLocation(locations, numLocations, latitude, longitude);
        Location closestLocation = locations[closestLocationIndex];
        
        printf("\nClosest location to your current location (%.4f, %.4f) is '%s' at latitude %.4f and longitude %.4f.\n", 
            latitude, longitude, closestLocation.name, closestLocation.latitude, closestLocation.longitude);
    }
    
    return 0;
}

void printLocations(Location locations[], int numLocations) {
    printf("Available locations:\n");
    for (int i = 0; i < numLocations; i++) {
        printf("%d. %s (latitude: %.4f, longitude: %.4f)\n", i+1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

int getClosestLocation(Location locations[], int numLocations, double latitude, double longitude) {
    int closestLocationIndex = 0;
    double closestDistance = __DBL_MAX__;
    
    for (int i = 0; i < numLocations; i++) {
        double distance = sqrt(pow(locations[i].latitude - latitude, 2) + pow(locations[i].longitude - longitude, 2));
        
        if (distance < closestDistance) {
            closestDistance = distance;
            closestLocationIndex = i;
        }
    }
    
    return closestLocationIndex;
}