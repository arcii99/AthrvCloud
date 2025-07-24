//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371000.0

double degToRad(double deg) {
    // Convert degrees to radians
    return deg * (PI / 180.0);
}

int main() {
    // Define the GPS coordinates of the starting and ending points
    double startLat = 40.712776;
    double startLon = -74.005974;
    double endLat = 37.7749;
    double endLon = -122.4194;

    // Convert GPS coordinates from degrees to radians
    double lat1 = degToRad(startLat);
    double lon1 = degToRad(startLon);
    double lat2 = degToRad(endLat);
    double lon2 = degToRad(endLon);

    // Calculate the haversine distance formula
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;

    // Calculate the bearing angle
    double y = sin(lon2 - lon1) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1);
    double bearing = atan2(y, x);
    bearing = fmod(bearing + 2 * PI, 2 * PI);

    // Print the results
    printf("Starting point: (%f, %f)\n", startLat, startLon);
    printf("Ending point: (%f, %f)\n", endLat, endLon);
    printf("Distance between points: %f meters\n", distance);
    printf("Bearing angle: %f degrees\n", bearing * (180.0 / PI));

    return 0;
}