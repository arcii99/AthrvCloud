//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

void investigate_planet(int planet) {
    printf("Investigating planet %d...\n", planet);

    // Space debris found on this planet
    bool debris_found = true;

    if (debris_found) {
        printf("There appears to be evidence of a recent space battle here.\n");

        // Analyze the debris
        int debris_code = 23;

        if (debris_code == 23) {
            printf("The debris matches that of the notorious space pirate Blackbeard.\n");
        }
        else {
            printf("The debris does not match any known space vessels.\n");
        }
    }
    else {
        printf("No evidence of space activity found on this planet.\n");
    }
}

void search_for_clues() {
    printf("Searching for clues...\n");

    // A strange energy signature is detected nearby
    bool energy_detected = true;

    if (energy_detected) {
        printf("The energy signature is coming from a nearby asteroid field.\n");

        // Investigate the asteroid field
        int asteroid_number = 8;

        if (asteroid_number > 10) {
            printf("This asteroid field shows signs of recent mining activity.\n");
        }
        else {
            printf("No signs of mining activity found in this asteroid field.\n");
        }
    }
    else {
        printf("No unusual energy signatures detected.\n");
    }
}

int main() {
    printf("Welcome, space adventurer!\n");

    // Set the destination planet
    int planet_number = 3;

    printf("You have been tasked with investigating planet %d.\n", planet_number);

    // Investigate the planet for space debris
    investigate_planet(planet_number);

    // Search for more clues in nearby space
    search_for_clues();

    printf("Mission complete!\n");

    return 0;
}