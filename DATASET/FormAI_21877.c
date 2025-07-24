//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants for the maximum and minimum latitude and longitude values */
#define MAX_LATITUDE 90
#define MIN_LATITUDE -90
#define MAX_LONGITUDE 180
#define MIN_LONGITUDE -180

/* Function declarations */
double getRandomCoordinate(double min, double max);
void simulateGPSNavigation(double currentLatitude, double currentLongitude, double destinationLatitude, double destinationLongitude);

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Set the current location to a random coordinate */
    double currentLatitude = getRandomCoordinate(MIN_LATITUDE, MAX_LATITUDE);
    double currentLongitude = getRandomCoordinate(MIN_LONGITUDE, MAX_LONGITUDE);

    /* Set the destination to a random coordinate */
    double destinationLatitude = getRandomCoordinate(MIN_LATITUDE, MAX_LATITUDE);
    double destinationLongitude = getRandomCoordinate(MIN_LONGITUDE, MAX_LONGITUDE);

    /* Print out the starting location */
    printf("Current location: (%lf, %lf)\n", currentLatitude, currentLongitude);

    /* Begin the navigation simulation */
    simulateGPSNavigation(currentLatitude, currentLongitude, destinationLatitude, destinationLongitude);

    return 0;
}

/* Generates a random coordinate between min and max */
double getRandomCoordinate(double min, double max) {
    return ((double)rand() / RAND_MAX * (max - min)) + min;
}

/* Simulates the GPS navigation from current location to destination */
void simulateGPSNavigation(double currentLatitude, double currentLongitude, double destinationLatitude, double destinationLongitude) {
    int timeElapsed = 0; // Track the time elapsed since the navigation began
    double distanceTraveled = 0; // Track the distance traveled from the starting location
    double distanceToDestination = 0; // Track the distance to the destination
    double speed = 50.0; // Set the speed to 50 kilometers per hour

    while (distanceToDestination > 0 || timeElapsed == 0) {
        printf("Time elapsed: %d seconds\n", timeElapsed);

        /* Calculate the distance to the destination */
        double latitudeDifference = destinationLatitude - currentLatitude;
        double longitudeDifference = destinationLongitude - currentLongitude;
        distanceToDestination = sqrt(latitudeDifference*latitudeDifference + longitudeDifference*longitudeDifference);

        /* Print out the distance to the destination */
        printf("Distance to destination: %lf kilometers\n", distanceToDestination);

        /* Calculate the distance traveled and update the current location */
        distanceTraveled += speed / 3600; // Convert from kilometers per hour to kilometers per second
        double bearing = atan2(longitudeDifference, latitudeDifference); // Calculate the bearing
        currentLatitude += (distanceTraveled * cos(bearing)); // Update the current latitude
        currentLongitude += (distanceTraveled * sin(bearing)); // Update the current longitude

        /* Print out the current location */
        printf("Current location: (%lf, %lf)\n\n", currentLatitude, currentLongitude);

        /* Increment the time elapsed */
        timeElapsed++;
    }

    printf("Arrived at destination in %d seconds!\n", timeElapsed);
}