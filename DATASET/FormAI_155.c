//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include<stdio.h>
#include<math.h>

// Function to convert degrees to radians
double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to calculate the distance between two GPS points
double calcDistance(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371e3; // Earth's radius in meters
    double phi1 = toRadians(lat1);
    double phi2 = toRadians(lat2);
    double deltaPhi = toRadians(lat2-lat1);
    double deltaLambda = toRadians(lon2-lon1);
    
    double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
               cos(phi1) * cos(phi2) *
               sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    return R * c; // Distance between the two points in meters
}

int main() {
    double latA = 41.890519; // Latitude of point A
    double lonA = -87.624834; // Longitude of point A
    double latB = 41.878114; // Latitude of point B
    double lonB = -87.629798; // Longitude of point B
    
    printf("Distance between point A and B is %lf meters\n", calcDistance(latA, lonA, latB, lonB));
    
    return 0;
}