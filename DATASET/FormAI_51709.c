//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function to simulate a space adventure
void spaceAdventure(char* planetName, int planetNumber) {
    printf("\nWelcome to planet %s, adventure seeker!", planetName);
    printf("\nYou are the %dth space explorer to set foot on this planet.", planetNumber);

    // Generate random events for the adventure
    int randEvent = rand() % 4;
    switch(randEvent) {
        case 0:
            printf("\n\nThe terrain on this planet is treacherous. Watch your step!");
            break;
        case 1:
            printf("\n\nYou encounter a friendly alien race. They share their knowledge of the planet with you.");
            break;
        case 2:
            printf("\n\nA fierce storm is approaching. Seek shelter before it's too late!");
            break;
        case 3:
            printf("\n\nYou discover a hidden cave system. Who knows what secrets it holds?");
            break;
    }
}

int main() {
    // Define an array of planet names
    char planetNames[5][10] = {"Mars", "Venus", "Jupiter", "Saturn", "Pluto"};

    // Seed the random number generator
    srand(time(0));

    int planetCount = sizeof(planetNames) / sizeof(planetNames[0]);
    int planetNumber = 1;

    // Loop through each planet, simulating a space adventure for each one
    for(int i=0; i<planetCount; i++) {
        spaceAdventure(planetNames[i], planetNumber);
        planetNumber++;
    }

    printf("\n\nThanks for playing!\n");

    return 0;
}