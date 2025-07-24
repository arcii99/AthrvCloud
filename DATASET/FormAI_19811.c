//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void spaceship(int level);
void aliens(int level);
void battle(int level);
void endgame(int status);

int main() {
    int level = 1;
    srand(time(NULL)); // seed the random number generator
    
    printf("***Welcome to Procedural Space Adventure***\n");
    printf("You are a space adventurer on a quest to save the galaxy!\n");
    
    while(level <= 5) { // play levels 1-5
        spaceship(level);
        aliens(level);
        battle(level);
        level++;
    }
    
    endgame(1);
    return 0;
}

void spaceship(int level) {
    printf("\n-------LEVEL %d-------\n", level);
    printf("You are flying in your spaceship through the galaxy...\n");
    printf("Press ENTER to continue\n");
    getchar(); // wait for player to press enter
}

void aliens(int level) {
    int alien_count = rand() % level + 1; // number of aliens is random (between 1 and level)
    printf("You encounter %d hostile aliens!\n", alien_count);
}

void battle(int level) {
    int player_health = 100;
    int alien_health = rand() % (level * 20) + 10; // alien health is random and increases with level
    printf("A fierce battle ensues!\n");
    
    while(player_health > 0 && alien_health > 0) {
        // player attacks
        int player_damage = rand() % 10 + 1;
        printf("You attack the alien and cause %d damage!\n", player_damage);
        alien_health -= player_damage;
        if(alien_health <= 0) {
            printf("You defeated the alien!\n");
            break;
        }
        
        // alien attacks
        int alien_damage = rand() % (level * 5) + 1;
        printf("The alien attacks and causes %d damage!\n", alien_damage);
        player_health -= alien_damage;
        if(player_health <= 0) {
            break;
        }
    }
    
    if(player_health > 0) {
        printf("You emerge victorious from the battle!\n");
    } else {
        printf("You have been defeated...\n");
        endgame(0);
    }
}

void endgame(int status) {
    if(status == 1) {
        printf("\n***CONGRATULATIONS! YOU SAVED THE GALAXY!***\n");
    } else {
        printf("\n***GAME OVER - BETTER LUCK NEXT TIME***\n");
    }
}