//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>

// Structure to store GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} Coordinates;

// Function to calculate distance between two coordinates using Haversine formula
double distanceInKm(Coordinates c1, Coordinates c2) {
    double lat1Rad = c1.latitude * 3.14159 / 180;
    double lon1Rad = c1.longitude * 3.14159 / 180;
    double lat2Rad = c2.latitude * 3.14159 / 180;
    double lon2Rad = c2.longitude * 3.14159 / 180;

    double deltaLat = lat2Rad - lat1Rad;
    double deltaLon = lon2Rad - lon1Rad;

    double a = sin(deltaLat/2) * sin(deltaLat/2) + cos(lat1Rad) * cos(lat2Rad) * sin(deltaLon/2) * sin(deltaLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371 * c;

    return d;
}

int main() {
    // Define coordinates for destination
    Coordinates destination = {44.9778, -93.2650};

    // Give message and prompt user
    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Please enter your starting coordinates (latitude longitude): ");

    // Take input from user
    double startLat, startLong;
    scanf("%lf %lf", &startLat, &startLong);

    // Define starting coordinates
    Coordinates start = {startLat, startLong};

    // Calculate distance from starting coordinates to destination
    double distance = distanceInKm(start, destination);

    // Print distance and message to user
    printf("You are %lf km away from your destination.\n", distance);
    printf("Please follow the GPS directions to reach your destination.\n");

    return 0;
}