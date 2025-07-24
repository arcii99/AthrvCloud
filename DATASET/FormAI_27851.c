//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
#define RADIUS 6371  //radius of the earth
 
typedef struct{
    double lat;
    double lng;
}Coordinates;
 
double toRadians(double degrees){
    return degrees * (M_PI/180.0);
}
 
double getDistance(Coordinates point1, Coordinates point2){
    double lat1 = toRadians(point1.lat);
    double lat2 = toRadians(point2.lat);
    double lng1 = toRadians(point1.lng);
    double lng2 = toRadians(point2.lng);
 
    double dlat = lat2 - lat1;
    double dlng = lng2 - lng1;
 
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlng/2), 2);
    double c = 2 * asin(sqrt(a));
 
    return RADIUS * c;
}
 
int main(){
    Coordinates point1, point2;
    point1.lat = 40.712776;
    point1.lng = -74.005974;
    point2.lat = 37.774929;
    point2.lng = -122.419416;
 
    double distance_km = getDistance(point1, point2);
 
    printf("The distance between New York City, NY and San Francisco, CA is: %.2f km.\n", distance_km );
 
    return 0;
}