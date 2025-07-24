//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOCATIONS 100

// Define a structure for a location
typedef struct {
    char name[30];
    float latitude;
    float longitude;
} t_location;

// Function to calculate the distance between two locations using the Haversine formula
float calculate_distance(float lat1, float long1, float lat2, float long2) {
    float radius = 6371; // Earth's radius in kilometers
    float d_lat = (lat2 - lat1) * M_PI / 180;
    float d_long = (long2 - long1) * M_PI / 180;
    float a = pow(sin(d_lat / 2), 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * pow(sin(d_long / 2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return radius * c;
}

int main() {
    // Declare variables
    t_location locations[MAX_LOCATIONS];
    int num_locations = 0;
    int i, j;

    // Add some sample locations
    strcpy(locations[0].name, "San Francisco");
    locations[0].latitude = 37.7749;
    locations[0].longitude = -122.4194;
    num_locations++;

    strcpy(locations[1].name, "Los Angeles");
    locations[1].latitude = 34.0522;
    locations[1].longitude = -118.2437;
    num_locations++;

    strcpy(locations[2].name, "Las Vegas");
    locations[2].latitude = 36.1699;
    locations[2].longitude = -115.1398;
    num_locations++;

    // Display the locations
    printf("List of locations:\n");
    for (i = 0; i < num_locations; i++) {
        printf("%d. %s (%f, %f)\n", i+1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }

    // Ask for the user's current location
    t_location current_location;
    printf("\nEnter your current location (latitude, longitude): ");
    scanf("%f, %f", &current_location.latitude, &current_location.longitude);

    // Find the nearest location
    int nearest_location_index = -1;
    float min_distance = INFINITY;
    for (i = 0; i < num_locations; i++) {
        float distance = calculate_distance(current_location.latitude, current_location.longitude, locations[i].latitude, locations[i].longitude);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_location_index = i;
        }
    }

    // Display the nearest location
    printf("\nThe nearest location is %s, which is %f km away.\n", locations[nearest_location_index].name, min_distance);

    return 0;
}