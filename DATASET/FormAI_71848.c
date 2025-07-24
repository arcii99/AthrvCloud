//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <math.h>

// Function to calculate distance between two points
double getDistance(double lat1, double long1, double lat2, double long2) {
    double distance, x, y;
    x = (long2 - long1) * cos((lat1 + lat2) / 2);
    y = lat2 - lat1;
    distance = sqrt(pow(x, 2) + pow(y, 2)) * 6371;
    return distance;
}

int main() {
    double currentLat, currentLong, destinationLat, destinationLong, distance;
    printf("Enter current latitude: ");
    scanf("%lf", &currentLat);
    printf("Enter current longitude: ");
    scanf("%lf", &currentLong);
    printf("Enter destination latitude: ");
    scanf("%lf", &destinationLat);
    printf("Enter destination longitude: ");
    scanf("%lf", &destinationLong);
    distance = getDistance(currentLat, currentLong, destinationLat, destinationLong);
    printf("Distance to Destination: %.2lf km\n", distance);
    if(distance > 10) {
        printf("You are far from the destination!\n");
    } else {
        printf("You have arrived at the destination!\n");
    }
    return 0;
}