//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>   //for printf, scanf
#include <stdlib.h>  //for srand, rand
#include <time.h>    //for time

int main() {
    srand(time(0));    //to get different random numbers each time program runs

    printf("Welcome to the Paranoid Adventure Game!\n\n");

    int playerHealth = 100;
    int enemyHealth = rand() % 100 + 1;    //enemy's health is between 1 to 100

    printf("You are starting with 100 health.\n");
    printf("An enemy appears with %d health.\n\n", enemyHealth);

    while (1) {    //infinite loop until either player or enemy dies
        int playerAttack = rand() % 20 + 1;    //player's attack power is between 1 to 20
        int enemyAttack = rand() % 30 + 1;     //enemy's attack power is between 1 to 30

        printf("Your turn:\n");
        printf("Press enter to attack the enemy...");
        getchar();    //pause until enter is pressed
        printf("You hit the enemy with %d damage.\n", playerAttack);
        enemyHealth -= playerAttack;    //subtract player's attack power from enemy's health
        if (enemyHealth <= 0) {    //if enemy's health reaches or goes below zero
            printf("The enemy is dead.\n");
            printf("Congratulations! You have won the game.\n");
            break;    //break the loop, game ended
        }
        printf("Enemy's turn:\n");
        printf("The enemy attacked you with %d damage.\n", enemyAttack);
        playerHealth -= enemyAttack;    //subtract enemy's attack power from player's health
        if (playerHealth <= 0) {    //if player's health reaches or goes below zero
            printf("You are dead.\n");
            printf("Game over! Better luck next time.\n");
            break;    //break the loop, game ended
        }
        printf("Your health: %d\n", playerHealth);
        printf("Enemy's health: %d\n\n", enemyHealth);
    }
    return 0;
}