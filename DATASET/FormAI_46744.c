//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate distance between two points on earth
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = (lat2 - lat1) * M_PI / 180; // Difference in latitude
    double dlon = (lon2 - lon1) * M_PI / 180; // Difference in longitude
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c; // Earth's radius in km
    return d;
}

int main() {
    double lat1 = 42.3392; // Latitude of starting point
    double lon1 = -71.0941; // Longitude of starting point

    double lat2 = 40.7128; // Latitude of destination
    double lon2 = -74.0060; // Longitude of destination

    double dist = distance(lat1, lon1, lat2, lon2); // Calculate distance between the two points
    printf("Distance between starting point and destination is %lf km\n", dist);

    // Simulating GPS navigation by printing out the coordinates of the user's current location
    for (int i = 0; i < 10; i++) {
        double lat = lat1 + (lat2 - lat1) * i / 9; // Calculate current latitude
        double lon = lon1 + (lon2 - lon1) * i / 9; // Calculate current longitude
        printf("Current location: %lf, %lf\n", lat, lon);
    }

    return 0;
}