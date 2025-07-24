//FormAI DATASET v1.0 Category: Random ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator

  int i;
  printf("Your random numbers are:\n");
  for (i = 1; i <= 10; i++) {
    printf("%d\n", rand());
  }

  printf("\nNow let's get a random value between 1 and 100...\n");
  int randomValue = rand() % 100 + 1;
  printf("Your random value is: %d\n", randomValue);

  printf("\nBut wait, there's more!\n");
  printf("Let's create an array of random integers...\n");

  int myArray[10];
  for (i = 0; i < 10; i++) {
    myArray[i] = rand() % 50 + 1;
  }

  printf("\nHere's your array:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", myArray[i]);
  }

  printf("\n\nThanks for playing with random numbers in C!\n");
  return 0;
}