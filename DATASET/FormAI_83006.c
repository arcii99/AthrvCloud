//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: dynamic
#include <stdio.h>

// function to simulate GPS navigation
void gpsNavigation(float x1, float y1, float x2, float y2) {
    // calculate distance between two points
    float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    // calculate the bearing
    float bearing = atan2(y2 - y1, x2 - x1) * 180 / 3.14159265358979323846;
    // convert bearing to a positive value
    if (bearing < 0) {
        bearing += 360;
    }
    // print the distance and bearing to the screen
    printf("Distance to destination: %.2f km\n", distance);
    printf("Bearing to destination: %.2f degrees\n", bearing);
}

int main() {
    // simulate a journey from point A to point B
    float x1 = 40.748817;
    float y1 = -73.985428;
    float x2 = 34.052235;
    float y2 = -118.243683;

    // print the starting coordinates
    printf("Starting position: (%.6f, %.6f)\n", x1, y1);

    // simulate navigation to point B
    gpsNavigation(x1, y1, x2, y2);

    // print the destination coordinates
    printf("Destination position: (%.6f, %.6f)\n", x2, y2);

    return 0;
}