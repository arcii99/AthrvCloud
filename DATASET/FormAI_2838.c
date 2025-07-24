//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>

// Defining a struct for the player's ship
struct Spaceship {
    int shield;
    int hull;
    int weapons;
    int energy;
};

// Defining a struct for alien spacecraft
struct AlienShip {
    int shield;
    int weapons;
};

int main() {
    int sector = 1; // Starting sector
    int score = 0; // Initializing score
    int choice; // User input variable
    struct Spaceship playerShip = { 100, 100, 100, 100 }; // Initializing player's ship
    
    // Game loop
    while (playerShip.hull > 0) {
        printf("You are in sector %d, what would you like to do?\n", sector);
        printf("1. Move to the next sector.\n");
        printf("2. Search for resources.\n");
        printf("3. Attack an alien spacecraft.\n");
        printf("4. Check your ship's status.\n");
        printf("5. Quit game.\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Move to the next sector
                sector++;
                printf("You move to sector %d.\n", sector);
                break;
                
            case 2: // Search for resources
                // Randomly generate resources found
                int energyFound = rand() % 25 + 1;
                int weaponsFound = rand() % 25 + 1;
                int shieldFound = rand() % 25 + 1;
                printf("You find %d energy, %d weapons, and %d shield parts.\n", energyFound, weaponsFound, shieldFound);
                // Add resources to player's ship
                playerShip.energy += energyFound;
                playerShip.weapons += weaponsFound;
                playerShip.shield += shieldFound;
                // Increase score
                score += 10;
                break;
                
            case 3: // Attack an alien spacecraft
                {
                    // Creating an alien ship
                    struct AlienShip alienShip = { 50, 75 };
                    printf("You engage in battle with an alien spacecraft!\n");
                    // Battle loop
                    while (playerShip.hull > 0 && alienShip.shield > 0) {
                        // Player's turn
                        int attack = (rand() % playerShip.weapons + 1) * playerShip.energy / 100;
                        alienShip.shield -= attack;
                        printf("You attack the alien spacecraft with %d damage! Alien spacecraft has %d shield left.\n", attack, alienShip.shield);
                        // Alien's turn
                        attack = (rand() % alienShip.weapons + 1) * 25 / playerShip.shield;
                        playerShip.hull -= attack;
                        printf("Alien spacecraft attacks you with %d damage! You have %d hull left.\n", attack, playerShip.hull);
                    }
                    // Check who won the battle
                    if (playerShip.hull > 0) {
                        printf("You have defeated the alien spacecraft! You gain 50 score points.\n");
                        score += 50;
                    }
                    else {
                        printf("Your ship has been destroyed by the alien spacecraft! GAME OVER.\n");
                        printf("You scored %d points.\n", score);
                        return 0;
                    }
                    break;
                }
                
            case 4: // Check your ship's status
                printf("Your ship has:\n");
                printf("- %d shield parts.\n", playerShip.shield);
                printf("- %d hull points.\n", playerShip.hull);
                printf("- %d weapons.\n", playerShip.weapons);
                printf("- %d energy.\n", playerShip.energy);
                break;
                
            case 5: // Quit game
                printf("You have quit the game. You scored %d points.\n", score);
                return 0;
                
            default: // Invalid input
                printf("Invalid input. Please choose again.\n");
                break;
        }
    }
    
    printf("Your ship has been destroyed! GAME OVER.\n");
    printf("You scored %d points.\n", score);
    return 0;
}