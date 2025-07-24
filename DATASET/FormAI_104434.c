//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
    double latitude;
    double longitude;
} Location;

// Calculates distance between two coordinates in meters
double calculateDistance(Location loc1, Location loc2) {
    double lat1 = loc1.latitude * PI / 180;
    double lat2 = loc2.latitude * PI / 180;
    double lon1 = loc1.longitude * PI / 180;
    double lon2 = loc2.longitude * PI / 180;
    
    double d = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1)) * 6371000;
    return d;
}

int main() {
    Location currentLoc = {37.7857, -122.4062};
    printf("Current Location: (%lf, %lf)\n", currentLoc.latitude, currentLoc.longitude);
    
    Location destLoc1 = {37.7749, -122.4194};
    Location destLoc2 = {37.8199, -122.4783};
    Location destLoc3 = {37.7877, -122.4205};
    
    double distToDest1 = calculateDistance(currentLoc, destLoc1);
    double distToDest2 = calculateDistance(currentLoc, destLoc2);
    double distToDest3 = calculateDistance(currentLoc, destLoc3);
    
    printf("Distance to Destination 1: %lf meters\n", distToDest1);
    printf("Distance to Destination 2: %lf meters\n", distToDest2);
    printf("Distance to Destination 3: %lf meters\n", distToDest3);
    
    // Navigate to closest destination
    Location closestDest;
    double minDist;
    
    if (distToDest1 < distToDest2 && distToDest1 < distToDest3) {
        closestDest = destLoc1;
        minDist = distToDest1;
    } else if (distToDest2 < distToDest1 && distToDest2 < distToDest3) {
        closestDest = destLoc2;
        minDist = distToDest2;
    } else {
        closestDest = destLoc3;
        minDist = distToDest3;
    }
    
    printf("Closest Destination: (%lf, %lf)\n", closestDest.latitude, closestDest.longitude);
    printf("Distance to closest Destination: %lf meters\n", minDist);
    
    return 0;
}