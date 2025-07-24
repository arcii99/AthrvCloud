//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265

// Function to calculate distance between two coordinates using Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (lon2 - lon1) * PI / 180.0;
 
    lat1 = (lat1) * PI / 180.0;
    lat2 = (lat2) * PI / 180.0;
 
    double a = pow(sin(dLat / 2), 2) + 
               pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

int main() {
    double startLat, startLon, endLat, endLon;
    printf("Enter the starting latitude and longitude: ");
    scanf("%lf %lf", &startLat, &startLon);
    printf("Enter the ending latitude and longitude: ");
    scanf("%lf %lf", &endLat, &endLon);
    double distanceTravelled = distance(startLat, startLon, endLat, endLon);
    printf("The distance between the two points is %lf km.", distanceTravelled);
    return 0;
}