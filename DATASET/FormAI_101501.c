//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

typedef struct Coordinate {
    float latitude;
    float longitude;
} Coordinate;

void navigate(Coordinate current_location, Coordinate destination_location) {
    // simulate GPS navigation
    float distance = 0.0;
    int step_count = 0;
    enum Direction current_direction = NORTH;

    while(current_location.latitude != destination_location.latitude 
          || current_location.longitude != destination_location.longitude) {
        if(current_location.latitude < destination_location.latitude) {
            current_location.latitude += 0.001;
            distance += 0.001;
            printf("Step %d: Moved North to latitude %f, longitude %f\n", step_count++, current_location.latitude, current_location.longitude);
            current_direction = NORTH;
        } else if (current_location.latitude > destination_location.latitude) {
            current_location.latitude -= 0.001;
            distance += 0.001;
            printf("Step %d: Moved South to latitude %f, longitude %f\n", step_count++, current_location.latitude, current_location.longitude);
            current_direction = SOUTH;
        } else if (current_location.longitude < destination_location.longitude) {
            current_location.longitude += 0.001;
            distance += 0.001;
            printf("Step %d: Moved East to latitude %f, longitude %f\n", step_count++, current_location.latitude, current_location.longitude);
            current_direction = EAST;
        } else {
            current_location.longitude -= 0.001;
            distance += 0.001;
            printf("Step %d: Moved West to latitude %f, longitude %f\n", step_count++, current_location.latitude, current_location.longitude);
            current_direction = WEST;
        }
    }
    printf("You have reached your destination!\n");
    printf("Total distance traveled was %f km\n", distance);
    printf("Your final location is latitude %f, longitude %f\n", current_location.latitude, current_location.longitude);
    printf("Your final direction is %d\n", current_direction);
}

int main() {
    Coordinate current_location = {35.661333, 139.704051};
    Coordinate destination_location = {35.657682, 139.703850};
    navigate(current_location, destination_location);
    return 0;
}