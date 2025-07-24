//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // initialize random seed

  int aliens = 0;
  float dist = 0;
  int time = 0;
  float prob = 0;

  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  printf("Enter the number of aliens: ");
  scanf("%d", &aliens);

  printf("Enter the distance between the alien spaceship and earth in light years: ");
  scanf("%f", &dist);

  printf("Enter the time it will take the aliens to travel to earth in years: ");
  scanf("%d", &time);

  float speed = dist / time;
  printf("\nThe aliens are traveling at a speed of %.2f light years per year.\n\n", speed);

  if (speed > 0.1) {
    prob = (float)aliens / (speed * (float)time);
  }
  else {
    printf("The aliens are traveling too slowly for an invasion to be probable.\n");
    return 0;
  }

  if (prob > 1) {
    prob = 1;
  }

  printf("The probability of an alien invasion is %.2f.\n", prob);

  if (prob > 0.5) {
    printf("Warning: The probability of an alien invasion is high!\n");
  }
  else {
    printf("The probability of an alien invasion is low.\n");
  }

  return 0;
}