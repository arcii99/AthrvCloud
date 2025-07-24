//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi = 3.14159265358979323846;

// function to calculate distance between two points given their coordinates
double distance(double lat1, double long1, double lat2, double long2) {
    double dlat, dlong, a, c, d;
    dlat = (lat2-lat1) * pi / 180.0;
    dlong = (long2-long1) * pi / 180.0;
    a = sin(dlat/2.0) * sin(dlat/2.0) + cos(lat1 * pi / 180.0) * cos(lat2 * pi / 180.0) * sin(dlong/2.0) * sin(dlong/2.0);
    c = 2.0 * atan2(sqrt(a), sqrt(1.0-a));
    d = 6371.0 * c; // radius of the earth
    return d;
}

int main() {
    double current_lat, current_long, destination_lat, destination_long;
    printf("Enter your current latitude: ");
    scanf("%lf", &current_lat);
    printf("Enter your current longitude: ");
    scanf("%lf", &current_long);
    printf("Enter your destination latitude: ");
    scanf("%lf", &destination_lat);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destination_long);
    double total_distance = distance(current_lat, current_long, destination_lat, destination_long);
    printf("Total distance to destination is: %.2lf km\n", total_distance);
    double remaining_distance = total_distance;
    while (remaining_distance > 0.1) { // while remaining distance is greater than 100 meters
        printf("Remaining distance to destination is: %.2lf km\n", remaining_distance);
        printf("Enter your current latitude: ");
        scanf("%lf", &current_lat);
        printf("Enter your current longitude: ");
        scanf("%lf", &current_long);
        double distance_to_destination = distance(current_lat, current_long, destination_lat, destination_long);
        printf("Distance to destination is: %.2lf km\n", distance_to_destination);
        remaining_distance = distance_to_destination;
    }
    printf("You have reached your destination!");
    return 0;
}