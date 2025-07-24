//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371

typedef struct{
    double lat, lon;
}Coordinate;

double deg2rad(double deg){
    return (deg * PI / 180);
}

double rad2deg(double rad){
    return (rad * 180 / PI);
}

double getDistance(Coordinate origin, Coordinate destination){
    double dlat = deg2rad(destination.lat - origin.lat);
    double dlon = deg2rad(destination.lon - origin.lon);
    double a = sin(dlat/2) * sin(dlat/2) + cos(deg2rad(origin.lat)) * cos(deg2rad(destination.lat)) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

int main(){
    Coordinate origin, destination;
    double distance;
    printf("Enter origin latitude: ");
    scanf("%lf", &origin.lat);
    printf("Enter origin longitude: ");
    scanf("%lf", &origin.lon);
    printf("Enter destination latitude: ");
    scanf("%lf", &destination.lat);
    printf("Enter destination longitude: ");
    scanf("%lf", &destination.lon);
    distance = getDistance(origin, destination);
    printf("The distance between the two points is %lf km\n", distance);
    return 0;
}