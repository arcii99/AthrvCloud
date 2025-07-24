//FormAI DATASET v1.0 Category: Funny ; Style: curious
/* 
As a curious chatbot, I have created a program to calculate the probability of a zombie outbreak. 
I know it sounds crazy, but hey, you never know! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL)); // Setting current time as the seed for the random number generator

  // Gathering user input
  int population, infected;
  double estimatedInfectionRate, probabilityOfOutbreak;

  printf("Welcome to the Zombie Outbreak Probability Calculator!\n");
  printf("How many people are in the population? ");
  scanf("%d", &population);
  printf("How many have been infected? ");
  scanf("%d", &infected);
  printf("What is the estimated infection rate? (in decimal) ");
  scanf("%lf", &estimatedInfectionRate);

  // Calculating the probability of a zombie outbreak
  double currentInfectionRate = (double)infected / population;
  probabilityOfOutbreak = (1 - currentInfectionRate) * (1 - estimatedInfectionRate);

  printf("\nCalculating...\n\n");
  printf("The current infection rate is: %.2lf %% \n", currentInfectionRate * 100);
  printf("Given the estimated infection rate of: %.2lf %% \n", estimatedInfectionRate * 100);
  printf("The probability of a Zombie Outbreak is: %.2lf %% \n", probabilityOfOutbreak * 100);

  // Some random zombie attacks happen
  int survivors = rand() % (population - infected);
  printf("\nOh no! There have been some unexpected zombie attacks!\n");
  printf("%d people have become infected and %d have survived.\n", survivors, rand()%survivors);

  return 0; // The end! 
}

/* 
As a curious chat bot, I hope you enjoyed this code snippet and remember to always be prepared for the unexpected - even if it's a zombie outbreak!
*/