//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include<stdio.h>
#include<math.h>

int main()
{
    double lat1, long1, lat2, long2, rad, dist;
    printf("Enter the latitude of your current location: ");
    scanf("%lf", &lat1);
    printf("Enter the longitude of your current location: ");
    scanf("%lf", &long1);
    printf("Enter the latitude of your destination: ");
    scanf("%lf", &lat2);
    printf("Enter the longitude of your destination: ");
    scanf("%lf", &long2);
    rad = 6371; //Radius of the earth in km
    lat1 = lat1 * M_PI / 180; //convert to radians
    long1 = long1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;
    long2 = long2 * M_PI / 180;
    double dlat, dlong;
    dlat = lat2 - lat1;
    dlong = long2 - long1;
    double a, c;
    a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    dist = rad * c;
    printf("Your distance from the destination is: %lf km\n", dist);
    return 0;
}