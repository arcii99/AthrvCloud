//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>

int main() {
    // initialize coordinates
    float currentLat = 37.7749;
    float currentLong = -122.4194;
    float destinationLat = 40.7128;
    float destinationLong = -74.0060;

    // distance tracking variables
    float totalDistance = 0.0;
    float currentDistance = 0.0;

    // loop until reach destination
    while (currentLat != destinationLat && currentLong != destinationLong) {
        // calculate distance using Haversine formula
        float latDiff = destinationLat - currentLat;
        float longDiff = destinationLong - currentLong;
        float a = pow(sin(latDiff/2),2) + cos(currentLat) * cos(destinationLat) * pow(sin(longDiff/2),2);
        float c = 2 * atan2(sqrt(a), sqrt(1-a));
        currentDistance = 6371 * c; // radius of Earth in km

        // update totalDistance
        totalDistance += currentDistance;

        // print update
        printf("Current distance: %.2f km\n", currentDistance);
        printf("Total distance traveled: %.2f km\n", totalDistance);

        // prompt for new coordinates
        printf("Enter new current latitude: ");
        scanf("%f", &currentLat);
        printf("Enter new current longitude: ");
        scanf("%f", &currentLong);

        // check if reached destination
        if (currentLat == destinationLat && currentLong == destinationLong) {
            printf("You have arrived at your destination!\n");
        }
    }

    return 0;
}