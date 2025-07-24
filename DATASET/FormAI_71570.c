//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>

int main() {
  // Declare variables
  int playerHealth = 100;
  int monsterHealth = 100;
  int playerDamage = 15;
  int monsterDamage = 20;
  int turn = 1;
  
  // Game loop
  while (playerHealth > 0 && monsterHealth > 0) {
    
    // Print turn number
    printf("Turn %d\n", turn);
    
    // Player attacks
    printf("Player attacks monster for %d damage\n", playerDamage);
    monsterHealth -= playerDamage;
    
    // Check if monster is defeated
    if (monsterHealth <= 0) {
      printf("Player wins!\n");
      break;
    }
    
    // Monster attacks
    printf("Monster attacks player for %d damage\n", monsterDamage);
    playerHealth -= monsterDamage;
    
    // Check if player is defeated
    if (playerHealth <= 0) {
      printf("Monster wins!\n");
      break;
    }
    
    // Print current health status
    printf("Player health: %d\n", playerHealth);
    printf("Monster health: %d\n", monsterHealth);
    
    // Increment turn number
    turn++;
  }
  
  return 0;
}