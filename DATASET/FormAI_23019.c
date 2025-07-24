//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
// C GPS Navigation Simulation example program

#include <stdio.h>
#include <math.h>

#define RADIUS 6371 // Earth's radius in km

int main() {
    double lat1, lat2, lon1, lon2;
    double distance;

    // User input for starting and ending coordinates
    printf("Enter starting latitude: ");
    scanf("%lf", &lat1);
    printf("Enter starting longitude: ");
    scanf("%lf", &lon1);
    printf("Enter ending latitude: ");
    scanf("%lf", &lat2);
    printf("Enter ending longitude: ");
    scanf("%lf", &lon2);

    // Converting degrees to radians
    lat1 = lat1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;
    lon1 = lon1 * M_PI / 180;
    lon2 = lon2 * M_PI / 180;

    // Distance formula using Haversine formula
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = RADIUS * c;

    // Printing final result to console
    printf("Distance between starting and ending coordinates: %.2lf km\n", distance);

    return 0;
}