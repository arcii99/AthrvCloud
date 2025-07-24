//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float deg2rad(float deg) {
    return deg * (PI/180);
}

float rad2deg(float rad) {
    return rad * (180/PI);
}

float distance(float lat1, float lon1, float lat2, float lon2) {
    float R = 6371; // Earth's radius in km
    float dLat = deg2rad(lat2 - lat1);
    float dLon = deg2rad(lon2 - lon1);
    float a = sin(dLat/2) * sin(dLat/2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dLon/2) * sin(dLon/2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float d = R * c; // Distance in km
    return d;
}

int main() {
    float lat1 = 51.5179;
    float lon1 = -0.077;
    float lat2 = 45.5231;
    float lon2 = -122.6765;

    float dist = distance(lat1, lon1, lat2, lon2);

    printf("Distance between London and Portland is %0.2f km\n", dist);

    return 0;
}