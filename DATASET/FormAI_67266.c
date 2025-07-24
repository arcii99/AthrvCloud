//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>

// Define the GPS coordinates for the destination
#define DEST_LAT 40.7128
#define DEST_LONG -74.0060

// Define a function that calculates the distance between two GPS coordinate points.
// This function uses the Haversine formula.
double calculateDistance(double lat1, double long1, double lat2, double long2) {
    const double PI = 3.14159265358979323846;
    const double earthRadius = 6371.0; // in km

    double lat1_r = lat1 * PI / 180.0;
    double long1_r = long1 * PI / 180.0;
    double lat2_r = lat2 * PI / 180.0;
    double long2_r = long2 * PI / 180.0;

    double deltaLat = lat2_r - lat1_r;
    double deltaLong = long2_r - long1_r;

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) +
        cos(lat1_r) * cos(lat2_r) *
        sin(deltaLong / 2) * sin(deltaLong / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = earthRadius * c;
    return distance;
}

// Main function
int main() {
    double curr_lat, curr_long, distance_to_dest;

    // Get the current GPS location of the user
    printf("Welcome to GPS Navigation Simulation in C!\n");
    printf("Enter your current GPS latitude: ");
    scanf("%lf", &curr_lat);
    printf("Enter your current GPS longitude: ");
    scanf("%lf", &curr_long);

    // Calculate the distance from the user's current location to the destination
    distance_to_dest = calculateDistance(curr_lat, curr_long, DEST_LAT, DEST_LONG);

    // Display the distance and directions to the user
    printf("You are currently %.2f kilometers away from the destination.\n", distance_to_dest);
    printf("To get to the destination, head %s and then %s.\n", (curr_long > DEST_LONG ? "west" : "east"), (curr_lat > DEST_LAT ? "south" : "north"));

    return 0;
}