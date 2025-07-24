//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

#define PI 3.14159

struct screenPos {
    int x;
    int y;
};

struct position {
    double latitude;
    double longitude;
};

double calculateDistance(struct position pos1, struct position pos2) {
    double x = (pos2.longitude - pos1.longitude) * cos((pos1.latitude + pos2.latitude) / 2);
    double y = pos2.latitude - pos1.latitude;
    return sqrt(x * x + y * y) * 6371;
}

double toRadians(double degrees) {
    return degrees * PI / 180;
}

void drawMap(struct screenPos currentPosition, struct position destination) {
    // Code to draw a map on screen, using ASCII art or similar
}

int main() {
    struct position currentPosition = { 52.5200, 13.4050 };  // Berlin, Germany
    struct position destination = { 40.7128, -74.0060 };  // New York, USA

    double distance = calculateDistance(currentPosition, destination);
    printf("Distance to destination: %.2f km\n", distance);

    double bearing = atan2(sin(toRadians(destination.longitude - currentPosition.longitude)) * cos(toRadians(destination.latitude)), cos(toRadians(currentPosition.latitude)) * sin(toRadians(destination.latitude)) - sin(toRadians(currentPosition.latitude)) * cos(toRadians(destination.latitude)) * cos(toRadians(destination.longitude - currentPosition.longitude)));
    printf("Bearing to destination: %.2f degrees\n", bearing * 180 / PI);

    struct screenPos currentScreenPos = { 0, 0 };  // Replace with actual screen position
    drawMap(currentScreenPos, destination);

    return 0;
}