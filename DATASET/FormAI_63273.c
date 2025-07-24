//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <math.h>

/* Define constants */
#define PI 3.14159265359
#define EARTH_RADIUS 6371000 /* in meters */

/* Define custom data types */
typedef struct {
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location origin;
    Location destination;
    double distance; /* in meters */
} Route;

/* Define function prototypes */
double toRadians(double degrees);
double calculateDistance(Location origin, Location destination);
Route getRoute(Location origin, Location destination);
void printLocation(Location location);
void printRoute(Route route);

/* Main function */
int main() {
    Location here = {40.7128, -74.0060}; /* New York City coordinates */
    Location there = {37.7749, -122.4194}; /* San Francisco coordinates */
    
    Route route = getRoute(here, there);
    printRoute(route);
    
    return 0;
}

/* Convert degrees to radians */
double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

/* Calculate distance between two locations using Haversine formula */
double calculateDistance(Location origin, Location destination) {
    double lat1 = toRadians(origin.latitude);
    double lat2 = toRadians(destination.latitude);
    double lon1 = toRadians(origin.longitude);
    double lon2 = toRadians(destination.longitude);
    
    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;
    
    double a = pow(sin(deltaLat / 2), 2) + 
               cos(lat1) * cos(lat2) * pow(sin(deltaLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return EARTH_RADIUS * c;
}

/* Get the route between two locations */
Route getRoute(Location origin, Location destination) {
    double distance = calculateDistance(origin, destination);
    Route route = {origin, destination, distance};
    return route;
}

/* Print a location to the console */
void printLocation(Location location) {
    printf("Location: %.4f, %.4f\n", location.latitude, location.longitude);
}

/* Print a route to the console */
void printRoute(Route route) {
    printf("Route:\n");
    printLocation(route.origin);
    printLocation(route.destination);
    printf("Distance: %.2f meters\n", route.distance);
}