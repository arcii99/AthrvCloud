//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define our GPS location structure
typedef struct{
    float lat;
    float lon;
}GPS_Location;

int main()
{
    // Define our starting location
    GPS_Location start_location;
    start_location.lat = 37.7749;
    start_location.lon = -122.4194;

    // Ask user for input destination location
    printf("Enter the destination location:\n");
    float dest_lat, dest_lon;
    printf("Latitude: ");
    scanf("%f", &dest_lat);
    printf("Longitude: ");
    scanf("%f", &dest_lon);
    GPS_Location dest_location = {dest_lat, dest_lon};

    // Calculate distance and direction to destination
    float dlat = dest_location.lat - start_location.lat;
    float dlon = dest_location.lon - start_location.lon;
    float distance = sqrt(dlat*dlat + dlon*dlon);
    float bearing = atan2(dlat, dlon);
    bearing = bearing * (180/M_PI); // convert from radians to degrees

    // Print out the results
    printf("Starting location: (%f, %f)\n", start_location.lat, start_location.lon);
    printf("Destination location: (%f, %f)\n", dest_location.lat, dest_location.lon);
    printf("Distance to destination: %f km\n", distance);
    printf("Bearing to destination: %f degrees\n", bearing);

    return 0;
}