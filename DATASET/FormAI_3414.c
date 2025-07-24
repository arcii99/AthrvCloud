//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 // Define PI for use in calculations

struct GPSData {
    double latitude;
    double longitude;
};

struct Waypoint {
    char name[50];
    struct GPSData coordinates;
};

struct Route {
    struct Waypoint waypoints[10];
    int numWaypoints;
};

// Calculate the great circle distance between two GPS coordinates
double calculateDistance(struct GPSData p1, struct GPSData p2) {
    double lat1 = p1.latitude * PI / 180;
    double lat2 = p2.latitude * PI / 180;
    double long1 = p1.longitude * PI / 180;
    double long2 = p2.longitude * PI / 180;

    double dlat = lat2 - lat1;
    double dlong = long2 - long1;

    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;

    return d;
}

// Calculate the bearing between two GPS coordinates
double calculateBearing(struct GPSData p1, struct GPSData p2) {
    double lat1 = p1.latitude * PI / 180;
    double lat2 = p2.latitude * PI / 180;
    double long1 = p1.longitude * PI / 180;
    double long2 = p2.longitude * PI / 180;

    double dlong = long2 - long1;
    double y = sin(dlong) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlong);

    double bearing = atan2(y, x) * 180 / PI;

    return bearing;
}

// Navigate from one waypoint to another and return the distance and bearing
void navigate(struct Waypoint start, struct Waypoint end, double *distance, double *bearing) {
    *distance = calculateDistance(start.coordinates, end.coordinates);
    *bearing = calculateBearing(start.coordinates, end.coordinates);
}

int main() {
    struct GPSData currentLocation = {40.7128, -74.0060}; // New York City
    struct Route route = {
        .waypoints = {
            {"Statue of Liberty", {40.6892, -74.0445}},
            {"Central Park", {40.7851, -73.9683}},
            {"Empire State Building", {40.7484, -73.9857}}
        },
        .numWaypoints = 3
    };

    double distance, bearing;
    for (int i = 0; i < route.numWaypoints; i++) {
        navigate((i == 0) ? (struct Waypoint){"Current Location", currentLocation} : route.waypoints[i-1], route.waypoints[i], &distance, &bearing);
        printf("Navigate to: %s\nDistance: %.2f km\nBearing: %.2f degrees\n\n", route.waypoints[i].name, distance, bearing);
        currentLocation = route.waypoints[i].coordinates; // Update current location to this waypoint
    }

    return 0;
}