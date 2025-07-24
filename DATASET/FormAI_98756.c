//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    double latitude;
    double longitude;
} Location;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Location location;
} Destination;

Destination destinations[MAX_LOCATIONS];
int num_destinations = 0;

void add_destination(char *name, double latitude, double longitude) {
    if (num_destinations < MAX_LOCATIONS) {
        strcpy(destinations[num_destinations].name, name);
        destinations[num_destinations].location.latitude = latitude;
        destinations[num_destinations].location.longitude = longitude;
        num_destinations++;
    } else {
        printf("Maximum number of destinations reached.\n");
    }
}

void print_destinations() {
    int i;
    printf("Destinations:\n");
    for (i = 0; i < num_destinations; i++) {
        printf("%d. %s: (%f, %f)\n", i + 1, destinations[i].name, destinations[i].location.latitude, destinations[i].location.longitude);
    }
}

double calculate_distance(Location location1, Location location2) {
    double d1 = location1.latitude - location2.latitude;
    double d2 = location1.longitude - location2.longitude;
    return sqrt(d1 * d1 + d2 * d2);
}

void navigate(Location current_location) {
    int i;
    double closest_distance = -1;
    int closest_destination_index = -1;
    for (i = 0; i < num_destinations; i++) {
        double distance = calculate_distance(current_location, destinations[i].location);
        if (closest_distance < 0 || distance < closest_distance) {
            closest_distance = distance;
            closest_destination_index = i;
        }
    }
    if (closest_destination_index < 0) {
        printf("No destinations found.\n");
    } else {
        Destination closest_destination = destinations[closest_destination_index];
        printf("Navigating to %s. Distance: %f\n", closest_destination.name, closest_distance);
    }
}

int main() {
    add_destination("Eiffel Tower", 48.8584, 2.2945);
    add_destination("Statue of Liberty", 40.6892, -74.0445);
    add_destination("Sydney Opera House", -33.8568, 151.2153);

    print_destinations();

    navigate((Location){37.7749, -122.4194});

    return 0;
}