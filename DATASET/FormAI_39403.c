//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.1415926535
#define EARTH_RADIUS 6371.0

// Function prototypes
double degToRad(double);
double getDistance(double, double, double, double);
double getBearing(double, double, double, double);
void simulateNavigation(double, double, double, double);

int main() {
    double latitude1, longitude1, latitude2, longitude2;
    srand(time(NULL)); // Seed the random number generator

    latitude1 = (double) (rand() % 181 - 90); // Generate random starting latitude
    longitude1 = (double) (rand() % 361 - 180); // Generate random starting longitude
    latitude2 = (double) (rand() % 181 - 90); // Generate random destination latitude
    longitude2 = (double) (rand() % 361 - 180); // Generate random destination longitude

    printf("Starting Latitude: %.4f\n", latitude1);
    printf("Starting Longitude: %.4f\n", longitude1);
    printf("Destination Latitude: %.4f\n", latitude2);
    printf("Destination Longitude: %.4f\n", longitude2);

    simulateNavigation(latitude1, longitude1, latitude2, longitude2);

    return 0;
}

/*
    Function to convert degrees to radians
*/
double degToRad(double degrees) {
    return degrees * (PI / 180.0);
}

/*
    Function to calculate the distance between two points on the surface of the Earth
*/
double getDistance(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat, deltaLon, a, c;

    deltaLat = degToRad(lat2 - lat1);
    deltaLon = degToRad(lon2 - lon1);

    a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos(degToRad(lat1)) * cos(degToRad(lat2)) * sin(deltaLon / 2) * sin(deltaLon / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

/*
    Function to calculate the bearing from point 1 to point 2
*/
double getBearing(double lat1, double lon1, double lat2, double lon2) {
    double y = sin(degToRad(lon2-lon1)) * cos(degToRad(lat2));
    double x = cos(degToRad(lat1)) * sin(degToRad(lat2)) -
              sin(degToRad(lat1)) * cos(degToRad(lat2)) * cos(degToRad(lon2-lon1));
    double bearing = atan2(y, x);

    return fmod((bearing + 2 * PI), (2* PI));
}

/*
    Function to simulate the navigation process
*/
void simulateNavigation(double lat1, double lon1, double lat2, double lon2) {
    double distance, bearing;
    int timeElapsed = 0;

    distance = getDistance(lat1, lon1, lat2, lon2);
    bearing = getBearing(lat1, lon1, lat2, lon2);

    printf("\nStarting Navigation...\n");
    printf("Distance to Destination: %.2f km\n", distance);
    printf("Initial Bearing: %.2f degrees\n", bearing * (180 / PI));

    while (distance > 0) {
        double speed = (rand() % 30 + 40) / 3.6; // Random speed between 40 km/h and 70 km/h
        int time = rand() % 11 + 5; // Random time between 5 minutes and 15 minutes
        double distanceCovered = speed * (time * 60); // Calculate distance covered in km

        lat1 = lat2;
        lon1 = lon2;

        lat2 = lat2 + (distanceCovered / 1000.0) * sin(bearing);
        lon2 = lon2 + (distanceCovered / 1000.0) * cos(bearing) / cos(lat2 * PI / 180.0);
        distance = getDistance(lat1, lon1, lat2, lon2);
        bearing = getBearing(lat1, lon1, lat2, lon2);
        timeElapsed += time;

        printf("\nElapsed Time: %d minutes\n", timeElapsed);
        printf("Speed: %.2f km/h\n", speed * 3.6);
        printf("Distance to Destination: %.2f km\n", distance);
        printf("Current Bearing: %.2f degrees\n", bearing * (180 / PI));
        printf("Current Latitude: %.4f\n", lat2);
        printf("Current Longitude: %.4f\n", lon2);
    }

    printf("\nArrived at Destination!\n");
}