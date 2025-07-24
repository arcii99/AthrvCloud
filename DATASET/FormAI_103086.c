//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int year;
  float probability;
  
  // Seed random number generator
  srand(time(NULL));
  
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
  
  // Gather input from user
  printf("Enter the current year: ");
  scanf("%d", &year);
  
  // Calculate probability of alien invasion
  probability = rand() % 101;
  
  // Display results
  printf("\nResults:\n");
  
  if (probability == 0) {
    printf("Wow. The probability of an alien invasion in the year %d is exactly 0%%!\n", year);
  } else if (probability <= 10) {
    printf("The chance of an alien invasion in the year %d is very low, at only %0.2f%%.\n", year, probability);
  } else if (probability <= 30) {
    printf("There is a moderate chance of an alien invasion in the year %d, with a probability of %0.2f%%.\n", year, probability);
  } else if (probability <= 50) {
    printf("The probability of an alien invasion in the year %d is fairly high, at %0.2f%%.\n", year, probability);
  } else if (probability <= 70) {
    printf("There is a strong chance of an alien invasion in the year %d, with a probability of %0.2f%%.\n", year, probability);
  } else if (probability <= 90) {
    printf("The probability of an alien invasion in the year %d is very high, at %0.2f%%!\n", year, probability);
  } else {
    printf("Oh no! The probability of an alien invasion in the year %d is a whopping %0.2f%%! Take precautions now!\n", year, probability);
  }
  
  return 0;
}