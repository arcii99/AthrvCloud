//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example asynchronous GPS navigation program */

typedef struct {
    float latitude;
    float longitude;
} GPSLocation;

int main(int argc, char* argv[]) {
    // initialize variables
    int index = 0;
    GPSLocation locations[10];
    float current_lat = 0;
    float current_lon = 0;
    
    // simulate getting GPS data asynchronously
    while (index < 10) {
        GPSLocation location;
        location.latitude = ((float)rand()/(float)(RAND_MAX)) * 180.0 - 90.0;
        location.longitude = ((float)rand()/(float)(RAND_MAX)) * 360.0 - 180.0;
        locations[index] = location;
        index++;
    }
    
    // simulate navigating to each location asynchronously
    for (int i = 0; i < 10; i++) {
        // set current location
        current_lat = ((float)rand()/(float)(RAND_MAX)) * 180.0 - 90.0;
        current_lon = ((float)rand()/(float)(RAND_MAX)) * 360.0 - 180.0;
        
        // calculate distance to location
        float lat_diff = current_lat - locations[i].latitude;
        float lon_diff = current_lon - locations[i].longitude;
        float distance = sqrt(lat_diff*lat_diff + lon_diff*lon_diff);
        
        // output distance and location information
        printf("Navigating to location %d\n", i+1);
        printf("Distance: %.2f km\n", distance);
        printf("Destination: (%.2f, %.2f)\n", locations[i].latitude, locations[i].longitude);
    }
    
    return 0;
}