//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a GPS Coordinate struct
typedef struct {
    float latitude; // Stores the latitude of the coordinate
    float longitude; // Stores the longitude of the coordinate
} GPS_Coord;

// Define a function to generate random GPS coordinates
GPS_Coord generateRandomGPS() {
    GPS_Coord coord;
    // Generate a random latitude between -90 and 90
    coord.latitude = ((float)rand()/(float)(RAND_MAX)) * 180 - 90;
    // Generate a random longitude between -180 and 180
    coord.longitude = ((float)rand()/(float)(RAND_MAX)) * 360 - 180;
    return coord;
}

// Define a function to calculate the distance between two GPS coordinates
float calculateDistance(GPS_Coord coord1, GPS_Coord coord2) {
    // Convert latitude and longitude to radians
    float lat1 = coord1.latitude * 0.0174533;
    float lon1 = coord1.longitude * 0.0174533;
    float lat2 = coord2.latitude * 0.0174533;
    float lon2 = coord2.longitude * 0.0174533;
    // Calculate the difference between the two coordinates
    float r = 6371; // Radius of the earth in kilometers
    float dLat = lat2 - lat1;
    float dLon = lon2 - lon1;
    // Apply the haversine formula
    float a = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float distance = r * c;
    return distance;
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    // Generate three random GPS coordinates
    GPS_Coord currentLoc = generateRandomGPS();
    GPS_Coord destLoc = generateRandomGPS();
    GPS_Coord userLoc = generateRandomGPS();
    // Print out the coordinates to the console
    printf("Current Location: %f, %f\n", currentLoc.latitude, currentLoc.longitude);
    printf("Destination Location: %f, %f\n", destLoc.latitude, destLoc.longitude);
    printf("User Location: %f, %f\n", userLoc.latitude, userLoc.longitude);
    // Calculate the distance between the current location and destination
    float distance = calculateDistance(currentLoc, destLoc);
    printf("Distance to destination: %f km\n", distance);
    // Calculate the distance between the user location and destination
    float userDistance = calculateDistance(userLoc, destLoc);
    printf("Distance from user to destination: %f km\n", userDistance);
    // Calculate the estimated time to reach the destination
    float speed = 60; // km/h
    float time = distance / speed;
    printf("Estimated time of arrival: %f hours\n", time);
    // Determine if the user is within a 10 km radius of the destination
    if (userDistance <= 10) {
        printf("You are within 10 km of your destination!\n");
    } else {
        printf("You are not yet within 10 km of your destination.\n");
    }
    return 0;
}