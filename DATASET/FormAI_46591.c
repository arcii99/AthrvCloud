//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>

// Define global variables
int fuel = 100;  // Initial fuel level
int shield = 50; // Initial shield level

// Define function to move the spaceship
void moveSpaceship(int distance) {
  if (fuel < distance) {
    printf("Not enough fuel to move spaceship.\n");
  } else {
    printf("Moving spaceship %d lightyears.\n", distance);
    fuel -= distance; // Subtract fuel used for movement
  }
}

// Define function to recharge shields
void rechargeShields() {
  if (shield < 50) {
    printf("Recharging shields.\n");
    shield = 50; // Set shields to maximum level
  } else {
    printf("Shields at maximum level. No recharge needed.\n");
  }
}

int main() {
  // Welcome message
  printf("Welcome to the Procedural Space Adventure!\n");
  
  // Initial status report
  printf("Fuel level: %d\n", fuel);
  printf("Shield level: %d\n", shield);
  
  // Move spaceship
  moveSpaceship(30);
  
  // Status report after movement
  printf("Fuel level: %d\n", fuel);
  printf("Shield level: %d\n", shield);
  
  // Recharge shields
  rechargeShields();
  
  // Status report after recharging shields
  printf("Fuel level: %d\n", fuel);
  printf("Shield level: %d\n", shield);
  
  return 0;
}