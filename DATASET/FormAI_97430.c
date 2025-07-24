//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793238

int main()
{
    double lat1, lat2, long1, long2, distance;

    // Get user input for starting and ending coordinates
    printf("Enter starting latitude: ");
    scanf("%lf", &lat1);
    printf("Enter starting longitude: ");
    scanf("%lf", &long1);
    printf("Enter ending latitude: ");
    scanf("%lf", &lat2);
    printf("Enter ending longitude: ");
    scanf("%lf", &long2);

    // Convert coordinates to radians
    lat1 = lat1 * PI / 180.0;
    lat2 = lat2 * PI / 180.0;
    long1 = long1 * PI / 180.0;
    long2 = long2 * PI / 180.0;

    // Calculate distance between coordinates using Haversine formula
    double dlat = lat2 - lat1;
    double dlong = long2 - long1;
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = 6371 * c; // radius of earth in km

    // Print out the distance to the console
    printf("The distance between the coordinates is %.2f km.\n", distance);

    return 0;
}