//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Global variables */
const float pi = 3.14159265;
const int radius_earth = 6371;

/* Function prototypes */
float deg_to_rad(float);
float dist(float, float, float, float);
float bearing(float, float, float, float);
void simulate_navigation(float, float, float, float);

/* Main function */
int main() {
    /* Coordinates of the starting and ending points */
    float lat_start = 55.7533;
    float lon_start = 37.6225;
    float lat_end = 51.5072;
    float lon_end = -0.1276;

    /* Simulation */
    simulate_navigation(lat_start, lon_start, lat_end, lon_end);

    return 0;
}

/* Function to convert degrees to radians */
float deg_to_rad(float deg) {
    return deg * (pi / 180);
}

/* Function to calculate the distance between two points */
float dist(float lat1, float lon1, float lat2, float lon2) {
    float d_lat, d_lon, a, c, d;

    d_lat = deg_to_rad(lat2 - lat1);
    d_lon = deg_to_rad(lon2 - lon1);

    a = pow(sin(d_lat / 2), 2) + cos(deg_to_rad(lat1)) * cos(deg_to_rad(lat2)) * pow(sin(d_lon / 2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    d = radius_earth * c;

    return d;
}

/* Function to calculate the bearing */
float bearing(float lat1, float lon1, float lat2, float lon2) {
    float d_lon, y, x;

    d_lon = deg_to_rad(lon2 - lon1);

    y = sin(d_lon) * cos(deg_to_rad(lat2));
    x = cos(deg_to_rad(lat1)) * sin(deg_to_rad(lat2)) - sin(deg_to_rad(lat1)) * cos(deg_to_rad(lat2)) * cos(d_lon);

    return atan2(y, x);
}

/* Function to simulate navigation */
void simulate_navigation(float lat_start, float lon_start, float lat_end, float lon_end) {
    float dist_to_end = dist(lat_start, lon_start, lat_end, lon_end);
    float direction = bearing(lat_start, lon_start, lat_end, lon_end);
    float current_lat = lat_start;
    float current_lon = lon_start;
    float move_dist = 100;    /* in meters */

    printf("Starting at: (%f, %f)\n", lat_start, lon_start);
    printf("Ending at: (%f, %f)\n", lat_end, lon_end);
    printf("Total distance to travel: %f km\n", dist_to_end);

    while (dist(current_lat, current_lon, lat_end, lon_end) >= move_dist/1000) {
        /* Calculate new coordinates */
        current_lat = asin(sin(deg_to_rad(current_lat)) * cos(move_dist / radius_earth) 
                     + cos(deg_to_rad(current_lat)) * sin(move_dist / radius_earth) * cos(direction));

        current_lon = deg_to_rad(current_lon) + atan2(sin(direction) * sin(move_dist / radius_earth) * cos(deg_to_rad(current_lat)), 
                                         cos(move_dist / radius_earth) - sin(deg_to_rad(current_lat)) * sin(deg_to_rad(current_lat)));

        current_lon = fmod((deg_to_rad(current_lon) + pi), (2 * pi)) - pi;
        current_lon = current_lon * (180 / pi);
        current_lat = current_lat * (180 / pi);

        /* Print current location */
        printf("Current location: (%f, %f)\n", current_lat, current_lon);
    }

    printf("Destination reached! Final location: (%f, %f)\n", current_lat, current_lon);
}