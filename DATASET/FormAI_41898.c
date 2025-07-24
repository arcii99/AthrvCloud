//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: peaceful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to calculate distance between two points
double distance(double lat1, double lon1, double lat2, double lon2) {
    int R = 6371; // Radius of the Earth in km
    double dLat = (lat2 - lat1) * M_PI / 180;
    double dLon = (lon2 - lon1) * M_PI / 180;
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = R * c;
    return d;
}

// Function to generate random GPS coordinates in a given range
double getRandomCoordinate(double minVal, double maxVal) {
    double range = maxVal - minVal;
    double randomVal = (double) rand() / RAND_MAX;
    return (minVal + randomVal * range);
}

// Function to simulate GPS navigation
void simulateNavigation(double startLat, double startLon, double endLat, double endLon) {
    double distanceToDestination = distance(startLat, startLon, endLat, endLon);
    printf("The distance to your destination is %.2f km\n", distanceToDestination);
    
    // Set max distance the user can travel in one step to 5% of total distance
    double stepSize = distanceToDestination * 0.05;
    double currentLat = startLat;
    double currentLon = startLon;
    bool reachedDestination = false;
    
    // Loop until destination is reached
    while (!reachedDestination) {
        // Generate random coordinates for next step
        double nextLat = getRandomCoordinate(currentLat - stepSize, currentLat + stepSize);
        double nextLon = getRandomCoordinate(currentLon - stepSize, currentLon + stepSize);
        double distanceToNext = distance(currentLat, currentLon, nextLat, nextLon);
        
        // Check if next step will get user closer to destination
        if (distanceToNext < distanceToDestination) {
            currentLat = nextLat;
            currentLon = nextLon;
            distanceToDestination -= distanceToNext;
            printf("You travelled %.2f km and have %.2f km left until you reach your destination\n", distanceToNext, distanceToDestination);
        } else {
            reachedDestination = true;
            printf("Congratulations, you have reached your destination!\n");
        }
    }
}

int main() {
    srand(time(0)); // Seed random number generator with current time
    
    double startLat = getRandomCoordinate(-90, 90);
    double startLon = getRandomCoordinate(-180, 180);
    double endLat = getRandomCoordinate(-90, 90);
    double endLon = getRandomCoordinate(-180, 180);
    
    printf("Starting location: %.6f,%.6f\n", startLat, startLon);
    printf("Destination: %.6f,%.6f\n", endLat, endLon);
    
    simulateNavigation(startLat, startLon, endLat, endLon);
    
    return 0;
}