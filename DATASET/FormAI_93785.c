//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Introduction
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  // Gathering user input
  int n;
  printf("How many years into the future are we calculating? ");
  scanf("%d", &n);

  // Estimating the number of alien civilizations in space
  srand(time(NULL));
  int r = rand() % 1000 + 1;
  double k = 10 * n;
  double N = k * r;

  // Calculating the probability of an invasion
  double P = N / (pow(10, 15));

  // Displaying the results
  printf("\n\nAfter %d years, there are estimated to be %0.0f alien civilizations in space.\n", n, N);
  printf("The probability of an invasion in the next %d years is %0.2f%%.\n", n, P);

  // Farewell
  printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
  return 0;
}