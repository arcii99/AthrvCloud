//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EARTH_RADIUS 6371
#define PI 3.14159

typedef struct {
    double latitude;
    double longitude;
} Point;

double convert_deg_to_rad(double degree) {
    return (degree * PI / 180);
}

double calculate_distance(Point point1, Point point2) {
    double lat1 = convert_deg_to_rad(point1.latitude);
    double lon1 = convert_deg_to_rad(point1.longitude);
    double lat2 = convert_deg_to_rad(point2.latitude);
    double lon2 = convert_deg_to_rad(point2.longitude);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

int main() {
    Point startPoint = {15.3850, 73.8448}; // Mexico City
    Point endPoint = {19.4326, 99.1332}; // Bangkok

    double distance = calculate_distance(startPoint, endPoint);
    printf("The distance between Mexico City and Bangkok is: %lf km\n", distance);

    return 0;
}