//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>

#define pi 3.14159265358979323846

int main()
{
    double lat1, long1, lat2, long2, dlat, dlong, a, c, distance;
    printf("Enter the latitude of starting point (in degrees): ");
    scanf("%lf", &lat1);
    printf("Enter the longitude of starting point (in degrees): ");
    scanf("%lf", &long1);
    printf("Enter the latitude of destination point (in degrees): ");
    scanf("%lf", &lat2);
    printf("Enter the longitude of destination point (in degrees): ");
    scanf("%lf", &long2);

    dlat = (lat2-lat1) * pi / 180;
    dlong = (long2-long1) * pi / 180;
    a = pow(sin(dlat/2), 2) + cos(lat1*pi/180) * cos(lat2*pi/180) * pow(sin(dlong/2), 2);
    c = 2* atan2(sqrt(a), sqrt(1-a));
    distance = (6371 * c) * 1000;

    printf("\nThe distance between the two points is %lf meters.\n", distance);
    
    return 0;

}