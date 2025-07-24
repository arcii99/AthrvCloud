//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;  
}

int main() {
    // Seed the random generator
    srand(time(0));

    // Initialize the spaceship's attributes
    int hullStrength = generateRandom(50, 100);
    int shieldStrength = generateRandom(50, 100);
    int weaponPower = generateRandom(1, 10);
    int energy = generateRandom(50, 100);

    // Initialize variables for the adventure
    int alienDanger = 0;
    int planetDanger = 0;
    int disasterChance = 0;
    int alienStrength = 0;
    int planetDefense = 0;

    // Intro message
    printf("Welcome to the Procedural Space Adventure, Captain. Your mission is to explore the galaxy and return home safely.\n");

    // Main game loop
    while (hullStrength > 0 && energy > 0) {
        // Generate a random event
        int eventNum = generateRandom(1, 3);
        
        switch (eventNum) {
            case 1: // Alien Encounter
                printf("ALIEN ALERT! Brace for impact.\n");
                alienDanger = generateRandom(1, 10);
                alienStrength = generateRandom(1, 10);
                if (alienDanger > shieldStrength) {
                    hullStrength -= (alienDanger - shieldStrength);
                    printf("The aliens hit your ship for %d damage. Hull strength at %d.\n", (alienDanger - shieldStrength), hullStrength);
                } else {
                    printf("Your shields held up to the alien attack. Shield strength at %d.\n", shieldStrength);
                }

                if (alienStrength > weaponPower) {
                    energy -= (alienStrength - weaponPower);
                    printf("You hit the aliens for %d damage, but they blasted your weapons with a counter-attack. Energy at %d.\n", (alienStrength - weaponPower), energy);
                } else {
                    printf("You hit the aliens for %d damage. Weapon power at %d.\n", weaponPower, (alienStrength - weaponPower));
                }
                break;

            case 2: // Planetary Scavenging
                printf("PLANETARY SCAN! Preparing to land.\n");
                planetDefense = generateRandom(1, 10);
                if (planetDefense > weaponPower) {
                    printf("The planet's defenses were too strong. You returned empty-handed.\n");
                } else {
                    printf("You successfully scavenged the planet's resources. Energy at %d.\n", energy + generateRandom(5, 10));
                }
                break;

            case 3: // Space Disaster
                printf("SPACE DISASTER! Brace for impact.\n");
                disasterChance = generateRandom(1, 10);
                if (disasterChance > hullStrength) {
                    energy -= generateRandom(10, 20);
                    printf("The disaster hit your ship, causing a major energy leak. Energy at %d.\n", energy);
                } else {
                    printf("You skillfully avoided the disaster.\n");
                }
                break;

            default:
                printf("Unknown event occurred.\n");
                break;
        }

        // Update the spaceship's attributes
        hullStrength += generateRandom(0, 5);
        shieldStrength += generateRandom(0, 5);
        weaponPower += generateRandom(0, 2);
        energy -= generateRandom(1, 5);

        // Print the spaceship's current status
        printf("\nCURRENT STATUS:\nHull Strength: %d\nShield Strength: %d\nWeapon Power: %d\nEnergy: %d\n", hullStrength, shieldStrength, weaponPower, energy);
    }

    // End game message
    if (hullStrength <= 0) {
        printf("Your ship has been destroyed. Game Over.\n");
    } else {
        printf("You have run out of energy. Game Over.\n");
    }

    // Exit the program
    return 0;
}