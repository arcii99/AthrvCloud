//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

struct GPS {
    double latitude;
    double longitude;
};

double calculateDistance(struct GPS point1, struct GPS point2) {
    double lat1 = point1.latitude * PI / 180;
    double lon1 = point1.longitude * PI / 180;
    double lat2 = point2.latitude * PI / 180;
    double lon2 = point2.longitude * PI / 180;
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = 6371 * c;
    return distance;
}

double calculateDirection(struct GPS point1, struct GPS point2) {
    double lat1 = point1.latitude * PI / 180;
    double lon1 = point1.longitude * PI / 180;
    double lat2 = point2.latitude * PI / 180;
    double lon2 = point2.longitude * PI / 180;
    double dLon = lon2 - lon1;
    double y = sin(dLon) * cos(lat2);
    double x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(dLon);
    double direction = atan2(y, x);
    direction = direction * 180 / PI;
    if (direction < 0) {
        direction += 360;
    }
    return direction;
}

int main() {
    struct GPS point1 = {51.507222, -0.127647}; // London coordinates
    struct GPS point2 = {48.858093, 2.294694}; // Paris coordinates
    double distance = calculateDistance(point1, point2);
    double direction = calculateDirection(point1, point2);
    printf("The distance between London and Paris is %.2f km\n", distance);
    printf("The direction from London to Paris is %.2f degrees\n", direction);
    return 0;
}