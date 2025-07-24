//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include<stdio.h>
#include<math.h>

#define EARTH_RADIUS 6371 //in km
#define PI 3.14159265359

struct location {
    double latitude;
    double longitude;
};

double deg2rad(double degrees) {
    return degrees * PI / 180.0;
}

double rad2deg(double radians) {
    return radians * 180.0 / PI;
}

double calculate_distance(struct location loc1, struct location loc2) {
    double lat1 = deg2rad(loc1.latitude);
    double lon1 = deg2rad(loc1.longitude);
    double lat2 = deg2rad(loc2.latitude);
    double lon2 = deg2rad(loc2.longitude);
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

int main() {
    struct location loc1 = {12.9716, 77.5946}; //Bengaluru coordinates
    struct location loc2 = {28.7041, 77.1025}; //Delhi coordinates
    double distance = calculate_distance(loc1, loc2);
    printf("Distance between Bengaluru and Delhi is: %lf km\n", distance);
    return 0;
}