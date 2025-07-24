//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float latitude;
    float longitude;
} coordinates;

void navigate(coordinates current_loc, coordinates destination_loc) {
    float x_diff = destination_loc.latitude - current_loc.latitude;
    float y_diff = destination_loc.longitude - current_loc.longitude;
    float distance = sqrt((x_diff * x_diff) + (y_diff * y_diff));
    printf("Distance to destination: %f km\n", distance);
    if (distance <= 1.0) {
        printf("You have arrived at your destination!\n");
    } else {
        float bearing = atan2(y_diff, x_diff) * 180.0 / 3.14159;
        printf("Current bearing: %f\n", bearing);
        printf("Adjusting course...\n");
        float adjustment = rand() % 30 - 15;
        bearing += adjustment;
        while (bearing < 0.0) {
            bearing += 360.0;
        }
        while (bearing >= 360.0) {
            bearing -= 360.0;
        }
        printf("New bearing: %f\n", bearing);
        coordinates new_loc;
        new_loc.latitude = current_loc.latitude + (distance / 111.0) * sin(bearing * 3.14159 / 180.0);
        new_loc.longitude = current_loc.longitude + (distance / 111.0) * cos(bearing * 3.14159 / 180.0);
        printf("New location: (%f, %f)\n", new_loc.latitude, new_loc.longitude);
        navigate(new_loc, destination_loc);
    }
}

int main() {
    printf("GPS Navigation Simulation\n");
    coordinates current_loc;
    coordinates destination_loc;
    printf("Enter current location (latitude longitude): ");
    scanf("%f%f", &current_loc.latitude, &current_loc.longitude);
    printf("Enter destination location (latitude longitude): ");
    scanf("%f%f", &destination_loc.latitude, &destination_loc.longitude);
    navigate(current_loc, destination_loc);
    return 0;
}