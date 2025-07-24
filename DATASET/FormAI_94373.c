//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include<stdio.h>
#include<math.h>

#define R 6371 // Earth's radius in km

// Function to convert degrees to radians
double deg2rad(double degree) {
    return degree * M_PI / 180;
}

// Function to calculate the distance between two points on Earth using Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat, dlon, a, c, d;
    dlat = deg2rad(lat2 - lat1);
    dlon = deg2rad(lon2 - lon1);
    a = sin(dlat/2) * sin(dlat/2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dlon/2) * sin(dlon/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = R * c; // Distance in km
    return d;
}

int main() {
    // Input coordinates from user 
    double lat1, lon1, lat2, lon2;
    printf("Enter coordinates of starting point (latitude, longitude): ");
    scanf("%lf %lf", &lat1, &lon1);
    printf("Enter coordinates of destination (latitude, longitude): ");
    scanf("%lf %lf", &lat2, &lon2);

    // Calculate distance between two points
    double d = distance(lat1, lon1, lat2, lon2);
    printf("Distance between (%lf, %lf) and (%lf, %lf) is %lf km\n", lat1, lon1, lat2, lon2, d);

    return 0;
}