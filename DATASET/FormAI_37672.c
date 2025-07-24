//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of planets in the adventure
#define MAX_PLANETS 5

// Define a struct for each planet in the adventure
struct Planet {
    char name[20];
    char description[50];
    int distanceFromEarth;
};

int main() {
    // Define the array of planets
    struct Planet planets[MAX_PLANETS];

    // Initialize each planet's information
    strcpy(planets[0].name, "Planet X");
    strcpy(planets[0].description, "A mysterious planet with plenty of secrets.");
    planets[0].distanceFromEarth = 1000;

    strcpy(planets[1].name, "Zarthon");
    strcpy(planets[1].description, "A beautiful, peaceful planet with blue skies and green grass.");
    planets[1].distanceFromEarth = 2000;

    strcpy(planets[2].name, "Nebula");
    strcpy(planets[2].description, "A planet covered in a colorful nebula, with strange creatures roaming about.");
    planets[2].distanceFromEarth = 5000;

    strcpy(planets[3].name, "Void");
    strcpy(planets[3].description, "A barren, lifeless planet with nothing but rocks and dust.");
    planets[3].distanceFromEarth = 10000;

    strcpy(planets[4].name, "Vulcan");
    strcpy(planets[4].description, "A planet filled with active volcanoes and intense earthquakes.");
    planets[4].distanceFromEarth = 15000;

    // Welcome the player to the adventure and ask for their name
    char playerName[20];
    printf("Welcome to the Procedural Space Adventure! What is your name?\n");
    scanf("%s", playerName);

    printf("Hello, %s! You are embarking on an adventure through space.\n", playerName);
    printf("You have a spaceship with enough fuel to travel to %d light-years away from Earth.\n", planets[MAX_PLANETS-1].distanceFromEarth);

    // Loop through each planet in the adventure
    for (int i = 0; i < MAX_PLANETS; i++) {
        // If the planet is too far away, skip it
        if (planets[i].distanceFromEarth > planets[MAX_PLANETS-1].distanceFromEarth) {
            continue;
        }

        // Describe the planet to the player
        printf("\n******************************************\n");
        printf("PLANET: %s\n", planets[i].name);
        printf("DESCRIPTION: %s\n", planets[i].description);

        // Ask the player if they want to visit the planet
        char choice;
        printf("\n%s, would you like to visit this planet? (y/n)\n", playerName);
        scanf(" %c", &choice);

        // If they choose to visit, give them some information about the planet and update their distance traveled
        if (choice == 'y') {
            printf("\n%s, you have traveled %d light-years.\n", playerName, planets[i].distanceFromEarth);
            printf("You have arrived at %s!\n", planets[i].name);

            // Update the player's fuel supply based on distance traveled
            int fuelRemaining = planets[MAX_PLANETS-1].distanceFromEarth - planets[i].distanceFromEarth;
            printf("You now have %d fuel units remaining.\n", fuelRemaining);
        }
    }

    // End the adventure
    printf("\n******************************************\n");
    printf("Congratulations, %s! You have completed your Procedural Space Adventure.\n", playerName);

    return 0;
}