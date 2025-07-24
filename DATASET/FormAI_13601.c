//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int car_direction = rand() % 360;
    float latitude = 0.0, longitude = 0.0, destination_latitude = 0.0, destination_longitude = 0.0;
    int distance = 0, heading = 0;

    printf("Welcome to the GPS Navigation Simulator!\n\n");

    // Ask for user's current location
    printf("Please enter your current latitude: ");
    scanf("%f", &latitude);
    printf("Please enter your current longitude: ");
    scanf("%f", &longitude);

    // Ask for user's destination
    printf("Please enter your destination latitude: ");
    scanf("%f", &destination_latitude);
    printf("Please enter your destination longitude: ");
    scanf("%f", &destination_longitude);

    // Calculate distance and heading
    distance = (int)(sqrt(pow(destination_latitude - latitude, 2) + pow(destination_longitude - longitude, 2)) * 111000);
    heading = (int)(atan2(destination_longitude - longitude, destination_latitude - latitude) * 180 / 3.14159);

    // Display directions
    printf("\nYou are currently facing %d degrees.\n", car_direction);
    printf("Your destination is %d meters away at a heading of %d degrees.\n", distance, heading);

    if (car_direction == heading) {
        printf("You are facing the right direction. Keep going straight ahead!\n");
    } else if (car_direction < heading) {
        printf("Turn left by %d degrees.\n", heading - car_direction);
    } else {
        printf("Turn right by %d degrees.\n", car_direction - heading);
    }

    return 0;
}