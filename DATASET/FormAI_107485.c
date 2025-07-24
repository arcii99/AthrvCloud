//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
// Welcome to the GPS Navigation Simulation program!
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct location {
    double latitude;
    double longitude;
};

int main() {

    srand(time(NULL)); // initialize random seed for generating random coordinates

    // create some test coordinates for the simulation
    struct location coords[] = {
        {51.5074, -0.1278}, // London, UK
        {40.7128, -74.0060}, // New York City, USA
        {35.6895, 139.6917}, // Tokyo, Japan
        {48.8566, 2.3522}, // Paris, France
        {-33.8688, 151.2093} // Sydney, Australia
    };

    printf("Welcome to the GPS Navigation Simulation program!\n\n");

    printf("We will select a random city and simulate navigating to another randomly selected city on Earth.\n");

    // select random starting point and destination
    int start_index = rand() % 5;
    int dest_index = rand() % 5;
    while (dest_index == start_index) { // make sure destination is not the same as starting point
        dest_index = rand() % 5;
    }

    printf("\nSelected starting point: (%.4f, %.4f)\n", coords[start_index].latitude, coords[start_index].longitude);
    printf("Selected destination: (%.4f, %.4f)\n", coords[dest_index].latitude, coords[dest_index].longitude);

    // simulate navigation
    int distance = abs(start_index - dest_index) * 1000; // assume 1 unit = 1000km
    printf("\nNavigating to destination...\n");
    printf("Distance to destination: %dkm\n", distance);

    printf("Arrived at destination! Have a safe trip.\n");

    return 0;
}