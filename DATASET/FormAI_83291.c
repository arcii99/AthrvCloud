//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: peaceful
#include <stdio.h>

int main() {
    float lat, lon; //coordinates
    float dest_lat = 36.1699; //destination latitude
    float dest_lon = -115.1398; //destination longitude
    int dist = 0; //distance from destination

    printf("Welcome to GPS Navigation\n\n");

    printf("Please enter your starting latitude: ");
    scanf("%f", &lat);

    printf("Please enter your starting longitude: ");
    scanf("%f", &lon);

    while ((lat != dest_lat) || (lon != dest_lon)) {
        printf("Driving...\n");

        //calculate distance from destination
        dist = sqrt((dest_lat - lat) * (dest_lat - lat) + (dest_lon - lon) * (dest_lon - lon));

        //update latitude and longitude based on current position and direction of travel
        if (dist > 10) {
            lat += (dest_lat - lat) / dist * 10;
            lon += (dest_lon - lon) / dist * 10;
        } else {
            lat = dest_lat;
            lon = dest_lon;
        }

        //print current position and distance from destination
        printf("Current position: (%.4f, %.4f)\n", lat, lon);
        printf("Distance from destination: %d km\n\n", dist);
    }

    printf("Congratulations, you have arrived at your destination!\n");

    return 0;
}