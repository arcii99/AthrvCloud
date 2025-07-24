//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 6371 // earth's radius in km

// function to calculate distance between two points using haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dlat = (lat2 - lat1) * M_PI / 180;
    double dlon = (lon2 - lon1) * M_PI / 180;
    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;
    return d;
}

int main() {
    double curr_lat = 0, curr_lon = 0; // current latitude and longitude
    double dest_lat = 51.5072, dest_lon = -0.1276; // destination latitude and longitude
    double distance = haversine(curr_lat, curr_lon, dest_lat, dest_lon); // distance between current location and destination
    int eta = (int)(distance / 60); // estimated time of arrival in minutes
    printf("Distance to destination: %f km\n", distance);
    printf("ETA: %d minutes\n\n", eta);

    printf("Simulating navigation...\n\n");
    while(distance > 0.1) { // loop until within 100 meters of destination
        double bearing = atan2(sin(dest_lon-curr_lon)*cos(dest_lat), cos(curr_lat)*sin(dest_lat)-sin(curr_lat)*cos(dest_lat)*cos(dest_lon-curr_lon));
        curr_lat += sin(bearing) * 0.001; // change latitude by 0.1 km
        curr_lon += cos(bearing) * 0.001; // change longitude by 0.1 km
        distance = haversine(curr_lat, curr_lon, dest_lat, dest_lon);
        eta = (int)(distance / 60);
        printf("Current position: (%f, %f)\n", curr_lat, curr_lon);
        printf("Distance to destination: %f km\n", distance);
        printf("ETA: %d minutes\n\n", eta);
    }
    printf("You have arrived at your destination!\n");
    return 0;
}