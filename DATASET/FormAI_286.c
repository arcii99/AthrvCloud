//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Set up variables
   int playerHealth = 100;
   int enemyHealth = 100; 
   int playerAttack;
   int enemyAttack;

   // Set up randomizer seed
   srand(time(NULL));

   printf("Welcome to Real-Life Adventure! You will go on a quest to defeat the Evil Enemy and save the town.\n");

   while (playerHealth > 0 && enemyHealth > 0) {
       // Get player attack input
       printf("\nIt's your turn to attack! Enter a number between 1 and 10: ");
       scanf("%d", &playerAttack);

       // Calculate enemy's attack
       enemyAttack = rand() % 10 + 1;

       // Remove health from enemy
       enemyHealth -= playerAttack;

       // Check if enemy is still alive
       if (enemyHealth <= 0) {
           printf("Congratulations! You have defeated the Evil Enemy and saved the town!");
           break;
       }

       // Remove health from player
       playerHealth -= enemyAttack;

       // Check if player is still alive
       if (playerHealth <= 0) {
           printf("Game Over! You have been defeated by the Evil Enemy :(");
           break;
       }

       printf("\nYour health: %d | Enemy health: %d", playerHealth, enemyHealth);
   }

   return 0;
}