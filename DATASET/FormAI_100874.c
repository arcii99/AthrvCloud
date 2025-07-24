//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random coordinates
void generateCoordinates(double* x, double* y) {
    srand(time(NULL));
    *x = (double)rand() / (double)RAND_MAX * 180 - 90;
    *y = (double)rand() / (double)RAND_MAX * 360 - 180;
}

int main() {
    double current_lat, current_long, dest_lat, dest_long;

    printf("Welcome to the GPS Navigation Simulator!\n");

    // Generate random current and destination coordinates
    generateCoordinates(&current_lat, &current_long);
    generateCoordinates(&dest_lat, &dest_long);

    printf("Current Location: (%.6f, %.6f)\n", current_lat, current_long);
    printf("Destination: (%.6f, %.6f)\n", dest_lat, dest_long);

    // Calculate distance between current location and destination (simplified spherical law of cosines formula)
    const double R = 6371; // Earth's radius in km
    const double toRadians = 3.141592653589793 / 180.0;
    double lat1 = current_lat * toRadians;
    double lat2 = dest_lat * toRadians;
    double long1 = current_long * toRadians;
    double long2 = dest_long * toRadians;
    double distance = R * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long2 - long1));

    printf("Distance to Destination: %.2f kilometers\n", distance);

    // Determine direction to destination (simplified bearing formula)
    double y = sin(long2 - long1) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(long2 - long1);
    double bearing = atan2(y, x) / toRadians;

    if (bearing < 0) {
        bearing = 360 + bearing;
    }

    printf("Direction: %.2f degrees\n", bearing);

    return 0;
}