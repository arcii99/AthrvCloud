//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining the variables for the simulation
#define EARTH_RADIUS 6371000.0   // Earth radius in meters
#define PI 3.14159265358979323846  // Value of Pi
#define Turnings 4 // Number of turns

// Function to convert degrees to radians
double ConvertDegreesToRadians(double degrees) {
    double radians = (degrees * PI) / 180.0;
    return radians;
}

// Function to calculate distance between two GPS coordinates
double DistanceBetweenCoordinates(double startLatitude, double startLongitude, double endLatitude, double endLongitude) {
    double dLat = ConvertDegreesToRadians(endLatitude - startLatitude);
    double dLon = ConvertDegreesToRadians(endLongitude - startLongitude);
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(ConvertDegreesToRadians(startLatitude)) * cos(ConvertDegreesToRadians(endLatitude)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distanceInMeters = EARTH_RADIUS * c;
    return distanceInMeters;
}

// Function to calculate bearing between two GPS coordinates
double BearingBetweenCoordinates(double startLatitude, double startLongitude, double endLatitude, double endLongitude) {
    double dLat = ConvertDegreesToRadians(endLatitude - startLatitude);
    double dLon = ConvertDegreesToRadians(endLongitude - startLongitude);
    double y = sin(dLon) * cos(ConvertDegreesToRadians(endLatitude));
    double x = cos(ConvertDegreesToRadians(startLatitude)) * sin(ConvertDegreesToRadians(endLatitude)) - sin(ConvertDegreesToRadians(startLatitude)) * cos(ConvertDegreesToRadians(endLatitude)) * cos(dLon);
    double bearing = atan2(y, x);
    return bearing;
}

// Main function for the simulation
int main() {
    // Initializing the starting GPS coordinates
    double currentLatitude = 37.7749;
    double currentLongitude = -122.4194;

    // Initializing the ending GPS coordinates
    double destinationLatitude = 40.7128;
    double destinationLongitude = -74.0060;

    // Printing the starting GPS coordinates
    printf("Starting GPS Coordinates: (%lf, %lf)\n", currentLatitude, currentLongitude);

    // Printing the ending GPS coordinates
    printf("Ending GPS Coordinates: (%lf, %lf)\n", destinationLatitude, destinationLongitude);

    // Simulating the GPS Navigation for four turns
    for (int i = 0; i < Turnings; i++) {
        // Getting the distance and bearing between current and destination GPS coordinates
        double distance = DistanceBetweenCoordinates(currentLatitude, currentLongitude, destinationLatitude, destinationLongitude);
        double bearing = BearingBetweenCoordinates(currentLatitude, currentLongitude, destinationLatitude, destinationLongitude);

        // Printing the distance and bearing between current and destination GPS coordinates
        printf("Turn %d: Distance to destination: %lf m, bearing: %lf rad\n", i + 1, distance, bearing);

        // Updating the current GPS coordinates based on distance and bearing
        double deltaLatitude = distance / EARTH_RADIUS * cos(bearing);
        double deltaLongitude = distance / EARTH_RADIUS * sin(bearing);
        currentLatitude += deltaLatitude * 180.0 / PI;
        currentLongitude += deltaLongitude * 180.0 / PI;

        // Printing the updated GPS coordinates
        printf("Updated GPS Coordinates: (%lf, %lf)\n", currentLatitude, currentLongitude);
    }

    return 0;
}