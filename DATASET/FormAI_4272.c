//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int probability;
  char choice;
  srand(time(NULL)); // seeding the random number generator with current time
  
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Do you want to know the probability of alien invasion? [y/n]: ");
  scanf(" %c", &choice);
  
  if (choice == 'y' || choice == 'Y') {
    probability = rand() % 101; // generating a random number between 0 and 100
    printf("The probability of alien invasion is %d%%\n", probability);
  } else if (choice == 'n' || choice == 'N') {
    printf("Okay, bye!\n");
  } else {
    printf("Invalid input. Please try again.\n");
  }
  
  return 0;
}