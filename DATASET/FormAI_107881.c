//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

struct location {
    double latitude;
    double longitude;
};

double deg2rad(double deg) {
    return deg * M_PI / 180;
}

double rad2deg(double rad) {
    return rad * 180 / M_PI;
}

double distance(struct location loc1, struct location loc2) {
    double lat1 = loc1.latitude;
    double lon1 = loc1.longitude;
    double lat2 = loc2.latitude;
    double lon2 = loc2.longitude;
    double earth_radius = 6371; // in km
    double d_lat = deg2rad(lat2-lat1);
    double d_lon = deg2rad(lon2-lon1);
    double a = sin(d_lat/2) * sin(d_lat/2) +
             cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
             sin(d_lon/2) * sin(d_lon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = earth_radius * c; // in km
    return d;
}

int time_taken(double distance, double speed) {
    int time_secs = (int)((distance / speed) * 3600);
    return time_secs;
}

void navigate(struct location current_location, struct location destination_location) {
    double dist = distance(current_location, destination_location);
    printf("Distance to destination: %.2f km\n", dist);
    int speed = 30; // km/h
    int time = time_taken(dist, speed);
    int hours = time / 3600;
    int minutes = (time - (hours * 3600)) / 60;
    printf("Estimated time of arrival: %d hours and %d minutes\n", hours, minutes);
    printf("Directions:\n");
    if (current_location.latitude < destination_location.latitude) {
        printf("Head north on Main Street\n");
    } else {
        printf("Head south on Main Street\n");
    }
    if (current_location.longitude < destination_location.longitude) {
        printf("Turn right onto Elm Street\n");
    } else {
        printf("Turn left onto Elm Street\n");
    }
    printf("Continue straight for %.2f km\n", dist);
    printf("Destination is on the left\n");
}

int main() {
    printf("GPS Navigation Simulation\n");
    struct location current_location = {45.4215, -75.6972};
    struct location destination_location = {48.8566, 2.3522};
    navigate(current_location, destination_location);
    return 0;
}