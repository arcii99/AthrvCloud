//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//initializing global variables
double lat, lon, destLat, destLon, distance, bearing, randomLat, randomLon;

//calculating the distance between 2 points using haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2)
{
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
    double c = 2 * asin(sqrt(a));
    double r = 6371;
    return(c * r);
}

//calculating the initial bearing of 2 points
double initial_bearing(double lat1, double lon1, double lat2, double lon2)
{
    double y = sin(lon2-lon1) * cos(lat2);
    double x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(lon2-lon1);
    double bearing = atan2(y, x) * 180 / M_PI;
    return fmod((bearing + 360), 360);
}

//setting random destination coordinates
void set_destination()
{
    srand(time(NULL));
    destLat = (double) rand() / RAND_MAX * 180 - 90;
    destLon = (double) rand() / RAND_MAX * 360 - 180;
}

//updating coordinates based on current location and bearing
void update_location(double currentLat, double currentLon, double bearing, double distance)
{
    double r = 6371.01; //radius of earth in km
    double d = distance / r; //angular distance covered based on distance and radius
    double lat1 = currentLat * M_PI / 180; //current latitude in radians
    double lon1 = currentLon * M_PI / 180; //current longitude in radians
    double brng = bearing * M_PI / 180; //bearing in radians

    //calculating new latitude based on haversine formula
    double lat2 = asin(sin(lat1) * cos(d) + cos(lat1) * sin(d) * cos(brng));
    
    //calculating new longitude based on haversine formula
    double lon2 = lon1 + atan2(sin(brng) * sin(d) * cos(lat1), cos(d) - sin(lat1) * sin(lat2));

    //convert radians back to degrees
    lat = lat2 * 180 / M_PI;
    lon = lon2 * 180 / M_PI;
}

//function to simulate GPS navigation
void gps_navigation()
{
    //setting current location to some random location
    lat = (double) rand() / RAND_MAX * 180 - 90;
    lon = (double) rand() / RAND_MAX * 360 - 180;

    //setting random destination coordinates
    set_destination();

    while (1) {
        //calculating distance and initial bearing to destination
        distance = haversine(lat, lon, destLat, destLon); 
        bearing = initial_bearing(lat, lon, destLat, destLon);

        //updating current location every 5 seconds
        update_location(lat, lon, bearing, distance);
        printf("Current Location: (%lf, %lf)  Destination: (%lf, %lf)  Distance: %lf km  Bearing: %lf degrees\n", lat, lon, destLat, destLon, distance, bearing);

        //reaching destination when distance is less than 1 km
        if (distance < 1) {
            printf("Destination Reached!\n");
            break;
        }

        //updating randomly generated destination coordinates every 20 seconds
        if ((int) time(NULL) % 20 == 0) {
            set_destination();
            printf("New Destination Set: (%lf, %lf)\n", destLat, destLon);
        }
        sleep(5); //wait for 5 seconds before checking again
    }
}

int main()
{
    gps_navigation(); //calling the gps navigation function
    return 0;
}