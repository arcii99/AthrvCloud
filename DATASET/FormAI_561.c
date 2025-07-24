//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc_distance(double, double, double, double);

int main()
{
    // GPS Coordinates
    double start_lat, start_long, end_lat, end_long;

    // Get starting position
    printf("Enter starting latitude: ");
    scanf("%lf", &start_lat);
    printf("Enter starting longitude: ");
    scanf("%lf", &start_long);

    // Get destination position
    printf("Enter destination latitude: ");
    scanf("%lf", &end_lat);
    printf("Enter destination longitude: ");
    scanf("%lf", &end_long);

    // Calculate Distance
    double distance = calc_distance(start_lat, start_long, end_lat, end_long);

    // Print Distance
    printf("\nDistance between start and destination: %.2lf km\n", distance);

    return 0;
}


double calc_distance(double lat1, double lon1, double lat2, double lon2)
{
    double phi1 = lat1 * M_PI / 180;
    double phi2 = lat2 * M_PI / 180;
    double delta_phi = (lat2 - lat1) * M_PI / 180;
    double delta_lambda = (lon2 - lon1) * M_PI / 180;

    double a = sin(delta_phi/2) * sin(delta_phi/2) + cos(phi1) * cos(phi2) * sin(delta_lambda/2) * sin(delta_lambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371 * c;

    return d;
}