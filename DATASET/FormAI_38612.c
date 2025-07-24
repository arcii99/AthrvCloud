//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Constants for the Earth's radius and for the conversion between degrees and radians.
#define EARTH_RADIUS 6371
#define DEG_TO_RAD (M_PI / 180.0)

// A custom 'Location' struct to represent each waypoint with its name, latitude, and longitude.
typedef struct Location {
    char name[50];
    double latitude;
    double longitude;
} Location;

/**
 * Calculates the distance in kilometers between two locations on Earth using the Haversine formula.
 * @param loc1 - the starting location
 * @param loc2 - the destination location
 * @return the distance in kilometers rounded to one decimal place
 */
double calculateDistance(Location loc1, Location loc2) {
    double dlat = (loc2.latitude - loc1.latitude) * DEG_TO_RAD;
    double dlon = (loc2.longitude - loc1.longitude) * DEG_TO_RAD;
    double a = pow(sin(dlat / 2), 2) + cos(loc1.latitude * DEG_TO_RAD)
                                        * cos(loc2.latitude * DEG_TO_RAD)
                                        * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    return round(distance * 10) / 10;
}

/**
 * Finds the closest location in the given array to the specified location.
 * @param loc - the location to find closest to
 * @param locations - the array of locations to search through
 * @param numLocations - the number of locations in the array
 * @return the index of the closest location in the array
 */
int findClosestLocation(Location loc, Location locations[], int numLocations) {
    int closestIndex = 0;
    double closestDistance = calculateDistance(loc, locations[closestIndex]);
    for (int i = 1; i < numLocations; i++) {
        double distance = calculateDistance(loc, locations[i]);
        if (distance < closestDistance) {
            closestIndex = i;
            closestDistance = distance;
        }
    }
    return closestIndex;
}

/**
 * Simulates GPS navigation by finding the optimal route between a starting and destination location
 * and displaying turn-by-turn directions.
 * @param startLoc - the starting location
 * @param destLoc - the destination location
 * @param locations - the array of waypoints to travel through
 * @param numLocations - the number of waypoints in the array
 */
void simulateNavigation(Location startLoc, Location destLoc, Location locations[], int numLocations) {
    // Print out the travel plan.
    printf("Travel Plan:\n");
    printf("  Starting at %s\n", startLoc.name);
    printf("  Destination: %s\n", destLoc.name);

    // Calculate the closest waypoint to the starting and destination locations.
    int startWaypointIndex = findClosestLocation(startLoc, locations, numLocations);
    int destWaypointIndex = findClosestLocation(destLoc, locations, numLocations);

    // Check if the starting and destination waypoints are the same.
    if (startWaypointIndex == destWaypointIndex) {
        printf("\nYou are already at your destination!");
        return;
    }

    // Find the optimal route using a greedy algorithm, starting at the starting location
    // and repeatedly visiting the closest unvisited waypoint until the destination is reached.
    int visited[numLocations];
    memset(visited, 0, sizeof visited);
    visited[startWaypointIndex] = 1;
    int currentWaypointIndex = startWaypointIndex;
    double totalDistance = 0;
    printf("\nDirections: \n");
    while (currentWaypointIndex != destWaypointIndex) {
        int closestIndex = -1;
        double closestDistance = INFINITY;
        for (int i = 0; i < numLocations; i++) {
            if (!visited[i]) {
                double distance = calculateDistance(locations[currentWaypointIndex], locations[i]);
                if (distance < closestDistance) {
                    closestIndex = i;
                    closestDistance = distance;
                }
            }
        }
        visited[closestIndex] = 1;
        totalDistance += closestDistance;
        printf("  Go to %s (%.1f km)\n", locations[closestIndex].name, closestDistance);
        currentWaypointIndex = closestIndex;
    }

    // Print out the final route and total distance.
    printf("\nRoute: %s", startLoc.name);
    currentWaypointIndex = startWaypointIndex;
    while (currentWaypointIndex != destWaypointIndex) {
        int closestIndex = -1;
        double closestDistance = INFINITY;
        for (int i = 0; i < numLocations; i++) {
            if (!visited[i]) {
                double distance = calculateDistance(locations[currentWaypointIndex], locations[i]);
                if (distance < closestDistance) {
                    closestIndex = i;
                    closestDistance = distance;
                }
            }
        }
        visited[closestIndex] = 1;
        printf(" > %s", locations[closestIndex].name);
        currentWaypointIndex = closestIndex;
    }
    printf(" > %s\n", destLoc.name);
    printf("Total Distance: %.1f km", totalDistance);
}

// Test program with sample locations.
int main() {
    // Define the locations with their names, latitudes, and longitudes.
    Location startLoc = {"My House", 52.520008, 13.404954};
    Location destLoc = {"Berlin Zoo", 52.507684, 13.337862};
    Location locations[] = {
            {"Brandenburg Gate", 52.516275, 13.377704},
            {"Checkpoint Charlie", 52.507576, 13.390374},
            {"Potsdamer Platz", 52.509648, 13.376254},
            {"Alexanderplatz", 52.521918, 13.413215},
    };
    int numLocations = sizeof locations / sizeof(Location);

    // Simulate navigation from the starting location to the destination location.
    simulateNavigation(startLoc, destLoc, locations, numLocations);
    return 0;
}