//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  int shipHealth = 100;
  int alienHealth = 100;
  
  printf("Welcome to the Procedural Space Adventure!\n");
  printf("Your ship has been attacked by an alien spaceship.\n");
  printf("You need to defeat the alien to stay alive.\n");
  
  while (shipHealth > 0 && alienHealth > 0) {
    int shipAttack = rand() % 10 + 1;
    int alienAttack = rand() % 10 + 1;
    
    printf("Your ship health: %d\n", shipHealth);
    printf("Alien ship health: %d\n", alienHealth);
    
    // Player's attack
    printf("You attack the alien and deal %d damage.\n", shipAttack);
    alienHealth -= shipAttack;
    
    if (alienHealth <= 0) {
      printf("Congratulations, you defeated the alien and survived the attack!\n");
      break;
    }
    
    // Alien's attack
    printf("The alien attacks your ship and deals %d damage.\n", alienAttack);
    shipHealth -= alienAttack;
    
    if (shipHealth <= 0) {
      printf("Your ship has been destroyed by the alien. Game Over.\n");
      break;
    }
  }
  
  printf("Thanks for playing the Procedural Space Adventure!\n");
  
  return 0;
}