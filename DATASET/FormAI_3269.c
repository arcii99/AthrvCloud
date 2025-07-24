//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>

float fuel_level = 100.0;
int shield_level = 100;
int enemy_health = 50;

void increase_shield(int x) {
  shield_level += x;
  printf("Shield level increased by %d. Current shield level: %d\n", x, shield_level);
}

void refuel(float x) {
  fuel_level += x;
  printf("Fuel level increased by %.1f. Current fuel level: %.1f\n", x, fuel_level);
}

void attack() {
  enemy_health -= 25;
  printf("Enemy health reduced by 25. Current health: %d\n", enemy_health);
}

int main() {
  printf("Welcome to Procedural Space Adventure!\n\n");
  printf("Your fuel level: %.1f\n", fuel_level);
  printf("Your shield level: %d\n", shield_level);
  printf("Enemy health: %d\n\n", enemy_health);

  refuel(20.5);
  increase_shield(50);
  attack();

  printf("\nEnd of game. Final stats:\n");
  printf("Fuel level: %.1f\n", fuel_level);
  printf("Shield level: %d\n", shield_level);
  printf("Enemy health: %d\n", enemy_health);

  return 0;
}