//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int num_of_planets, num_of_years;
  int invasion_odds;
  
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("How many planets are in the known universe? ");
  scanf("%d", &num_of_planets);
  printf("How many years into the future would you like to calculate? ");
  scanf("%d", &num_of_years);

  srand(time(NULL)); // Seed random number generator
  
  for (int i = 1; i <= num_of_years; i++) {
    invasion_odds = rand() % num_of_planets; // Generate invasion probability between 0 and num_of_planets
    printf("Year %d: Probability of alien invasion is %d out of %d.\n", i, invasion_odds, num_of_planets);
  }

  printf("\nThank you for using the Alien Invasion Probability Calculator!");
  
  return 0;
}