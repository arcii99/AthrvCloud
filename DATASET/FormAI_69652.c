//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Random seed based on current time
    srand(time(0));

    // Initializing variables
    int fuelLevel = 100, healthLevel = 100, alienCount = 0;
    int xPosition = 0, yPosition = 0, zPosition = 0;

    // Exploring space
    for (int i = 1; i <= 10; i++) {
        printf("Exploring sector %d...\n", i);

        // Random event: alien encounter
        int encounter = rand() % 10 + 1;
        if (encounter <= 3) {
            printf("ALIEN ENCOUNTER!\n");

            // Random number of aliens (1-5)
            int aliens = rand() % 5 + 1;
            printf("There are %d aliens attacking!\n", aliens);

            // Health level decreases with each alien encounter
            healthLevel -= aliens * 10;
            alienCount += aliens;
        }

        // Random event: asteroid field
        else if (encounter > 3 && encounter <= 6) {
            printf("ASTEROID FIELD!\n");

            // Random chance of being hit (50%)
            int hitChance = rand() % 2;
            if (hitChance == 1) {
                printf("You have been hit!\n");

                // Fuel level decreases with each hit
                fuelLevel -= 20;
            }
            else {
                printf("You have dodged the asteroids!\n");
            }
        }

        // Random event: alien planet discovery
        else {
            printf("ALIEN PLANET DISCOVERED!\n");

            // Random coordinates (between -50 and 50)
            xPosition = rand() % 101 - 50;
            yPosition = rand() % 101 - 50;
            zPosition = rand() % 101 - 50;

            printf("Coordinates: (%d, %d, %d)\n", xPosition, yPosition, zPosition);
        }

        // Display remaining fuel and health levels
        printf("Fuel Level: %d\n", fuelLevel);
        printf("Health Level: %d\n", healthLevel);

        // Check if fuel or health levels have reached zero
        if (fuelLevel <= 0) {
            printf("OUT OF FUEL! GAME OVER.\n");
            return 0;
        }
        else if (healthLevel <= 0) {
            printf("OUT OF HEALTH! GAME OVER.\n");
            return 0;
        }

        // Rest for 1 second before exploring next sector
        printf("Resting...\n");
        sleep(1);
    }

    // Successful completion of space adventure
    printf("CONGRATULATIONS! You have completed the space adventure.\n");
    printf("Final Fuel Level: %d\n", fuelLevel);
    printf("Final Health Level: %d\n", healthLevel);
    printf("Aliens Encountered: %d\n", alienCount);
    printf("Final Position: (%d, %d, %d)\n", xPosition, yPosition, zPosition);
    return 0;
}