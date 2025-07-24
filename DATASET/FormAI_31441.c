//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// define GPS structure
struct GPS {
    double latitude;
    double longitude;
};

// define destination structure
struct Destination {
     char name[50];
     struct GPS gps;
};

// converts degree to radian
double deg_to_rad(double degree) {
    return degree * M_PI / 180;
}

// calculates the distance between two GPS points in km
double distance(struct GPS source, struct GPS destination) {
    double dLat = deg_to_rad(destination.latitude - source.latitude);
    double dLon = deg_to_rad(destination.longitude - source.longitude);
    double a = pow(sin(dLat / 2), 2) + cos(deg_to_rad(source.latitude)) * cos(deg_to_rad(destination.latitude)) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;
    return d;
}

// returns the closest destination to the current GPS location
struct Destination get_closest_destination(struct GPS current_location, struct Destination destinations[], int num_destinations) {
    struct Destination closest_destination;
    double min_distance = INFINITY;

    for (int i=0; i<num_destinations; i++) {
        double d = distance(current_location, destinations[i].gps);
        if (d < min_distance) {
            min_distance = d;
            closest_destination = destinations[i];
        }
    }

    return closest_destination;
}

int main() {

    srand(time(NULL)); // initialize random number generator

    // define random GPS locations for destinations
    struct GPS destination_gps[] = {
        {37.7749, -122.4194},
        {40.7128, -74.0060},
        {34.0522, -118.2437},
        {41.8781, -87.6298},
        {51.5074, -0.1278}
    };

    // define destination names
    char destination_names[][50] = {"San Francisco", "New York City", "Los Angeles", "Chicago", "London"};

    // create destination objects
    int num_destinations = sizeof(destination_gps) / sizeof(destination_gps[0]);
    struct Destination destinations[num_destinations];

    for (int i=0; i<num_destinations; i++) {
        struct Destination destination;
        destination.gps = destination_gps[i];
        strcpy(destination.name, destination_names[i]);
        destinations[i] = destination;
    }

    // simulate GPS navigation
    printf("Starting GPS navigation...\n");

    // randomize starting location
    struct GPS current_location = {rand() % 180 - 90, rand() % 360 - 180};
    printf("Current Location: (%f, %f)\n", current_location.latitude, current_location.longitude);

    // navigate to destinations 10 times
    for (int i=0; i<10; i++) {
        struct Destination closest_destination = get_closest_destination(current_location, destinations, num_destinations);
        printf("Navigating to %s...\n", closest_destination.name);
        printf("Distance to destination: %f km\n", distance(current_location, closest_destination.gps));
        current_location = closest_destination.gps;
    }

    printf("GPS navigation complete.\n");
    return 0;
}