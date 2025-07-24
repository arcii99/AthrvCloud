//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
// Welcome to the most exciting GPS Navigation Simulation program!
// Get set for an adventure with this unique program
#include <stdio.h>
#include <stdlib.h>

// struct to represent a location on the map
typedef struct Location {
    char name[20];
    float latitude;
    float longitude;
} Location;

int main() {
    // initialize list of locations
    Location locations[5];
    strcpy(locations[0].name, "Home");
    locations[0].latitude = 37.7749;
    locations[0].longitude = -122.4194;
    strcpy(locations[1].name, "Golden Gate Park");
    locations[1].latitude = 37.7694;
    locations[1].longitude = -122.4862;
    strcpy(locations[2].name, "Fisherman's Wharf");
    locations[2].latitude = 37.8080;
    locations[2].longitude = -122.4177;
    strcpy(locations[3].name, "Alcatraz Island");
    locations[3].latitude = 37.8268;
    locations[3].longitude = -122.4228;
    strcpy(locations[4].name, "Union Square");
    locations[4].latitude = 37.7881;
    locations[4].longitude = -122.4075;

    // print list of locations
    printf("List of Locations:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (%f, %f)\n", i+1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }

    // get user's starting and ending locations
    int start, end;
    printf("Enter the number of your starting location: ");
    scanf("%d", &start);
    printf("Enter the number of your ending location: ");
    scanf("%d", &end);

    // calculate route and distance
    float distance = sqrt(pow(locations[end-1].latitude - locations[start-1].latitude, 2) + pow(locations[end-1].longitude - locations[start-1].longitude, 2));
    printf("\nYour route from %s to %s is %f miles.\n", locations[start-1].name, locations[end-1].name, distance);

    // give directions to user
    printf("Directions:\n");
    if (locations[start-1].latitude < locations[end-1].latitude) {
        printf("- Travel North ");
        if (locations[start-1].longitude < locations[end-1].longitude) {
            printf("East");
        } else {
            printf("West");
        }
    } else {
        printf("- Travel South ");
        if (locations[start-1].longitude < locations[end-1].longitude) {
            printf("East");
        } else {
            printf("West");
        }
    }
    printf(" for %f miles.\n", distance);

    // program complete
    printf("\nThank you for choosing this GPS Navigation Simulation! Have a safe trip!\n");

    return 0;
}