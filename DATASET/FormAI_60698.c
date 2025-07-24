//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct location {
    double latitude; //in degrees
    double longitude; //in degrees
} Location;

typedef struct distance {
    double distanceKM; //in Kilometers
    double distanceMiles; //in Miles
} Distance;

//helper function to convert degrees to radians
double deg2rad(double deg) {
    return (deg * PI / 180);
}

//helper function to calculate distance between two locations
Distance calcDistance(Location loc1, Location loc2) {
    double dlon = deg2rad(loc2.longitude - loc1.longitude);
    double dlat = deg2rad(loc2.latitude - loc1.latitude);
    double a = pow(sin(dlat / 2), 2) + cos(deg2rad(loc1.latitude)) * cos(deg2rad(loc2.latitude)) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    Distance dist;
    dist.distanceKM = 6371 * c;
    dist.distanceMiles = 3956 * c;
    return dist;
}

int main() {
    //start location
    Location currentLoc = { 37.7749, -122.4194 };
    printf("Current Location: %.4f, %.4f\n", currentLoc.latitude, currentLoc.longitude);

    //destination location
    Location destLoc = { 40.7128, -74.0060 };
    printf("Destination: %.4f, %.4f\n", destLoc.latitude, destLoc.longitude);

    //calculation of distance between two points
    Distance dist = calcDistance(currentLoc, destLoc);
    printf("Distance to Destination: %.2f KM / %.2f Miles\n", dist.distanceKM, dist.distanceMiles);
    
    //simulate navigation by creating a fake GPS movement
    double currentLat = currentLoc.latitude;
    double currentLong = currentLoc.longitude;
    printf("Starting Navigation...\n");
    for (int i = 1; i <= 3; i++) {
        printf("Movement #%d:\n", i);
        double newLat = currentLat + (destLoc.latitude - currentLat) / 4;
        double newLong = currentLong + (destLoc.longitude - currentLong) / 4;
        Location newLoc = { newLat, newLong };
        printf("New Location: %.4f, %.4f\n", newLoc.latitude, newLoc.longitude);
        Distance newDist = calcDistance(newLoc, destLoc);
        printf("Distance Remaining: %.2f KM / %.2f Miles\n", newDist.distanceKM, newDist.distanceMiles);
        if (newDist.distanceKM < 1) {
            printf("Arrived at Destination!\n");
            break;
        }
        currentLat = newLat;
        currentLong = newLong;
    }

    return 0;
}