//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EARTH_RADIUS 6371 // in kilometers

// function to convert degrees to radians
double deg2rad(double deg) {
    return (deg * M_PI / 180);
}

// function to calculate distance between two points on Earth
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat, dLon, a, c, d;
    dLat = deg2rad(lat2 - lat1);
    dLon = deg2rad(lon2 - lon1);
    a = pow(sin(dLat/2), 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * pow(sin(dLon/2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = EARTH_RADIUS * c;
    return d;
}

// main function
int main() {
    double lat, lon, dest_lat, dest_lon;
    char choice[10], input[100];

    printf("Welcome to GPS Navigation Simulation!\n");
    printf("Enter your starting latitude: ");
    fgets(input, 100, stdin);
    lat = atof(input);

    printf("Enter your starting longitude: ");
    fgets(input, 100, stdin);
    lon = atof(input);

    printf("Enter your destination latitude: ");
    fgets(input, 100, stdin);
    dest_lat = atof(input);

    printf("Enter your destination longitude: ");
    fgets(input, 100, stdin);
    dest_lon = atof(input);

    printf("\nYour current location is: %.2lf, %.2lf\n", lat, lon);
    printf("Your destination is: %.2lf, %.2lf\n", dest_lat, dest_lon);

    while (1) {
        printf("\nEnter 'distance' to get distance to destination or 'exit' to quit: ");
        fgets(choice, 10, stdin);

        // check for exit condition
        if (strcmp(choice, "exit\n") == 0)
            break;

        // calculate distance to destination
        if (strcmp(choice, "distance\n") == 0) {
            double d = distance(lat, lon, dest_lat, dest_lon);
            printf("You are %.2lf kilometers away from your destination.\n", d);
        } else {
            printf("Invalid choice!\n");
        }
    }

    printf("\nThanks for using GPS Navigation Simulation!\n");

    return 0;
}