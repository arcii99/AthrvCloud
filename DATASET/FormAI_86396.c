//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// GPS coordinates of the starting and ending points
double lat1 = 37.7749;
double lon1 = -122.4194;
double lat2 = 40.7128;
double lon2 = -74.0060;

// Functions for converting degrees to radians and radians to degrees
double deg_to_rad(double deg) {
    return deg * (PI / 180.0);
}

double rad_to_deg(double rad) {
    return rad * (180.0 / PI);
}

// Function for calculating the distance between two GPS points
double distance(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371.0; // Radius of the earth in km
    double dlat = deg_to_rad(lat2 - lat1);
    double dlon = deg_to_rad(lon2 - lon1);
    double a = sin(dlat/2.0) * sin(dlat/2.0) + cos(deg_to_rad(lat1)) * cos(deg_to_rad(lat2)) * sin(dlon/2.0) * sin(dlon/2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    double d = R * c; // Distance in km
    return d;
}

int main() {
    double d = distance(lat1, lon1, lat2, lon2);
    printf("Distance between (%lf, %lf) and (%lf, %lf) is %lf km.\n", lat1, lon1, lat2, lon2, d);
    return 0;
}