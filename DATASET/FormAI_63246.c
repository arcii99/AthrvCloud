//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void introduce();
int explorePlanet(int planetNumber);
int fightAlien();
void gameOver();

// Global variables
int explorationPoints = 0;
int alienCount = 0;

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Introduction
    introduce();
    
    // Explore planets
    for(int i = 1; i <= 5; i++) {
        explorationPoints += explorePlanet(i);
    }
    
    // Fight aliens
    printf("\nYou encounter %d aliens.\n", alienCount);
    for(int i = 1; i <= alienCount; i++) {
        if(fightAlien()) {
            printf("Alien defeated!\n");
        }
        else {
            // Game over
            gameOver();
            return 0;
        }
    }
    
    // Victory
    printf("\nCongratulations, you have successfully completed your space adventure!\n");
    printf("Your exploration points: %d\n", explorationPoints);
    
    return 0;
}

void introduce() {
    printf("Welcome to your space adventure!\n");
    printf("You will explore 5 planets and fight aliens along the way.\n");
    printf("Good luck!\n\n");
}

int explorePlanet(int planetNumber) {
    printf("Exploring planet %d...\n", planetNumber);
    
    // Generate exploration points
    int points = rand() % 100 + 1;
    printf("You found %d exploration points!\n", points);
    
    return points;
}

int fightAlien() {
    int playerHealth = 100;
    int alienHealth = 100;
    
    printf("\nYou encounter an alien!\n");
    
    // Fight loop
    while(playerHealth > 0 && alienHealth > 0) {
        // Player attacks
        int playerDamage = rand() % 30 + 1;
        alienHealth -= playerDamage;
        printf("You hit the alien for %d damage!\n", playerDamage);
        if(alienHealth <= 0) {
            return 1;
        }
        
        // Alien attacks
        int alienDamage = rand() % 30 + 1;
        playerHealth -= alienDamage;
        printf("The alien hit you for %d damage!\n", alienDamage);
        if(playerHealth <= 0) {
            return 0;
        }
    }
}

void gameOver() {
    printf("\nGame over!\n");
    printf("You were defeated by an alien...\n");
    printf("Better luck next time!\n");
}