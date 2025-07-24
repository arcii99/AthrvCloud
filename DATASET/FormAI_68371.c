//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double latitude;
    double longitude;
} coordinates_t;

typedef struct {
    int speed; // in km/h
    int heading; // in degrees
} movement_t;

typedef struct {
    int id;
    char name[50];
    char address[100];
    coordinates_t coordinates;
} destination_t;

typedef struct {
    coordinates_t current_location;
    movement_t current_movement;
    destination_t current_destination;
} navigator_t;

// Function to calculate the distance between two coordinates using the Haversine formula
double haversine(coordinates_t coord1, coordinates_t coord2) {
    double lat1 = coord1.latitude;
    double lon1 = coord1.longitude;
    double lat2 = coord2.latitude;
    double lon2 = coord2.longitude;

    double dlat = (lat2 - lat1) * PI / 180.0; // convert degrees to radians
    double dlon = (lon2 - lon1) * PI / 180.0;

    double a = pow(sin(dlat / 2), 2) + cos(lat1 * PI /180.0) * cos(lat2 * PI / 180.0) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double distance = 6371 * c; // radius of Earth in km

    return distance;
}

// Function to simulate movement towards a destination
void move_towards_destination(navigator_t* navigator, int time_elapsed) {
    double distance = haversine(navigator->current_location, navigator->current_destination.coordinates);
    double heading = navigator->current_movement.heading * PI / 180.0; // convert degrees to radians
    double speed = navigator->current_movement.speed * 1000 / 3600.0; // convert km/h to m/s
    double displacement = speed * time_elapsed;

    if (displacement > distance) { // we have reached our destination
        navigator->current_location = navigator->current_destination.coordinates;
        printf("You have arrived at %s\n", navigator->current_destination.name);
    } else { // we are still on our way
        double lat1 = navigator->current_location.latitude * PI / 180.0; // convert degrees to radians
        double lon1 = navigator->current_location.longitude * PI / 180.0;
        double lat2 = navigator->current_destination.coordinates.latitude * PI / 180.0;
        double lon2 = navigator->current_destination.coordinates.longitude * PI / 180.0;

        double dlat = displacement * cos(heading) / 6371; // radius of Earth in km
        double lat = asin(sin(lat1) * cos(dlat) + cos(lat1) * sin(dlat) * cos(heading));
        double dlon = atan2(sin(heading) * sin(dlat) * cos(lat1), cos(dlat) - sin(lat1) * sin(lat));
        double lon = fmod(lon1 + dlon + PI, 2 * PI) - PI;

        navigator->current_location.latitude = lat * 180 / PI; // convert radians to degrees
        navigator->current_location.longitude = lon * 180 / PI;

        printf("You are now at (%lf, %lf)\n", navigator->current_location.latitude, navigator->current_location.longitude);
    }
}

int main() {
    navigator_t navigator;
    navigator.current_location.latitude = 37.7749;
    navigator.current_location.longitude = -122.4194;
    navigator.current_movement.speed = 50;
    navigator.current_movement.heading = 90;
    navigator.current_destination.id = 1;
    strcpy(navigator.current_destination.name, "Golden Gate Bridge");
    strcpy(navigator.current_destination.address, "Golden Gate Bridge, San Francisco, CA 94129");
    navigator.current_destination.coordinates.latitude = 37.8199;
    navigator.current_destination.coordinates.longitude = -122.4783;

    int time_elapsed = 0;
    while (haversine(navigator.current_location, navigator.current_destination.coordinates) > 0) {
        move_towards_destination(&navigator, 10); // simulate 10 seconds of movement
        time_elapsed += 10;
    }

    return 0;
}