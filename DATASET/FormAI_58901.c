//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator with time
  int alien_attack_probability;
  int weapons_strength;
  int planetary_defense;
  int number_of_defenders;
  int alien_fleet_size;
  int defense_budget;
  int alien_technology_level;
  int victory_probability;
  
  // generate random input values
  alien_attack_probability = rand() % 101; // generates a number between 0-100
  weapons_strength = rand() % 11; // generates a number between 0-10
  planetary_defense = rand() % 11; // generates a number between 0-10
  number_of_defenders = rand() % 10001; // generates a number between 0-10000
  alien_fleet_size = rand() % 100001; // generates a number between 0-100000
  defense_budget = rand() % 10000001; // generates a number between 0-10000000
  alien_technology_level = rand() % 11; // generates a number between 0-10
  
  // calculate probability of victory
  victory_probability = ((weapons_strength * planetary_defense) + (number_of_defenders * defense_budget)) / (alien_fleet_size * (10 - alien_attack_probability) * (10 - alien_technology_level));
  
  // output results
  printf("Alien Attack Probability: %d\n", alien_attack_probability);
  printf("Weapons Strength: %d\n", weapons_strength);
  printf("Planetary Defense: %d\n", planetary_defense);
  printf("Number of Defenders: %d\n", number_of_defenders);
  printf("Alien Fleet Size: %d\n", alien_fleet_size);
  printf("Defense Budget: %d\n", defense_budget);
  printf("Alien Technology Level: %d\n", alien_technology_level);
  printf("Victory Probability: %d%%\n", victory_probability);
  
  return 0;
}