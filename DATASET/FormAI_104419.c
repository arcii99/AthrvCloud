//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define EARTH_RADIUS 6371.0 // in km
#define PI 3.14159265359

// Structure to hold GPS co-ordinates
typedef struct{
    double latitude;
    double longitude;
}Coordinate;

// Function to convert degrees to radians
double convertToRadians(double degree){
    return (degree*PI)/180;
}

// Function to calculate distance between two GPS coordinates
double calculateDistance(Coordinate c1, Coordinate c2){
    double lat1 = convertToRadians(c1.latitude);
    double long1 = convertToRadians(c1.longitude);
    double lat2 = convertToRadians(c2.latitude);
    double long2 = convertToRadians(c2.longitude);
    double deltaLong = long2 - long1;

    double d = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(deltaLong)) * EARTH_RADIUS; // Haversine formula
    
    return d;
}

int main(){
    Coordinate currentLocation;
    currentLocation.latitude = 37.7749;
    currentLocation.longitude = -122.4194;

    Coordinate destination;
    destination.latitude = 40.7128;
    destination.longitude = -74.0060;

    double distance = calculateDistance(currentLocation, destination);

    printf("The distance between current location (%lf, %lf) and destination (%lf, %lf) is %lf km.", currentLocation.latitude, currentLocation.longitude, destination.latitude, destination.longitude, distance);

    return 0;
}