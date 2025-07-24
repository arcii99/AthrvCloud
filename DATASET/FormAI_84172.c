//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 20
#define MAX_ROUTES 20

struct location {
    int id;
    float latitude;
    float longitude;
};

struct route {
    int id;
    int start;
    int end;
};

struct car {
    int id;
    int current_location;
};

struct gps {
    int id;
    int current_car;
    struct location destinations[MAX_LOCATIONS];
    struct route routes[MAX_ROUTES];
};

int main() {
    srand(time(0));

    struct gps my_gps;

    my_gps.id = 10;
    my_gps.current_car = rand() % 3 + 1;

    // Generate random locations
    for (int i = 0; i < MAX_LOCATIONS; i++) {
        my_gps.destinations[i].id = i + 1;
        my_gps.destinations[i].latitude = (float) (rand() % 901 + 100) / 10;
        my_gps.destinations[i].longitude = (float) (rand() % 1801 + 100) / 10 * -1;
    }

    // Generate random routes
    for (int i = 0; i < MAX_ROUTES; i++) {
        my_gps.routes[i].id = i + 1;
        my_gps.routes[i].start = rand() % MAX_LOCATIONS + 1;
        my_gps.routes[i].end = rand() % MAX_LOCATIONS + 1;
    }

    // Generate random car and current location
    struct car my_car;
    my_car.id = my_gps.current_car;
    my_car.current_location = rand() % MAX_LOCATIONS + 1;

    printf("GPS Navigation Simulation\n");
    printf("------------------------\n\n");
    printf("GPS ID: %d\n", my_gps.id);
    printf("Current Car: %d\n", my_car.id);
    printf("Current Location: %d\n\n", my_car.current_location);

    // Search for routes that start at the current location
    printf("Available Routes:\n");
    for (int i = 0; i < MAX_ROUTES; i++) {
        if (my_gps.routes[i].start == my_car.current_location)
            printf("- Route %d: Start: %d, End: %d\n", my_gps.routes[i].id, my_gps.routes[i].start, my_gps.routes[i].end);
    }

    // Generate random destination and calculate distance
    int destination_index = rand() % MAX_LOCATIONS;
    float destination_lat = my_gps.destinations[destination_index].latitude;
    float destination_long = my_gps.destinations[destination_index].longitude;

    float distance = sqrt(pow(my_gps.destinations[destination_index].latitude - my_gps.destinations[my_car.current_location - 1].latitude, 2)
                          + pow(my_gps.destinations[destination_index].longitude - my_gps.destinations[my_car.current_location - 1].longitude, 2));

    printf("\nNext Destination:\n");
    printf("- Location: %d\n", my_gps.destinations[destination_index].id);
    printf("- Latitude: %f\n", destination_lat);
    printf("- Longitude: %f\n", destination_long);
    printf("- Distance: %f km\n\n", distance);

    return 0;
}