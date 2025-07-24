//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to store GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} GPSCoordinates;

// Function to calculate the distance between two coordinates using the Haversine Formula
double calculateDistance(GPSCoordinates coord1, GPSCoordinates coord2) {
    double earthRadius = 6371;  // Kilometers
    double dLat = (coord2.latitude - coord1.latitude) * M_PI / 180;
    double dLon = (coord2.longitude - coord1.longitude) * M_PI / 180;
    double lat1 = coord1.latitude * M_PI / 180;
    double lat2 = coord2.latitude * M_PI / 180;

    double a = sin(dLat/2) * sin(dLat/2) + sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = earthRadius * c;

    return distance;
}

int main() {
    // Coordinates of the starting and destination points
    GPSCoordinates startPoint = {44.968046, -94.420307};
    GPSCoordinates endPoint = {44.33328, -89.132008};
    
    // Display the starting point GPS coordinates
    printf("Starting Point: (%f, %f)\n", startPoint.latitude, startPoint.longitude);
    
    // Display the destination point GPS coordinates
    printf("Destination Point: (%f, %f)\n", endPoint.latitude, endPoint.longitude);

    // Calculate the distance between the two points
    double distance = calculateDistance(startPoint, endPoint);
    printf("Distance between the two points: %f km\n", distance);

    // Simulate the GPS navigation
    printf("Starting navigation...\n");
    GPSCoordinates currentLocation = startPoint;
    int counter = 0;
    while (distance > 0.1) {
        counter++;
        printf("Step %d - Current location: (%f, %f)\n", counter, currentLocation.latitude, currentLocation.longitude);
        
        // Calculate the bearing (direction) from the current location to the destination
        double dLat = (endPoint.latitude - currentLocation.latitude) * M_PI / 180;
        double dLon = (endPoint.longitude - currentLocation.longitude) * M_PI / 180;
        double currentLat = currentLocation.latitude * M_PI / 180;
        double endLat = endPoint.latitude * M_PI / 180;

        double y = sin(dLon) * cos(endLat);
        double x = cos(currentLat) * sin(endLat) - sin(currentLat) * cos(endLat) * cos(dLon);
        double bearing = atan2(y, x) * 180 / M_PI;

        // Move towards the destination based on the bearing and distance covered
        double bearingRadians = bearing * M_PI / 180;
        double coveredDistance = 0.2; // Kilometers
        double latRadians = currentLocation.latitude * M_PI / 180;
        double lonRadians = currentLocation.longitude * M_PI / 180;

        double newLat = asin(sin(latRadians) * cos(coveredDistance/6371) + cos(latRadians) * sin(coveredDistance/6371) * cos(bearingRadians));
        double newLon = lonRadians + atan2(sin(bearingRadians) * sin(coveredDistance/6371) * cos(latRadians), cos(coveredDistance/6371) - sin(latRadians) * sin(newLat));

        // Update the current location
        currentLocation.latitude = newLat * 180 / M_PI;
        currentLocation.longitude = newLon * 180 / M_PI;

        // Recalculate the distance between the current location and the destination
        distance = calculateDistance(currentLocation, endPoint);
    }

    // Display the arrival message
    printf("You have reached your destination!\n");

    return 0;
}