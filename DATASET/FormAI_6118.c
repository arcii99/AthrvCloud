//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the distance between two coordinates
double distance(double lat1, double lon1, double lat2, double lon2) {
    int r = 6371000;
    double phi1 = lat1 * M_PI / 180;
    double phi2 = lat2 * M_PI / 180;
    double d_phi = (lat2 - lat1) * M_PI / 180;
    double d_lambda = (lon2 - lon1) * M_PI / 180;

    double a = sin(d_phi/2) * sin(d_phi/2) + cos(phi1) * cos(phi2) * sin(d_lambda/2) * sin(d_lambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = r * c;

    return d;
}

int main() {
    double origin_lat, origin_lon, dest_lat, dest_lon;
    char origin[50], destination[50];

    printf("Welcome to the GPS Navigation Simulation Program!\n\n");
    printf("Please enter your current location (in format: latitude, longitude): ");
    fgets(origin, 50, stdin);
    origin[strlen(origin)-1] = '\0';

    printf("Please enter your destination (in format: latitude, longitude): ");
    fgets(destination, 50, stdin);
    destination[strlen(destination)-1] = '\0';

    char *ptr;
    origin_lat = strtod(origin, &ptr);
    origin_lon = strtod(ptr+1, NULL);
    dest_lat = strtod(destination, &ptr);
    dest_lon = strtod(ptr+1, NULL);

    double distance_m = distance(origin_lat, origin_lon, dest_lat, dest_lon);
    printf("\nCalculating route...\n\n");
    printf("Your distance to the destination is %.2f meters.", distance_m);

    return 0;
}