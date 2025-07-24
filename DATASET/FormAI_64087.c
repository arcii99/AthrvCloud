//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>  
#include <math.h>    


int main()
{
    double lat1, lat2, lon1, lon2, dLat, dLon, a, c, distance;
    double pi = 3.14159265358979323846;

    printf("Enter the latitude and longitude of the starting point in Degrees: ");
    scanf("%lf %lf", &lat1, &lon1);

    printf("Enter the latitude and longitude of the destination in Degrees: ");
    scanf("%lf %lf", &lat2, &lon2);

    lat1 = lat1 * pi / 180;
    lon1 = lon1 * pi / 180;
    lat2 = lat2 * pi / 180;
    lon2 = lon2 * pi / 180;

    dLat = lat2 - lat1;
    dLon = lon2 - lon1;

    a = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = 6371 * c;

    printf("The distance between the two points is: %lf km\n", distance);

    return 0;
}