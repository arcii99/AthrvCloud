//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: authentic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct position {
    double latitude;
    double longitude;
} Position;

double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

double radiansToDegrees(double radians) {
    return radians * 180.0 / PI;
}

double getDistance(double lat1, double long1, double lat2, double long2) {
    double dLat = degreesToRadians(lat2 - lat1);
    double dLong = degreesToRadians(long2 - long1);

    double a = pow(sin(dLat / 2), 2) + cos(degreesToRadians(lat1)) * cos(degreesToRadians(lat2)) * pow(sin(dLong / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = 6371.0 * c;
    return distance;
}

void navigateToDestination(Position currentPosition, Position destination) {
    double distance = getDistance(currentPosition.latitude, currentPosition.longitude, destination.latitude, destination.longitude);
    printf("Distance between current location and destination is %lf km\n", distance);

    double bearing = atan2(sin(degreesToRadians(destination.longitude - currentPosition.longitude)) * cos(degreesToRadians(destination.latitude)), cos(degreesToRadians(currentPosition.latitude)) * sin(degreesToRadians(destination.latitude)) - sin(degreesToRadians(currentPosition.latitude)) * cos(degreesToRadians(destination.latitude)) * cos(degreesToRadians(destination.longitude - currentPosition.longitude)));
    bearing = fmod(radiansToDegrees(bearing) + 360, 360);
    printf("Bearing to destination is %lf degrees\n", bearing);
}

int main() {
    Position currentLocation = { 37.7749, -122.4194 };
    Position destination = { 37.7749, -122.5185 };

    navigateToDestination(currentLocation, destination);

    return 0;
}