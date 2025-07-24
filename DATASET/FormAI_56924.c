//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

int main()
{
    //initialize latitude and longitude
    double lat1, lat2, lon1, lon2;

    //get user input
    printf("Enter latitude of source location: ");
    scanf("%lf", &lat1);
    printf("Enter longitude of source location: ");
    scanf("%lf", &lon1);
    printf("Enter latitude of destination location: ");
    scanf("%lf", &lat2);
    printf("Enter longitude of destination location: ");
    scanf("%lf", &lon2);

    //convert to radians
    lat1 = lat1 * PI / 180;
    lon1 = lon1 * PI / 180;
    lat2 = lat2 * PI / 180;
    lon2 = lon2 * PI / 180;

    //calculation of distance between two coordinates
    double delta_lat = lat2 - lat1;
    double delta_lon = lon2 - lon1;
    double a = sin(delta_lat / 2) * sin(delta_lat / 2) + cos(lat1) * cos(lat2) * sin(delta_lon / 2) * sin(delta_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = c * 6371;

    //output distance
    printf("The distance between the two locations is %lf km.\n", distance);

    return 0;
}