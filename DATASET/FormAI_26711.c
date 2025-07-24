//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
//GPS Navigation Simulation
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

//User defined structure to store GPS coordinates (latitude & longitude)
typedef struct GPS_COORDS {
    double latitude; 
    double longitude; 
} GPS;

//Utility function to calculate distance between two GPS coordinates
double calculate_distance(GPS posA, GPS posB) {
    double R = 6371; //Earth's radius in km
    double lat1 = posA.latitude * PI/180; //Convert to radians
    double lat2 = posB.latitude * PI/180;
    double long1 = posA.longitude * PI/180;
    double long2 = posB.longitude * PI/180;
    
    double dLat = (lat2-lat1);
    double dLong = (long2-long1);
    
    double a = sin(dLat/2) * sin(dLat/2) 
    + cos(lat1) * cos(lat2) * sin(dLong/2) * sin(dLong/2); 
    
    double c = 2 * atan2(sqrt(a), sqrt(1-a)); 
    double d = R * c; //Distance
    return d;
}

int main() {
    GPS current_pos, destination_pos; 
    double distance;
    
    printf("Enter your current position (latitude, longitude): ");
    scanf("%lf, %lf", &current_pos.latitude, &current_pos.longitude);
    printf("Enter your destination position (latitude, longitude): ");
    scanf("%lf, %lf", &destination_pos.latitude, &destination_pos.longitude);
    
    distance = calculate_distance(current_pos, destination_pos);
    
    printf("Distance to destination: %.2lf km\n", distance);
    
    return 0;
}