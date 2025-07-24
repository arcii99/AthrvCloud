//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>

int main() {
  int health = 100;
  int shield = 50;
  int damage = 0;

  printf("Welcome space adventurer! You find yourself on a spaceship in the middle of the galaxy.\n");
  printf("You notice that your health is at %d and your shield is at %d.\n", health, shield);

  printf("Suddenly, you hear a loud noise coming from outside the spaceship!\n");
  printf("You rush to the control panel and see that your spaceship has been attacked by aliens!\n");

  while (health > 0) {
    damage = 10; // set damage to a random value between 1 and 20

    shield = shield - damage;
    if (shield < 0) {
      shield = 0;
      health = health + shield;
      printf("Your shield is no longer operational!\n");
    } else {
      printf("You were hit! Your shield is now at %d.\n", shield);
    }

    printf("Your health is now at %d.\n", health);

    if (health <= 0) {
      printf("Oh no! You've been defeated by the aliens!\n");
      break;
    }

    if (shield <= 0) {
      printf("Your shield has been depleted! You must repair it!\n");
      break;
    }

    printf("You fire your laser cannons at the aliens and...\n");
    printf("You hit them! Nice shot! You inflict %d damage!\n", damage);
    printf("The aliens are getting weaker!\n");
  }

  printf("Thanks for playing this silly space adventure game!\n");
  return 0;
}