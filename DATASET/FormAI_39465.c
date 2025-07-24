//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert degrees to radians
double toRadians(double degrees)
{
    return degrees * PI / 180.0;
}

// Struct to hold GPS coordinates
typedef struct Coordinate {
    double latitude;
    double longitude;
} Coordinate;

// Function to calculate the distance (in kilometers) between two GPS coordinates
double distance(Coordinate coord1, Coordinate coord2)
{
    double lat1 = toRadians(coord1.latitude);
    double lat2 = toRadians(coord2.latitude);
    double lon1 = toRadians(coord1.longitude);
    double lon2 = toRadians(coord2.longitude);
    
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = 6371 * c;
    
    return distance;
}

// Main function to simulate GPS navigation
int main()
{
    // Start and end coordinates
    Coordinate start = {37.7749, -122.4194};
    Coordinate end = {37.3352, -121.8811};
    
    // Print start and end coordinates
    printf("Start: (%.4f, %.4f)\n", start.latitude, start.longitude);
    printf("End: (%.4f, %.4f)\n", end.latitude, end.longitude);
    
    // Calculate distance between start and end coordinates
    double d = distance(start, end);
    
    // Print distance between start and end coordinates
    printf("Distance between start and end coordinates: %.2f km\n", d);
    
    // Calculate and print intermediate coordinates
    int numIntermediateCoords = 10; // configurable parameter
    double stepSize = 1.0 / (numIntermediateCoords + 1);
    for (int i = 1; i <= numIntermediateCoords; i++)
    {
        double fraction = i * stepSize;
        Coordinate intermediate = {
            start.latitude + fraction * (end.latitude - start.latitude),
            start.longitude + fraction * (end.longitude - start.longitude)
        };
        printf("Intermediate coordinate %d: (%.4f, %.4f)\n", i, intermediate.latitude, intermediate.longitude);
    }
    
    return 0;
}