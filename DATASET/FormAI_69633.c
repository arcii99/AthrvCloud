//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOCATIONS 20
#define MAX_NAME_LENGTH 30

/* Struct for each location */
struct Location {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
};

/* Struct for the navigation system */
struct Navigation {
    struct Location locations[MAX_LOCATIONS];
    int numLocations;
};

/* Function to add a location to the navigation system */
void addLocation(struct Navigation *navigation, char name[MAX_NAME_LENGTH], float latitude, float longitude) {
    if (navigation->numLocations < MAX_LOCATIONS) {
        strcpy(navigation->locations[navigation->numLocations].name, name);
        navigation->locations[navigation->numLocations].latitude = latitude;
        navigation->locations[navigation->numLocations].longitude = longitude;
        navigation->numLocations++;
        printf("%s added to the navigation system!\n", name);
    } else {
        printf("Error: Navigation system is full.\n");
    }
}

/* Function to find the closest location to the user's current coordinates */
struct Location findClosestLocation(struct Navigation navigation, float latitude, float longitude) {
    float minDistance = 9999999;
    struct Location closestLocation;
    
    for (int i = 0; i < navigation.numLocations; i++) {
        float distance = sqrt(pow(latitude - navigation.locations[i].latitude, 2) + pow(longitude - navigation.locations[i].longitude, 2));
        if (distance < minDistance) {
            minDistance = distance;
            closestLocation = navigation.locations[i];
        }
    }
    
    return closestLocation;
}

/* Function to print out instructions for the user */
void printInstructions() {
    printf("Welcome to the Cyberpunk GPS Navigation Simulation!\n");
    printf("You have just been hired for a job, and you need to navigate through the city to find your destination.\n");
    printf("You will need to enter your current coordinates, and we will tell you the closest location to your destination.\n");
    printf("Good luck!\n");
}

/* Main function */
int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Create the navigation system */
    struct Navigation navigation;
    navigation.numLocations = 0;
    
    /* Add some locations to the navigation system */
    addLocation(&navigation, "Hacker's Den", 24.753575, -77.569022);
    addLocation(&navigation, "Nightclub", 24.746118, -77.561703);
    addLocation(&navigation, "Black Market", 24.747322, -77.573906);
    addLocation(&navigation, "MegaCorp Headquarters", 24.752459, -77.564195);
    addLocation(&navigation, "Gang Hideout", 24.741802, -77.576377);
    addLocation(&navigation, "APC Bank", 24.756602, -77.569091);
    
    /* Print out instructions */
    printInstructions();
    
    /* Get the user's current coordinates */
    float currentLatitude, currentLongitude;
    printf("\nEnter your current latitude: ");
    scanf("%f", &currentLatitude);
    printf("Enter your current longitude: ");
    scanf("%f", &currentLongitude);
    
    /* Find the closest location to the user */
    struct Location closestLocation = findClosestLocation(navigation, currentLatitude, currentLongitude);
    
    /* Print out the closest location */
    printf("\nClosest location to your current coordinates:\n%s (%f, %f)\n", closestLocation.name, closestLocation.latitude, closestLocation.longitude);
    
    return 0;
}