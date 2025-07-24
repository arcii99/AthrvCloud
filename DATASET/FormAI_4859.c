//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate distance between two points
double distance(double lat1, double lon1, double lat2, double lon2){
    double earthRadius = 6371; // in km
    double dLat = (lat2 - lat1) * M_PI / 180;
    double dLon = (lon2 - lon1) * M_PI / 180;
    double a =
        sin(dLat / 2) * sin(dLat / 2) +
        cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) *
        sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = earthRadius * c;
    return distance;
}

int main(){
    double startLat, startLon, endLat, endLon;
    printf("Enter starting latitude and longitude (separated by space): ");
    scanf("%lf %lf", &startLat, &startLon);
    printf("Enter ending latitude and longitude (separated by space): ");
    scanf("%lf %lf", &endLat, &endLon);
    double dist = distance(startLat, startLon, endLat, endLon);
    printf("The distance between the two points is %.2f km.\n", dist);
    printf("Enter your current latitude and longitude (separated by space): ");
    double curLat, curLon;
    scanf("%lf %lf", &curLat, &curLon);
    double curDist = distance(curLat, curLon, endLat, endLon);
    if(curDist < dist){
        printf("You are heading in the right direction.\n");
    }
    else{
        printf("You are heading in the wrong direction.\n");
    }
    return 0;
}