//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371 // in km

struct location {
    double latitude;
    double longitude;
};

double calculate_distance(struct location location1, struct location location2); // function prototype

int main()
{
    struct location source, destination;
    double distance;

    printf("Enter the source location (latitude, longitude): ");
    scanf("%lf %lf", &source.latitude, &source.longitude);

    printf("Enter the destination location (latitude, longitude): ");
    scanf("%lf %lf", &destination.latitude, &destination.longitude);

    distance = calculate_distance(source, destination);

    printf("The distance between the two locations is: %lf km\n", distance);
    
    return 0;
}

double calculate_distance(struct location location1, struct location location2)
{
    double lat1, lat2, lon1, lon2, delta_lat, delta_lon, a, c;

    lat1 = location1.latitude * M_PI / 180.0;
    lat2 = location2.latitude * M_PI / 180.0;
    lon1 = location1.longitude * M_PI / 180.0;
    lon2 = location2.longitude * M_PI / 180.0;

    delta_lat = lat2 - lat1;
    delta_lon = lon2 - lon1;

    a = sin(delta_lat/2)*sin(delta_lat/2) + cos(lat1)*cos(lat2)*sin(delta_lon/2)*sin(delta_lon/2);
    c = 2*atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}