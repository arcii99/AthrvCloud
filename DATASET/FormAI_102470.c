//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG 57.2957795

// Function to calculate the distance between two GPS coordinates
float distance(float lat1, float long1, float lat2, float long2) {
    float delta_lat = lat2 - lat1;
    float delta_long = long2 - long1;

    float a = pow(sin(delta_lat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(delta_long / 2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float d = 6371 * c;

    return d;
}

// Main function to simulate the GPS navigation
int main() {

    // Define the GPS coordinates of the start and end points
    float lat1 = 51.5074;
    float long1 = -0.1278;

    float lat2 = 48.8566;
    float long2 = 2.3522;

    // Calculate the initial distance and bearing between the two points
    float d = distance(lat1, long1, lat2, long2);
    float bearing = atan2(sin(long2-long1)*cos(lat2), cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(long2-long1));
    bearing *= RAD_TO_DEG;

    printf("Starting location: (%f, %f)\n", lat1, long1);
    printf("Destination: (%f, %f)\n", lat2, long2);
    printf("Initial distance: %f km\n", d);
    printf("Initial bearing: %f degrees\n", bearing);

    // Ask the user for the number of turns in the simulation
    int turns;
    printf("Enter the number of turns in the simulation: ");
    scanf("%d", &turns);

    // Simulate the GPS navigation for the specified number of turns
    float turn_distance = d / turns;
    float current_lat = lat1;
    float current_long = long1;

    for (int i = 0; i < turns; i++) {
        // Calculate the new GPS coordinates based on the turn_distance and bearing
        current_lat += turn_distance * sin(bearing / RAD_TO_DEG);
        current_long += turn_distance * cos(bearing / RAD_TO_DEG);

        // Calculate the new distance and bearing to the destination
        d = distance(current_lat, current_long, lat2, long2);
        bearing = atan2(sin(long2-current_long)*cos(lat2), cos(current_lat)*sin(lat2)-sin(current_lat)*cos(lat2)*cos(long2-current_long));
        bearing *= RAD_TO_DEG;

        printf("\nTurn %d\n", i+1);
        printf("Current location: (%f, %f)\n", current_lat, current_long);
        printf("Distance to destination: %f km\n", d);
        printf("Bearing: %f degrees\n", bearing);
    }

    printf("\nArrived at destination!\n");

    return 0;
}