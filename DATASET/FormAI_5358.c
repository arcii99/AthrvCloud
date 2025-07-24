//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Function to calculate distance between two points
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (lon2 - lon1) * PI / 180.0;
    double a = sin(dLat / 2.0) * sin(dLat / 2.0) + 
               cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) *
               sin(dLon / 2.0) * sin(dLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    double d = 6371.0 * c; // Radius of Earth in km
    return d;
}

// Main function
int main() {
    double lat1, lon1; // Starting point
    double lat2, lon2; // Destination point
    printf("Enter starting point (latitude and longitude): ");
    scanf("%lf %lf", &lat1, &lon1);
    printf("Enter destination point (latitude and longitude): ");
    scanf("%lf %lf", &lat2, &lon2);
    double dist = distance(lat1, lon1, lat2, lon2);
    printf("The distance between the two points is %lf km.\n", dist);
    return 0;
}