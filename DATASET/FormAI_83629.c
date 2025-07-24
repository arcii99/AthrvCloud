//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_ROUTE_SIZE 100 // maximum number of waypoints for the route
#define MAX_NAME_SIZE 50 // maximum size of the name of a waypoint
#define EARTH_RADIUS 6371000 // average radius of the Earth in meters

typedef struct {
    double lat; // latitude in degrees
    double lon; // longitude in degrees
    char name[MAX_NAME_SIZE]; // name of the waypoint
} Waypoint;

Waypoint route[MAX_ROUTE_SIZE]; // array of waypoints for the route
int num_waypoints = 0; // number of waypoints in the route
double distance[MAX_ROUTE_SIZE]; // distance between each pair of waypoints in the route

// function to convert degrees to radians
double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// function to calculate the distance between two waypoints using the Haversine formula
double calcDistance(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat = toRadians(lat2 - lat1);
    double deltaLon = toRadians(lon2 - lon1);
    double a = sin(deltaLat / 2) * sin(deltaLat / 2)
        + cos(toRadians(lat1)) * cos(toRadians(lat2))
        * sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// function to print all the waypoints in the route
void printRoute() {
    printf("Route:\n");
    for (int i = 0; i < num_waypoints; i++) {
        printf("%s (%.6f, %.6f)\n", route[i].name, route[i].lat, route[i].lon);
    }
    printf("\n");
}

// function to calculate the total distance of the route
double calcRouteDistance() {
    double total_distance = 0;
    for (int i = 0; i < num_waypoints - 1; i++) {
        double lat1 = route[i].lat;
        double lon1 = route[i].lon;
        double lat2 = route[i + 1].lat;
        double lon2 = route[i + 1].lon;
        double d = calcDistance(lat1, lon1, lat2, lon2);
        distance[i] = d;
        total_distance += d;
    }
    distance[num_waypoints - 1] = 0; // set distance of last waypoint to zero
    return total_distance;
}

// function to simulate a GPS navigation
void gpsNavigation() {
    double current_lat = route[0].lat;
    double current_lon = route[0].lon;
    double total_distance = calcRouteDistance();
    double remaining_distance = total_distance;
    printf("Starting GPS navigation:\n");
    for (int i = 0; i < num_waypoints - 1; i++) {
        printf("Go straight for %.2f meters to %s\n", distance[i], route[i+1].name);
        remaining_distance -= distance[i];
        printf("%.2f meters remaining to destination\n", remaining_distance);
    }
    printf("Arrived at destination\n");
}

int main() {
    // define some waypoints
    Waypoint wp1 = { 43.655140, -79.380400, "Toronto" };
    Waypoint wp2 = { 45.501690, -73.567250, "Montreal" };
    Waypoint wp3 = { 51.045350, -114.058170, "Calgary" };
    Waypoint wp4 = { 49.282730, -123.120735, "Vancouver" };
    
    // add the waypoints to the route
    route[num_waypoints++] = wp1;
    route[num_waypoints++] = wp2;
    route[num_waypoints++] = wp3;
    route[num_waypoints++] = wp4;
    
    // print the route and calculate the total distance
    printRoute();
    double total_distance = calcRouteDistance();
    printf("Total distance of the route: %.2f meters\n\n", total_distance);
    
    // simulate GPS navigation
    gpsNavigation();
    
    return 0;
}