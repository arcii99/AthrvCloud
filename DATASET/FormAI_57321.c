//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: systematic
#include<stdio.h>
#include<math.h>

#define PI 3.14159265

//Structure to hold location coordinates
struct Location {
    double latitude;
    double longitude;
};

//Function to convert degrees to radians
double to_radians(double degrees) {
    return degrees * PI / 180;
}

//Function to calculate distance between two coordinates
double calculate_distance(struct Location loc1, struct Location loc2) {
    double lat1 = to_radians(loc1.latitude);
    double lat2 = to_radians(loc2.latitude);
    double delta_long = to_radians(loc2.longitude - loc1.longitude);

    //Haversine formula
    double a = pow(sin((lat2-lat1)/2),2) + cos(lat1) * cos(lat2) * pow(sin(delta_long/2),2);
    double c = 2 * atan2(sqrt(a),sqrt(1-a));

    //Mean Earth radius in kilometers (can be adjusted based on location)
    double radius = 6371;

    return radius * c;
}

int main() {
    struct Location current_loc = {40.7590, -73.9845}; //Current location coordinates
    struct Location destination_loc = {37.7749, -122.4194}; //Destination location coordinates

    printf("Current location: (%lf, %lf)\n", current_loc.latitude, current_loc.longitude);
    printf("Destination location: (%lf, %lf)\n", destination_loc.latitude, destination_loc.longitude);

    //Calculate distance between current location and destination location
    printf("Distance between current location and destination location: %lf kilometers\n", calculate_distance(current_loc, destination_loc));

    return 0;
}