//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about the space adventure
struct Adventure {
    char title[50];
    char description[250];
    char hostile[50];
    int numPlanets;
};

// Function to start the space adventure
void startAdventure(struct Adventure adventure) {
    printf("%s\n", adventure.title);
    printf("%s\n", adventure.description);
    printf("Number of planets in this adventure: %d\n\n", adventure.numPlanets);

    // Loop through each planet and display information
    for (int i = 0; i < adventure.numPlanets; i++) {
        printf("Planet %d\n", i+1);
        printf("Hostile: %s\n\n", adventure.hostile);
    }
}

int main() {
    // Initialize the space adventure
    struct Adventure adventure;
    strcpy(adventure.title, "The Quest for the Galactic Gemstone");
    strcpy(adventure.description, "Join us on a journey through the galaxy to find the legendary Galactic Gemstone.");
    strcpy(adventure.hostile, "Yes");
    adventure.numPlanets = 5;

    // Start the space adventure
    startAdventure(adventure);

    return 0;
}