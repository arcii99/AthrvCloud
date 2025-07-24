//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define R 6371.0 // Diameter of Earth


double degreeToRadian(double degree){
    return degree * (M_PI/180);
}

double calculateDistance(double lat1, double long1, double lat2, double long2){
    double dLat = degreeToRadian(lat2 - lat1);
    double dLong = degreeToRadian(long2 - long1);
    double a = pow(sin(dLat/2),2) + cos(degreeToRadian(lat1)) * cos(degreeToRadian(lat2)) * pow(sin(dLong/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c;
    return distance;
}

int main(){
    double lat1 = 37.7749;
    double long1 = -122.4194;
    double lat2 = 40.7128;
    double long2 = -74.0060;
    double distance = calculateDistance(lat1, long1, lat2, long2);
    printf("The distance between San Francisco and New York City is %.2f km\n", distance);
    return 0;
}