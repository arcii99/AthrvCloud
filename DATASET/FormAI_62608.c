//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Predefined GPS coordinates
    float GPS_start[2] = {42.397559, -71.120238};
    float GPS_end[2] = {42.358771, -71.057703};
    
    // Generate random coordinates with a certain degree of variation
    float GPS_current[2] = {GPS_start[0], GPS_start[1]};
    float GPS_error = 0.0005; // Adjust as needed
    float GPS_variation = GPS_error * 2;
    while (GPS_current[0] != GPS_end[0] || GPS_current[1] != GPS_end[1]) {
        GPS_current[0] += (rand() / (float) RAND_MAX) * GPS_variation - GPS_error;
        GPS_current[1] += (rand() / (float) RAND_MAX) * GPS_variation - GPS_error;
        printf("Current GPS Coordinates: %f, %f\n", GPS_current[0], GPS_current[1]);
    }
    
    printf("You have arrived at your destination!\n");
    
    return 0;
}