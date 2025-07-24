//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants for maximum sizes
#define MAX_STR_LEN 100
#define NUM_POIS 5
#define MAP_SIZE 10

//define structs for GPS coordinates and Points of Interest
typedef struct {
    double latitude;
    double longitude;
} coordinates;

typedef struct {
    char name[MAX_STR_LEN];
    coordinates location;
} poi;

//initialize global POI array
poi pois[NUM_POIS];

//function to calculate distance between two GPS coordinates
double calcDistance(coordinates coord1, coordinates coord2) {
    double distLat = coord1.latitude - coord2.latitude;
    double distLong = coord2.longitude - coord1.longitude;
    return sqrt((distLat * distLat) + (distLong * distLong));
}

//function to find nearest POI to current GPS coordinates
poi* findNearestPOI(coordinates currentLocation) {
    double minDist = -1;
    poi* nearestPOI = NULL;
    for (int i = 0; i < NUM_POIS; i++) {
        double dist = calcDistance(currentLocation, pois[i].location);
        if (minDist == -1 || dist < minDist) {
            minDist = dist;
            nearestPOI = &pois[i];
        }
    }
    return nearestPOI;
}

int main() {
    //initialize POI array with sample data
    strcpy(pois[0].name, "Statue of Liberty");
    pois[0].location.latitude = 40.6892;
    pois[0].location.longitude = -74.0445;

    strcpy(pois[1].name, "Eiffel Tower");
    pois[1].location.latitude = 48.8584;
    pois[1].location.longitude = 2.2945;

    strcpy(pois[2].name, "The Great Wall of China");
    pois[2].location.latitude = 40.4319;
    pois[2].location.longitude = 116.5704;

    strcpy(pois[3].name, "Chichen Itza");
    pois[3].location.latitude = 20.6843;
    pois[3].location.longitude = -88.5678;

    strcpy(pois[4].name, "Sydney Opera House");
    pois[4].location.latitude = -33.8568;
    pois[4].location.longitude = 151.2153;

    //initialize current location to random coordinates within map size
    coordinates currentLocation;
    currentLocation.latitude = ((double) rand() / RAND_MAX) * MAP_SIZE;
    currentLocation.longitude = ((double) rand() / RAND_MAX) * MAP_SIZE;

    //prompt user for input to simulate navigation
    char input[MAX_STR_LEN];
    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Your current location is: %.4lf, %.4lf\n", currentLocation.latitude, currentLocation.longitude);
    while (1) {
        printf("Please enter a command (NAVIGATE or QUIT): ");
        fgets(input, MAX_STR_LEN, stdin);
        strtok(input, "\n"); //remove newline character from input string

        //handle NAVIGATE command
        if (strcmp(input, "NAVIGATE") == 0) {
            poi* nearestPOI = findNearestPOI(currentLocation);
            printf("The nearest point of interest is: %s\n", nearestPOI->name);
            printf("Its location is: %.4lf, %.4lf\n", nearestPOI->location.latitude, nearestPOI->location.longitude);
            currentLocation = nearestPOI->location; //update current location to nearest POI
        }

        //handle QUIT command
        else if (strcmp(input, "QUIT") == 0) {
            printf("Thank you for using the GPS Navigation Simulation!\n");
            break; //exit loop and end program
        }

        //handle invalid command
        else {
            printf("Invalid command entered. Please try again.\n");
        }
    }
    return 0;
}