//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Location {
    double latitude;
    double longitude;
};

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Generate random coordinates for current location
    struct Location current_location = {
        .latitude = (double)rand()/(double)(RAND_MAX/180.0) - 90.0,
        .longitude = (double)rand()/(double)(RAND_MAX/360.0) - 180.0,
    };

    // Prompt user for destination coordinates
    printf("Enter destination coordinates (latitude longitude): ");
    struct Location destination_location;
    scanf("%lf %lf", &destination_location.latitude, &destination_location.longitude);

    // Calculate distance between current location and destination
    double latitude_difference = destination_location.latitude - current_location.latitude;
    double longitude_difference = destination_location.longitude - current_location.longitude;
    double distance = sqrt(latitude_difference * latitude_difference + longitude_difference * longitude_difference);

    // Calculate estimated time based on distance
    double estimated_time = distance * 0.5; // Assuming average speed of 30 km/h
    int hours = (int)estimated_time;
    int minutes = (int)((estimated_time - hours) * 60.0);

    // Print navigation instructions
    printf("\nStarting GPS Navigation Simulation...\n\n");
    printf("Current Location: %f, %f\n", current_location.latitude, current_location.longitude);
    printf("Destination: %f, %f\n", destination_location.latitude, destination_location.longitude);
    printf("Distance: %f km\n", distance);
    printf("Estimated Time: %d hours %d minutes\n", hours, minutes);

    return 0;
}