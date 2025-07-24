//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Function to calculate the distance between two points given their latitude and longitude
double distance(double lat1, double long1, double lat2, double long2) {
    double d_lat = (lat2 - lat1) * PI / 180.0;
    double d_long = (long2 - long1) * PI / 180.0;
    double a = sin(d_lat / 2) * sin(d_lat / 2) + cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) * sin(d_long / 2) * sin(d_long / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;
    return d;
}

int main() {
    // Starting coordinates
    double start_lat = 37.7749;
    double start_long = -122.4194;
    
    // Destination coordinates
    double dest_lat = 40.7128;
    double dest_long = -74.0060;
    
    // Total distance to travel
    double total_distance = distance(start_lat, start_long, dest_lat, dest_long);
    
    // Current position
    double current_lat = start_lat;
    double current_long = start_long;
    
    // Speed and direction variables
    double speed = 60; // km/h
    double bearing = atan2(sin(dest_long - start_long) * cos(dest_lat), cos(start_lat) * sin(dest_lat) - sin(start_lat) * cos(dest_lat) * cos(dest_long - start_long));
    bearing = bearing * 180.0 / PI; // convert to degrees
    if (bearing < 0) {
        bearing += 360; // convert from -180 to 180 range to 0 to 360 range
    }
    
    // Simulation loop
    int time = 0;
    while (current_lat != dest_lat || current_long != dest_long) {
        // Calculate distance to travel in this time step
        double distance_to_travel = (speed / 3600.0) * 0.01666667; // 1 minute in degrees
        if (distance_to_travel > total_distance) {
            distance_to_travel = total_distance;
        }
        total_distance -= distance_to_travel;
        
        // Calculate new position
        current_lat += distance_to_travel * cos(bearing * PI / 180.0);
        current_long += distance_to_travel * sin(bearing * PI / 180.0) / cos(current_lat * PI / 180.0);
        
        // Print position and time
        printf("Time: %d minutes. Current Position: (%f, %f)\n", time, current_lat, current_long);
        time++;
    }
    
    printf("Destination reached in %d minutes!\n", time);
    return 0;
}