//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 // value of pi

int main() {
    double start_lat, start_lon, end_lat, end_lon; // starting and ending latitude and longitude values
    double distance, bearing, deltaLat, deltaLon; // calculated distance, bearing, and change in latitude and longitude
    
    // get starting latitude and longitude values from user
    printf("Enter the starting latitude: ");
    scanf("%lf", &start_lat);
    printf("Enter the starting longitude: ");
    scanf("%lf", &start_lon);
    
    // get ending latitude and longitude values from user
    printf("Enter the ending latitude: ");
    scanf("%lf", &end_lat);
    printf("Enter the ending longitude: ");
    scanf("%lf", &end_lon);
    
    // calculate change in latitude and longitude
    deltaLat = (end_lat - start_lat) * PI / 180.0; // convert to radians
    deltaLon = (end_lon - start_lon) * PI / 180.0;
    
    // calculate distance using Haversine formula
    double a = pow(sin(deltaLat/2), 2) + cos(start_lat*PI/180) * cos(end_lat*PI/180) * pow(sin(deltaLon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = 6371 * c; // 6371 is the radius of the earth in km
    
    // calculate bearing using formula
    double y = sin(deltaLon) * cos(end_lat);
    double x = cos(start_lat) * sin(end_lat) - sin(start_lat) * cos(end_lat) * cos(deltaLon);
    bearing = atan2(y, x) * 180 / PI; // convert to degrees
    
    // print results
    printf("The distance between the two points is %.2lf km\n", distance);
    printf("The bearing from starting point to ending point is %.2lf degrees\n", bearing);
    
    return 0;
}