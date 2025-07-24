//FormAI DATASET v1.0 Category: Random ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to the Brave C Random Example Program!\n");
  printf("This program generates random integers between 1-100\n\n");

  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate 10 random numbers
  int i;
  for (i = 0; i < 10; i++) {
    int random_num = rand() % 100 + 1;
    printf("Random number %d: %d\n", i + 1, random_num);
  }

  printf("\nThanks for using the Brave C Random Example Program!\n");
  return 0;
}