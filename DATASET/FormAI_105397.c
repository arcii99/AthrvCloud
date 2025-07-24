//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 10

#define MAX_DISTANCE 200

struct Location {
    char name[25];
    float latitude;
    float longitude;
};

int main() {
    srand(time(NULL));
    struct Location locations[MAX_LOCATIONS];
    int num_locations;
    printf("Enter the number of locations: ");
    scanf("%d", &num_locations);
    if (num_locations > MAX_LOCATIONS) {
        printf("Error: Maximum number of locations is %d\n", MAX_LOCATIONS);
        return 1;
    }
    printf("\nEnter the name, latitude, and longitude of each location:\n");
    for (int i = 0; i < num_locations; i++) {
        printf("\nLocation %d:\n", i+1);
        printf("Name: ");
        scanf("%s", locations[i].name);
        printf("Latitude (between -90 and 90): ");
        scanf("%f", &locations[i].latitude);
        printf("Longitude (between -180 and 180): ");
        scanf("%f", &locations[i].longitude);
    }
    printf("\nLocations:\n");
    for (int i = 0; i < num_locations; i++) {
        printf("%d. %s: (%.2f,%.2f)\n", i+1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
    int current_location = rand() % num_locations;
    printf("\nStarting location: %s\n", locations[current_location].name);
    while (1) {
        int destination = rand() % num_locations;
        if (destination == current_location) {
            continue;
        }
        float distance = sqrt(pow(locations[destination].latitude - locations[current_location].latitude, 2) +
                              pow(locations[destination].longitude - locations[current_location].longitude, 2));
        if (distance > MAX_DISTANCE) {
            printf("\nDestination location %s is too far away (%.2f km) from current location %s, trying again...\n", locations[destination].name, distance, locations[current_location].name);
            continue;
        }
        printf("\nRoute:\n");
        printf("From: %s (%.2f,%.2f)\n", locations[current_location].name, locations[current_location].latitude, locations[current_location].longitude);
        printf("To: %s (%.2f,%.2f)\n", locations[destination].name, locations[destination].latitude, locations[destination].longitude);
        printf("Distance: %.2f km\n", distance);
        current_location = destination;
        char choice;
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }
    printf("\nProgram terminated.\n");
    return 0;
}