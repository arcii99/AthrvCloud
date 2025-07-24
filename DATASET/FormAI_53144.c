//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    double lat1, lon1, lat2, lon2, dlat, dlon, a, c, distance;
    printf("Enter latitude and longitude of starting point (in degrees): ");
    scanf("%lf %lf", &lat1, &lon1);
    printf("Enter latitude and longitude of destination point (in degrees): ");
    scanf("%lf %lf", &lat2, &lon2);
    lat1 *= (PI/180);
    lon1 *= (PI/180);
    lat2 *= (PI/180);
    lon2 *= (PI/180);
    dlat = lat2 - lat1;
    dlon = lon2 - lon1;
    a = sin(dlat/2)*sin(dlat/2) + cos(lat1)*cos(lat2)*sin(dlon/2)*sin(dlon/2);
    c = 2*atan2(sqrt(a), sqrt(1-a));
    distance = 6371*c; // radius of earth is 6371 km
    printf("Distance between the two points is %lf km\n", distance);
    return 0;
}