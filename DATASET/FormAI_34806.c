//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define structure for GPS coordinates
typedef struct {
    int latitude;
    int longitude;
} GPS;

// define main function
int main() {
    // seed random number generator
    srand(time(0));

    // initialize starting GPS coordinates
    GPS current_coordinates;
    current_coordinates.latitude = 0;
    current_coordinates.longitude = 0;

    // initialize destination GPS coordinates (generated randomly within a range)
    GPS dest_coordinates;
    dest_coordinates.latitude = rand() % 100;
    dest_coordinates.longitude = rand() % 100;

    // print starting and destination coordinates
    printf("Starting GPS Coordinates: Latitude %d, Longitude %d\n", current_coordinates.latitude, current_coordinates.longitude);
    printf("Destination GPS Coordinates: Latitude %d, Longitude %d\n", dest_coordinates.latitude, dest_coordinates.longitude);

    // initialize navigation variables
    int distance_traveled = 0;
    int distance_to_dest = abs(dest_coordinates.latitude - current_coordinates.latitude) + abs(dest_coordinates.longitude - current_coordinates.longitude);

    // simulate navigation until the destination is reached
    while (distance_to_dest > 0) {
        // generate random direction
        int direction = rand() % 4; // 0 = north, 1 = east, 2 = south, 3 = west

        // update current GPS coordinates based on direction
        switch (direction) {
            case 0: // north
                current_coordinates.latitude++;
                break;
            case 1: // east
                current_coordinates.longitude++;
                break;
            case 2: // south
                current_coordinates.latitude--;
                break;
            case 3: // west
                current_coordinates.longitude--;
                break;
        }

        // update navigation variables
        distance_traveled++;
        distance_to_dest = abs(dest_coordinates.latitude - current_coordinates.latitude) + abs(dest_coordinates.longitude - current_coordinates.longitude);

        // print updated GPS coordinates
        printf("Current GPS Coordinates: Latitude %d, Longitude %d\n", current_coordinates.latitude, current_coordinates.longitude);
    }

    // print final navigation information
    printf("\nDestination reached in %d moves and %d distance traveled.\n", distance_traveled, abs(distance_traveled - distance_to_dest));

    // exit program
    return 0;
}