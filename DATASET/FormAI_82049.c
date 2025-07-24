//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int shipHealth = 100;
  int alienHealth = 100;
  printf("Welcome to the Space Adventure!\n");
  printf("Your ship's health: %d\n", shipHealth);

  while (shipHealth > 0 && alienHealth > 0) {
    int shipAttack = rand() % 20;
    int alienAttack = rand() % 30;
    printf("\nAlien's health: %d\n", alienHealth);
    printf("Your ship attacks the alien for %d damage!\n", shipAttack);
    alienHealth -= shipAttack;
    if (alienHealth <= 0) {
      printf("You've defeated the alien and saved the universe!\n");
      break;
    }
    printf("The alien attacks your ship for %d damage!\n", alienAttack);
    shipHealth -= alienAttack;
    if (shipHealth <= 0) {
      printf("Your ship has been destroyed. Game over.\n");
      break;
    }
    printf("Your ship's health: %d\n", shipHealth);
  }
  return 0;
}