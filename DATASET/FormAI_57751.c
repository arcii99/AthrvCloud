//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
#include<stdio.h>
#include<math.h>

#define PI 3.141592653579

#define LAT1 42.364506
#define LON1 -71.038887

// Function to convert degrees to radians
double deg_to_rad(double deg)
{
    return deg * PI / 180;
}

//Function to calculate the distance between two locations 
double distance(double lat1, double lat2, double lon1, double lon2)
{
    double dlat = deg_to_rad(lat2 - lat1);
    double dlon = deg_to_rad(lon2 - lon1);
    double a = pow(sin(dlat / 2), 2) + cos(deg_to_rad(lat1)) * cos(deg_to_rad(lat2)) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c * 1000; // Distance in Metres
    return distance;
}

int main()
{
    double lat, lon, distance_to_destination;
    printf("Enter the Latitude and Longitude of your destination:\n");
    scanf("%lf %lf", &lat, &lon);
    distance_to_destination = distance(LAT1, lat, LON1, lon);
    printf("Distance to your destination is %.1lf metres\n", distance_to_destination);
    return 0;
}