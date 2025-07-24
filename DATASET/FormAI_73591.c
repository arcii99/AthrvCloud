//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Define struct for coordinates
typedef struct {
    double lat;
    double lon;
} Coordinate;

// Function to convert degrees to radians
double degToRad(double degrees) {
    return degrees * PI / 180;
}

// Function to calculate distance between two coordinates using Haversine formula
double haversine(Coordinate coord1, Coordinate coord2) {
    double lat1 = degToRad(coord1.lat);
    double lat2 = degToRad(coord2.lat);
    double deltaLat = degToRad(coord2.lat - coord1.lat);
    double deltaLon = degToRad(coord2.lon - coord1.lon);

    double a = pow(sin(deltaLat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = 6371 * c; // Earth's radius in km

    return distance;
}

int main() {
    // Define coordinates for waypoints
    Coordinate start = {40.7128, -74.0060}; // New York, NY
    Coordinate waypoint1 = {37.7749, -122.4194}; // San Francisco, CA
    Coordinate waypoint2 = {51.5074, -0.1278}; // London, UK
    Coordinate end = {35.6895, 139.6917}; // Tokyo, Japan

    // Calculate distances between waypoints
    double distance1 = haversine(start, waypoint1);
    double distance2 = haversine(waypoint1, waypoint2);
    double distance3 = haversine(waypoint2, end);

    // Output distances between waypoints
    printf("Distance from New York, NY to San Francisco, CA: %.2f km\n", distance1);
    printf("Distance from San Francisco, CA to London, UK: %.2f km\n", distance2);
    printf("Distance from London, UK to Tokyo, Japan: %.2f km\n", distance3);

    // Calculate total distance of trip
    double totalDistance = distance1 + distance2 + distance3;

    // Output total distance of trip
    printf("Total distance of trip: %.2f km\n", totalDistance);

    return 0;
}