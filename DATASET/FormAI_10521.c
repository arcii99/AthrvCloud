//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate distance between two points using Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = (lat2 - lat1) * PI / 180.0;
    double dlon = (lon2 - lon1) * PI / 180.0;

    double a = pow(sin(dlat / 2), 2) + cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = 6371 * c;

    return distance;
}

// Function to simulate GPS navigation
void simulateNavigation() {
    // Starting point
    double currentLat = 37.7749;
    double currentLon = -122.4194;

    // Destination point
    double destinationLat = 37.3382;
    double destinationLon = -121.8863;

    // Navigation loop
    while (distance(currentLat, currentLon, destinationLat, destinationLon) > 0.1) {
        double bearing = atan2(sin(destinationLon - currentLon) * cos(destinationLat), cos(currentLat) * sin(destinationLat) - sin(currentLat) * cos(destinationLat) * cos(destinationLon - currentLon));
        double distanceToGo = distance(currentLat, currentLon, destinationLat, destinationLon);

        printf("Distance to destination: %0.2f km\n", distanceToGo);
        printf("Bearing to destination: %0.2f degrees\n", bearing * 180 / PI);

        // Move towards destination
        currentLat += sin(bearing) * 0.1 / 6371 * 180 / PI;
        currentLon += cos(bearing) * 0.1 / 6371 * 180 / PI / cos(currentLat * PI / 180.0);
    }

    printf("You have arrived at your destination.\n");
}

// Main function
int main() {
    simulateNavigation();

    return 0;
}