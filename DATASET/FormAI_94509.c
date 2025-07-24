//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    int score = 0; // initialize score to 0
    int potion = 0; // initialize potion to 0
    int health = 10; // initialize health to 10
    int enemy_health = 5; // initialize enemy health to 5
    char input; // initialize user input character
    printf("Welcome to PARANOIA!\n");
    printf("You are an adventurer in a haunted castle, trying to reach the treasure.\n");
    printf("You have 10 health points, a sword and a potion.\n");
    printf("Enter 'w' to move forward, 'a' to attack, 'p' to use potion, 'q' to quit.\n");
    while (health > 0) {
        printf("Score: %d\nHealth: %d\nEnemy Health: %d\n", score, health, enemy_health);
        input = getchar(); // get user input
        switch (input) {
            case 'w': // move forward
                printf("You move forward and encounter an enemy.\n");
                break;
            case 'a': // attack enemy
                printf("You attack the enemy with your sword.\n");
                int damage = rand() % 3 + 1; // random damage between 1 and 3
                enemy_health -= damage; // reduce enemy health
                if (enemy_health <= 0) { // enemy defeated
                    printf("You defeated the enemy!\n");
                    score += 10; // increase score
                    enemy_health = 5; // reset enemy health
                    int treasure = rand() % 2; // 50% chance of treasure
                    if (treasure) {
                        printf("You find a treasure chest!\n");
                        score += 50; // increase score
                        potion++; // found a potion
                    }
                } else { // enemy still alive
                    printf("The enemy counterattacks!\n");
                    damage = rand() % 2 + 1; // random damage between 1 and 2
                    health -= damage; // reduce player health
                }
                break;
            case 'p': // use potion
                if (potion > 0) {
                    printf("You use a potion and restore 5 health points.\n");
                    health += 5; // increase health
                    potion--; // consume a potion
                } else {
                    printf("You don't have any potions left!\n");
                }
                break;
            case 'q': // quit game
                printf("Quitting game...\n");
                return 0;
            default: // invalid input
                printf("Invalid input!\n");
                break;
        }
    }
    printf("Game over!\nYour final score is: %d\n", score); // game over
    return 0;
}