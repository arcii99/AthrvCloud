//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>  //for input/output operations
#include <stdlib.h>  //for random number generator
#include <time.h>   //for accessing time function

int main()
{
    int choice, health = 100, enemy_health = 100;  
    srand(time(0));   //for seed value for random number generation
    printf("Welcome to the Adventure Game!\nYou are on a quest to find the mystical treasure hidden in the cave.\n");
    printf("You enter the cave and encounter a monster. Ready to fight? \n1. Yes 2. No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The fight begins!\n");
        while (health > 0 && enemy_health > 0) {
            int damage = rand() % 10 + 1;  //damage dealt by player
            int enemy_damage = rand() % 10 + 1;  //damage dealt by enemy
            printf("You dealt %d damage to the monster!\n", damage);
            enemy_health -= damage;
            printf("The monster dealt %d damage to you!\n", enemy_damage);
            health -= enemy_damage;
            printf("Health: %d  Monster Health: %d\n", health, enemy_health);
        }
        if (health <= 0) {
            printf("You died! Game Over!\n");
        }
        else {
            printf("You have defeated the monster! Continue on your quest.\n");
            printf("You come across two paths. Which do you choose? \n1. Right 2. Left\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You continue down the path and come across a treasure chest! You found the mystical treasure!\nCongratulations! You have completed the adventure game!\n");
            }
            else {
                printf("You continue down the path and come across a dead end. Looks like you chose the wrong path. Game Over!\n");
            }
        }
    }
    else if (choice == 2) {
        printf("You decided to back down and return home. Maybe another day you can attempt the quest.\n");
    }
    else {
        printf("Invalid choice. Try again.\n");
    }
    return 0; //indicates the program has ended successfully
}