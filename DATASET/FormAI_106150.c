//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define SHIP_HP 10
#define ALIEN_HP 3
#define MAX_LEVEL 5

// function prototypes
void displayIntro();
void displayOutro(int score);
int playGame(int level);

int main() {
    srand(time(NULL)); // seed random number generator
    int score = 0;
    displayIntro();
    for(int i = 1; i <= MAX_LEVEL; i++) {
        printf("LEVEL %d\n", i);
        score += playGame(i);
    }
    displayOutro(score);
    return 0;
}

void displayIntro() {
    printf("\n\nWelcome to Retro Space Adventure!\n");
    printf("You are the captain of a spaceship and your mission is to complete 5 levels of space combat.\n");
    printf("Each level will get progressively more difficult, but the rewards will also be greater.\n");
    printf("Good luck, captain!\n\n");
}

void displayOutro(int score) {
    printf("\n\nCongratulations on completing all 5 levels!\n");
    printf("Your final score is: %d\n", score);
    printf("Thanks for playing Retro Space Adventure!\n\n");
}

int playGame(int level) {
    int shipHP = SHIP_HP;
    int alienHP = ALIEN_HP;
    int damageDealt, damageTaken;
    printf("Get ready for battle!\n");
    for(int i = 1; i <= 3; i++) {
        printf("ROUND %d\n", i);
        // player attacks
        damageDealt = rand() % 4 + level; // calculate damage dealt based on level
        printf("You attack the alien and deal %d damage.\n", damageDealt);
        alienHP -= damageDealt;
        if(alienHP <= 0) { // alien destroyed
            printf("The alien is destroyed!\n");
            return level * 10; // return reward for level
        }
        // alien attacks
        damageTaken = rand() % 3 + 1; // calculate damage taken
        printf("The alien attacks you and deals %d damage.\n", damageTaken);
        shipHP -= damageTaken;
        if(shipHP <= 0) { // game over
            printf("Your ship has been destroyed! GAME OVER\n");
            exit(0);
        }
        printf("Your ship has %d HP remaining.\n", shipHP);
    }
    printf("You successfully completed round 3!\n");
    return level * 5; // return reward for completing level
}