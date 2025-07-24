//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int latitude, longitude, distance, choice;
    srand(time(NULL));

    printf("Welcome to GPS Navigation Simulator!\n\n");
    printf("Please enter your current location:\n");
    printf("Latitude: ");
    scanf("%d", &latitude);
    printf("Longitude: ");
    scanf("%d", &longitude);

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Navigate to a random location\n");
        printf("2. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Generate a random destination
                int dest_latitude = rand() % 181 - 90;   // Range of -90 to +90
                int dest_longitude = rand() % 361 - 180; // Range of -180 to +180

                // Calculate distance to destination
                int dlat = dest_latitude - latitude;
                int dlong = dest_longitude - longitude;
                distance = (int) sqrt(dlat * dlat + dlong * dlong);

                // Display destination and distance
                printf("\nDestination: (%d, %d)\n", dest_latitude, dest_longitude);
                printf("Distance: %d km\n", distance);
                break;
            case 2:
                printf("\nThank you for using GPS Navigation Simulator!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}