//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); // seed for random number generator
    int playerHealth = 100, bossHealth = 200, damage; // initialization of player and boss health and damage variables
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are a space adventurer on a mission to defeat a boss to save the galaxy!\n");
    printf("You have 100 health points and the boss has 200 health points.\n");
    while(playerHealth > 0 && bossHealth > 0) {
        printf("\nYour current health: %d\n", playerHealth);
        printf("Boss's current health: %d\n", bossHealth);
        printf("Choose your next move:\n1. Attack\n2. Heal\n");
        int choice; // variable to store user's choice
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                damage = rand() % 30 + 10; // generate random damage between 10 and 30
                printf("You hit the boss with %d damage points!\n", damage);
                bossHealth -= damage;
                break;
            case 2:
                damage = rand() % 20 + 10; // generate random healing between 10 and 20
                printf("You healed yourself for %d health points!\n", damage);
                playerHealth += damage;
                break;
            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }
        damage = rand() % 40 + 20; // generate random damage between 20 and 40 for boss's turn
        printf("The boss hit you with %d damage points!\n", damage);
        playerHealth -= damage;
    }
    if(playerHealth <= 0) {
        printf("\nYou lost! The boss defeated you.\n");
    } else {
        printf("\nCongratulations! You defeated the boss and saved the galaxy!\n");
    }
    return 0;
}