//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // random seed based on current time
    int alien_hp = 100; // alien's health points
    int spaceship_hp = 100; // spaceship's health points
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship on a mission to explore a distant planet.\n");
    printf("However, you have encountered an alien race who are hostile towards you.\n");
    printf("You must defeat the alien and continue your mission.\n");

    while (alien_hp > 0 && spaceship_hp > 0) { // battle loop
        int alien_attack = rand() % 20 + 1; // alien's attack damage
        printf("The alien attacks your spaceship! It does %d damage.\n", alien_attack);
        spaceship_hp -= alien_attack; // reduce spaceship's health
        if (spaceship_hp <= 0) { // check if spaceship explodes
            printf("Your spaceship explodes and you lose the game.\n");
            return 0;
        }
        int spaceship_attack = rand() % 20 + 1; // spaceship's attack damage
        printf("You fire your laser cannons at the alien! You do %d damage.\n", spaceship_attack);
        alien_hp -= spaceship_attack; // reduce alien's health
        if (alien_hp <= 0) { // check if alien is defeated
            printf("You have defeated the alien and continue your mission!\n");
            printf("You win!\n");
            return 0;
        }
        printf("Your spaceship has %d health points left.\n", spaceship_hp);
        printf("The alien has %d health points left.\n", alien_hp);
    }
    return 0;
}