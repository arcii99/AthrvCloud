//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define RAD_PER_DEG 0.017453293

struct Coordinates {
    double latitude;
    double longitude;
};

int main(void) {

    // Define starting location and destination
    struct Coordinates start = {42.358056, -71.063611}; // Boston, MA
    struct Coordinates dest = {37.7749, -122.4194}; // San Francisco, CA

    // Calculate distance between two points using Haversine formula
    double dLat = (dest.latitude - start.latitude) * RAD_PER_DEG;
    double dLon = (dest.longitude - start.longitude) * RAD_PER_DEG;
    double a = pow(sin(dLat/2), 2) + cos(start.latitude * RAD_PER_DEG) * cos(dest.latitude * RAD_PER_DEG) * pow(sin(dLon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = 6371 * c; // 6371 is the radius of the Earth in kilometers

    // Print distance between starting location and destination
    printf("Distance between Boston, MA and San Francisco, CA is %.2f km.\n", distance);

    // Calculate bearing from starting location to destination using spherical law of cosines
    double y = sin(dLon) * cos(dest.latitude * RAD_PER_DEG);
    double x = cos(start.latitude * RAD_PER_DEG) * sin(dest.latitude * RAD_PER_DEG) - sin(start.latitude * RAD_PER_DEG) * cos(dest.latitude * RAD_PER_DEG) * cos(dLon);
    double bearing = atan2(y, x) / RAD_PER_DEG;

    // Print bearing from starting location to destination
    printf("Bearing from Boston, MA to San Francisco, CA is %.2f degrees.\n", bearing);

    return 0;
}