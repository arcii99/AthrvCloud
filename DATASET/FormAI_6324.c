//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double distance(double lat1, double long1, double lat2, double long2) {
    double lat1_rad, long1_rad, lat2_rad, long2_rad, d_lat, d_long, a, c, d;
    
    lat1_rad = lat1 * PI / 180;
    long1_rad = long1 * PI / 180;
    lat2_rad = lat2 * PI / 180;
    long2_rad = long2 * PI / 180;
    d_lat = lat2_rad - lat1_rad;
    d_long = long2_rad - long1_rad;
    
    a = sin(d_lat/2) * sin(d_lat/2) + cos(lat1_rad) * cos(lat2_rad) * sin(d_long/2) * sin(d_long/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = 6371 * c;
    
    return d;
}

int main() {
    double lat1, long1, lat2, long2;

    printf("Welcome to GPS Navigation Simulation program!\n");
    printf("Please enter the latitude and longitude of your starting point:\n");
    scanf("%lf %lf", &lat1, &long1);
    printf("Please enter the latitude and longitude of your destination:\n");
    scanf("%lf %lf", &lat2, &long2);
    
    double dist = distance(lat1, long1, lat2, long2);
    
    printf("\nYour starting point:\n");
    printf("Latitude: %lf\n", lat1);
    printf("Longitude: %lf\n", long1);
    
    printf("\nYour destination:\n");
    printf("Latitude: %lf\n", lat2);
    printf("Longitude: %lf\n", long2);
    
    printf("\nThe distance between your starting point and destination is %lf km.\n", dist);
    
    return 0;
}