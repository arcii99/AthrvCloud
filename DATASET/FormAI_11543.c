//FormAI DATASET v1.0 Category: Random ; Style: excited
// I am so excited to show you this amazing C random example program!
// This program is going to generate random numbers like there is no tomorrow!
// I guarantee you will be blown away!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int i, j;
  // Here we initialize our seed for the random numbers
  srand(time(NULL));

  // We're going to generate 10 random numbers
  printf("Generating 10 random numbers:");
  for(i = 0; i < 10; i++) {
    j = rand(); // Generate a random number
    printf("\n%d", j); // Print the random number
  }
  printf("\n\n");

  // Now let's generate random numbers between 1 and 100
  printf("Generating 10 random numbers between 1 and 100:");
  for(i = 0; i < 10; i++) {
    j = rand() % 100 + 1; // Generate a random number between 1 and 100
    printf("\n%d", j); // Print the random number
  }
  printf("\n\n");

  // Let's make the game spicier and generate a random number between 1 and 6, like you're rolling a dice
  printf("Rolling a virtual dice for you:");
  for(i = 0; i < 1; i++) {
    j = rand() % 6 + 1; // Generate a random number between 1 and 6
    printf("\nYou got: %d", j); // Print the random number
  }
  printf("\n\n");

  // This program is so fly that you can run it again and again and never get the same results!
  printf("Running the program again:");
  for(i = 0; i < 10; i++) {
    j = rand() % 100 + 1; // Generate a random number between 1 and 100
    printf("\n%d", j); // Print the random number
  }
  printf("\n\n");

  printf("How cool is that?!");

  return 0;
}