//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTE_LENGTH 100 // Maximum length of a route
#define MAX_POSITION_LENGTH 20 // Maximum length of a position
#define MAX_INSTRUCTIONS_LENGTH 100 // Maximum length of a set of instructions

typedef struct {
    char name[MAX_POSITION_LENGTH]; // Name of the position
    double latitude; // Latitude of the position
    double longitude; // Longitude of the position
} Position;

Position positions[] = { // Array of positions
    {"San Francisco", 37.7749, -122.4194},
    {"Los Angeles", 34.0522, -118.2437},
    {"Las Vegas", 36.1699, -115.1398},
    {"Phoenix", 33.4484, -112.0740},
    {"Houston", 29.7604, -95.3698},
    {"New Orleans", 29.9511, -90.0715}
};

int main() {
    char route[MAX_ROUTE_LENGTH]; // Route input by user
    char instructions[MAX_INSTRUCTIONS_LENGTH]; // Instructions to output
    Position currentPosition; // Current position of user
    int currentPosIndex; // Index of current position in the array
    int x, y; // Variables to store user input for navigation
    int i; // Loop variable

    // Initialize current position
    strcpy(currentPosition.name, positions[0].name);
    currentPosition.latitude = positions[0].latitude;
    currentPosition.longitude = positions[0].longitude;
    currentPosIndex = 0;

    // Welcome the user
    printf("Welcome to the GPS Navigation Simulation!\n\n");

    // Loop until user quits
    while (1) {
        // Print current position
        printf("Current position: %s (%lf,%lf)\n\n", currentPosition.name, currentPosition.latitude, currentPosition.longitude);

        // Get user input for navigation
        printf("Enter X and Y coordinates to navigate towards (0 to quit): ");
        scanf("%d %d", &x, &y);

        // If user chose to quit, exit the loop
        if (x == 0 && y == 0) {
            break;
        }

        // Calculate new position
        double newLat = currentPosition.latitude + (double)x / 1000;
        double newLong = currentPosition.longitude + (double)y / 1000;

        // Find position closest to new position
        double minDist = 999999999;
        for (i = 0; i < sizeof(positions) / sizeof(positions[0]); i++) {
            double dist = sqrt(pow(positions[i].latitude - newLat, 2) + pow(positions[i].longitude - newLong, 2));
            if (dist < minDist) {
                minDist = dist;
                currentPosIndex = i;
            }
        }
        strcpy(currentPosition.name, positions[currentPosIndex].name);
        currentPosition.latitude = positions[currentPosIndex].latitude;
        currentPosition.longitude = positions[currentPosIndex].longitude;

        // Generate instructions
        sprintf(instructions, "Head %d meters towards %s\n\n", (int)minDist * 1000, currentPosition.name);

        // Print instructions
        printf("%s", instructions);
    }

    // Exit program
    printf("Thanks for using the GPS Navigation Simulation!");
    return 0;
}