//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between min and max */
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to simulate the space adventure game */
void spaceAdventure() {
    int fuelLevel = 100;
    int distance = 0;
    int alienEncounter = 0;
    int asteroidEncounter = 0;
    
    printf("Welcome to Space Adventure! You are the captain of the starship USS Enterprise.\n");
    printf("Your mission is to explore new worlds and seek out new life and new civilizations.\n");
    printf("You have a limited supply of fuel, so use it wisely.\n");
    printf("\n\n");
    
    /* Loop until we run out of fuel or reach our destination */
    while (fuelLevel > 0 && distance < 100) {
        
        /* Generate a random event */
        int event = generateRandom(1, 100);
        
        /* Alien Encounter */
        if (event <= 20) {
            printf("You have encountered a hostile alien race!\n");
            alienEncounter++;
            fuelLevel -= 20;
        }
        /* Asteroid Encounter */
        else if (event <= 40) {
            printf("You have encountered an asteroid field!\n");
            asteroidEncounter++;
            fuelLevel -= 10;
        }
        /* Nothing found */
        else {
            printf("Nothing found...\n");
            fuelLevel -= 5;
        }
        
        /* Display fuel level and distance */
        printf("Fuel Level: %d\n", fuelLevel);
        distance += generateRandom(1, 10);
        printf("Distance from Earth: %d\n", distance);
        printf("\n\n");
    }
    
    /* Display final results */
    printf("Mission Complete!\n");
    printf("Alien Encounters: %d\n", alienEncounter);
    printf("Asteroid Encounters: %d\n", asteroidEncounter);
    printf("Final Distance from Earth: %d\n", distance);
    printf("Fuel Remaining: %d\n", fuelLevel);
}

int main() {
    srand(time(0));
    
    spaceAdventure();
    
    return 0;
}