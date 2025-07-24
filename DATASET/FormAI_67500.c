//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Structure to hold GPS coordinates */
typedef struct {
    double lat;
    double lon;
} gps_coord;

/* Function to calculate the distance between two GPS coordinates */
double gps_distance(gps_coord coord1, gps_coord coord2) {
    double R = 6371; // Earth's radius in km
    double dLat = (coord2.lat - coord1.lat) * M_PI / 180; // Convert to radians
    double dLon = (coord2.lon - coord1.lon) * M_PI / 180; // Convert to radians
    double lat1 = coord1.lat * M_PI / 180; // Convert to radians
    double lat2 = coord2.lat * M_PI / 180; // Convert to radians

    double a = sin(dLat/2) * sin(dLat/2) + 
               sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c;

    return distance;
}

int main() {
    gps_coord start = {38.8977, -77.0365}; // Washington, DC
    gps_coord dest = {51.5074, -0.1278}; // London, UK

    printf("Starting location: (%lf, %lf)\n", start.lat, start.lon);
    printf("Destination location: (%lf, %lf)\n", dest.lat, dest.lon);

    double distance = gps_distance(start, dest);
    printf("Distance between locations: %lf km\n", distance);

    return 0;
}