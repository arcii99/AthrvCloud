//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define NUM_WAYPOINTS 5 // number of waypoints in our route
#define MAP_RADIUS 50 // define the limit of the map (km)

// structure for representing GPS coordinates of a location.
typedef struct _Location {
    double latitude; // in degrees
    double longitude; // in degrees
} Location;

// structure for representing a journey from a starting location to an end location
typedef struct _Journey {
    Location start;
    Location end;
    double distance_km; // distance of journey in kilometers
} Journey;

// structure for representing a route consisting of multiple waypoints
typedef struct _Route {
    Location waypoints[NUM_WAYPOINTS];
    double total_distance_km; // total distance of the route in kilometers
} Route;

// function to generate a random point within a circular area
Location generate_random_point_in_circle(double radius_km, Location center) {
    // generate random angle between 0 to 2 * pi
    double angle_rad = (double)rand() / RAND_MAX * 2 * M_PI;
    // generate random distance between 0 to radius_km
    double distance_km = (double)rand() / RAND_MAX * radius_km;
    double delta_lat_deg = (distance_km / 111.12) * sin(angle_rad); // 111.12 km is the distance of 1 degree latitude
    double delta_lon_deg = (distance_km / (111.12 * cos(center.latitude * M_PI/180))) * cos(angle_rad); // cosine of latitude to adjust for longitude distance
    Location rand_loc;
    rand_loc.latitude = center.latitude + delta_lat_deg;
    rand_loc.longitude = center.longitude + delta_lon_deg;
    return rand_loc;
}

int main() {
    // set the seed for random number generation
    srand(time(NULL));
    
    // set up the start and end points of a journey
    Location start_point = {.latitude = 51.5014, .longitude = -0.1419}; // Buckingham Palace, London
    Location end_point = {.latitude = 48.8566, .longitude = 2.3522}; // Eiffel Tower, Paris
    
    // calculate the distance between the start and end points
    double delta_lat = (end_point.latitude - start_point.latitude) * M_PI/180;
    double delta_lon = (end_point.longitude - start_point.longitude) * M_PI/180;
    double a = pow(sin(delta_lat/2), 2) + cos(start_point.latitude * M_PI/180) * cos(end_point.latitude * M_PI/180) * pow(sin(delta_lon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance_km = 6371 * c;
    
    // create a journey structure and assign its values
    Journey j;
    j.start = start_point;
    j.end = end_point;
    j.distance_km = distance_km;
    
    // print the details of the journey
    printf("Starting location: (%.4f, %.4f)\n", j.start.latitude, j.start.longitude);
    printf("End location: (%.4f, %.4f)\n", j.end.latitude, j.end.longitude);
    printf("Distance between starting location and end location: %.2f km\n\n", j.distance_km);
    
    // generate a random route consisting of multiple waypoints
    Route r;
    r.waypoints[0] = start_point; // start at the starting location
    double total_distance_km = 0;
    for (int i = 1; i < NUM_WAYPOINTS; i++) {
        Location prev_point = r.waypoints[i-1];
        Location new_point = generate_random_point_in_circle(MAP_RADIUS, prev_point);
        double delta_lat = (new_point.latitude - prev_point.latitude) * M_PI/180;
        double delta_lon = (new_point.longitude - prev_point.longitude) * M_PI/180;
        double a = pow(sin(delta_lat/2), 2) + cos(prev_point.latitude * M_PI/180) * cos(new_point.latitude * M_PI/180) * pow(sin(delta_lon/2), 2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        double distance_km = 6371 * c;
        r.waypoints[i] = new_point;
        total_distance_km += distance_km;
    }
    r.total_distance_km = total_distance_km + distance_km; // add the distance from the last waypoint to the end location
    
    // print the details of the route
    printf("Generated route:\n");
    printf("Starting location: (%.4f, %.4f)\n", r.waypoints[0].latitude, r.waypoints[0].longitude);
    for (int i = 1; i < NUM_WAYPOINTS; i++) {
        printf("Waypoint %d: (%.4f, %.4f)\n", i, r.waypoints[i].latitude, r.waypoints[i].longitude);
    }
    printf("End location: (%.4f, %.4f)\n", j.end.latitude, j.end.longitude);
    printf("Total distance: %.2f km\n", r.total_distance_km);
    
    return 0;
}