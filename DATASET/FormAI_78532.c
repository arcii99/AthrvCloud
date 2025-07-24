//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define GPS point struct
struct gps_point {
    double lat;     // Latitude in degrees
    double lon;     // Longitude in degrees
};

// Define function to calculate distance between two GPS points
double distance(struct gps_point p1, struct gps_point p2) {
    double R = 6371e3;   // Earth's radius in meters
    double lat1 = p1.lat * M_PI / 180.0;
    double lat2 = p2.lat * M_PI / 180.0;
    double dlat = (p2.lat - p1.lat) * M_PI / 180.0;
    double dlon = (p2.lon - p1.lon) * M_PI / 180.0;
    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;
    return d;
}

// Define function to generate random GPS point within a given box
struct gps_point random_gps_point(double min_lat, double max_lat, double min_lon, double max_lon) {
    struct gps_point p;
    p.lat = (max_lat - min_lat) * ((double)rand() / (double)RAND_MAX) + min_lat;
    p.lon = (max_lon - min_lon) * ((double)rand() / (double)RAND_MAX) + min_lon;
    return p;
}

// Define function to simulate GPS navigation
void simulate_navigation(struct gps_point start, struct gps_point end, double speed) {
    double distance_to_end = distance(start, end);
    double bearing = atan2(sin(end.lon - start.lon) * cos(end.lat), cos(start.lat) * sin(end.lat) - sin(start.lat) * cos(end.lat) * cos(end.lon - start.lon));
    double elapsed_time = 0.0;
    struct gps_point current_location = start;
    printf("Starting at (%f, %f)\n", start.lat, start.lon);
    while (distance_to_end > 0.0) {
        // Calculate distance to travel in this time step
        double distance_to_travel = speed * elapsed_time;
        // Calculate new location based on distance and bearing
        double lat1 = current_location.lat * M_PI / 180.0;
        double lon1 = current_location.lon * M_PI / 180.0;
        double lat2 = asin(sin(lat1) * cos(distance_to_travel / 6371e3) + cos(lat1) * sin(distance_to_travel / 6371e3) * cos(bearing));
        double lon2 = lon1 + atan2(sin(bearing) * sin(distance_to_travel / 6371e3) * cos(lat1), cos(distance_to_travel / 6371e3) - sin(lat1) * sin(lat2));
        current_location.lat = lat2 * 180.0 / M_PI;
        current_location.lon = lon2 * 180.0 / M_PI;
        // Calculate new distance to end and elapsed time
        distance_to_end = distance(current_location, end);
        elapsed_time += 1.0;    // Simulate 1 second of time
        // Print current location and distance to end
        printf("Current location: (%f, %f) Distance to end: %f meters\n", current_location.lat, current_location.lon, distance_to_end);
    }
    printf("Destination reached at (%f, %f) after %f seconds\n", end.lat, end.lon, elapsed_time);
}

int main() {
    // Set seed for random number generation
    srand(time(NULL));
    // Define start and end points
    struct gps_point start = { 38.8895, -77.0352 };
    struct gps_point end = random_gps_point(38.8891, 38.8899, -77.0359, -77.0346);
    // Define simulation parameters
    double speed = 5.0;     // Speed in meters per second
    // Simulate navigation
    simulate_navigation(start, end, speed);
    return 0;
}