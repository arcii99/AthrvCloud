//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float lat, lon;
    printf("Welcome to the GPS Navigation Simulation System.\n");
    while (1) {
        printf("MENU:\n");
        printf("1. Set current location\n");
        printf("2. Find directions to a location\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your current latitude: ");
                scanf("%f", &lat);
                printf("Enter your current longitude: ");
                scanf("%f", &lon);
                printf("Current location set.\n");
                break;
            case 2:
                if (lat == 0.0f && lon == 0.0f) {
                    printf("Current location not set. Please set current location first.\n");
                    break;
                }
                printf("Enter the destination latitude: ");
                scanf("%f", &lat);
                printf("Enter the destination longitude: ");
                scanf("%f", &lon);
                printf("Calculating route to destination...\n");
                // Future code for route calculation goes here
                printf("Route calculation complete. Turn left in 200m.\n");
                break;
            case 3:
                printf("Exiting GPS Navigation Simulation System...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}