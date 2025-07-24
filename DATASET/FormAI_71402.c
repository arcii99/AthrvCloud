//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Set seed for randomly generated events
    int health = 100; // Set initial health
    int score = 0; // Set initial score
    
    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("Your mission is to explore the galaxy while avoiding hazards that reduce your health.\n");
    printf("You will earn points for each planet you discover.\n\n");
    
    while (health > 0) {
        int event = rand() % 5 + 1; // Randomly generate an event
        
        if (event == 1) {
            printf("You safely arrived at a new planet! +50 points.\n");
            score += 50;
        } else if (event == 2) {
            printf("Your ship was hit by asteroid and lost 10 health.\n");
            health -= 10;
        } else if (event == 3) {
            printf("Your ship landed on a planet with dangerous creatures! Lost 20 health.\n");
            health -= 20;
        } else if (event == 4) {
            printf("Your ship encountered hostile aliens and had to maneuver to safety. Lost 15 health.\n");
            health -= 15;
        } else {
            printf("You found a rare space artifact worth +100 points!\n");
            score += 100;
        }
        printf("Current health: %d\n", health);
        printf("Current score: %d\n", score);
        
    }
    printf("Game over! You scored %d points.\n", score);
    
    return 0;
}