//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define R 6371.0       // Earth's radius in km
#define PI 3.14159265  // Mathematical constant pi

// Function to calculate distance between two coordinates on Earth's surface using Haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (lon2 - lon1) * PI / 180.0;
    double a = pow(sin(dLat / 2), 2) + cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;
    return distance;
}

int main() {
    // Sample coordinates
    double lat1 = 39.9087;
    double lon1 = 116.3974;
    double lat2 = 40.7128;
    double lon2 = -74.0060;

    double distance = haversine(lat1, lon1, lat2, lon2);
    
    printf("Distance between (%f, %f) and (%f, %f) is %f km\n", lat1, lon1, lat2, lon2, distance);

    return 0;
}