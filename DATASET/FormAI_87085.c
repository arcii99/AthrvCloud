//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

void GPSNavigation(double lat1, double lon1, double lat2, double lon2);

int main()
{
    double lat1, lon1, lat2, lon2;

    printf("Enter initial latitude and longitude (decimal degrees):\n");
    scanf("%lf %lf", &lat1, &lon1);

    printf("Enter final latitude and longitude (decimal degrees):\n");
    scanf("%lf %lf", &lat2, &lon2);

    GPSNavigation(lat1, lon1, lat2, lon2);

    return 0;
}

void GPSNavigation(double lat1, double lon1, double lat2, double lon2)
{
    const double PI = 3.14159265358979323846;
    const double EarthRadius = 6371000; // Earth's radius in metres 

    // Convert latitude and longitude to radians 
    lat1 = lat1 * PI / 180;
    lon1 = lon1 * PI / 180;
    lat2 = lat2 * PI / 180;
    lon2 = lon2 * PI / 180;

    // Calculate the angular distance between two points 
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat/2)*sin(dlat/2) + cos(lat1)*cos(lat2)*sin(dlon/2)*sin(dlon/2);
    double c = 2*atan2(sqrt(a), sqrt(1-a));
    double distance = EarthRadius*c;

    // Calculate the heading from point 1 to point 2 in degrees 
    double y = sin(dlon)*cos(lat2);
    double x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(dlon);
    double heading = atan2(y, x) * 180 / PI;

    // Print output 
    printf("Distance: %.2f metres\n", distance);
    printf("Heading: %.2f degrees\n", heading);
}