//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: automated
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371

struct Point {
    double lat;
    double lon;
};

struct Path {
    struct Point start;
    struct Point end;
    double distance;
};

double toRadians(double degrees) {
    return degrees * PI / 180;
}

double calculateDistance(struct Point start, struct Point end) {
    double dLat = toRadians(end.lat - start.lat);
    double dLon = toRadians(end.lon - start.lon);
    double lat1 = toRadians(start.lat);
    double lat2 = toRadians(end.lat);

    double a = sin(dLat/2) * sin(dLat/2) + sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = RADIUS * c;

    return distance;
}

struct Path navigate(struct Point current, struct Point destination) {
    double distance = calculateDistance(current, destination);

    struct Path path = {
        .start = current,
        .end = destination,
        .distance = distance,
    };

    return path;
}

int main() {
    struct Point current = {
        .lat = 47.6062,
        .lon = -122.3352,
    };

    struct Point destination = {
        .lat = 37.7749,
        .lon = -122.4194,
    };

    struct Path path = navigate(current, destination);

    printf("Start: (%f, %f)\n", current.lat, current.lon);
    printf("Destination: (%f, %f)\n", destination.lat, destination.lon);
    printf("Distance: %f km\n", path.distance);

    return 0;
}