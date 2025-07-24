//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // Set random seed based on current time

  // Define the genome sequence as a string
  char genome[] = "ATCG";

  // Generate a random genome sequence of length 50
  int i;
  for (i = 0; i < 50; i++) {
    printf("%c", genome[rand() % 4]); // Generate a random base and print it
  }
  printf("\n");

  // Simulate sequencing errors by randomly changing each base with a probability of 10%
  for (i = 0; i < 50; i++) {
    if (rand() % 10 == 0) { // 10% chance of an error
      char old_base = genome[rand() % 4];
      char new_base = genome[rand() % 4];
      while (new_base == old_base) { // Make sure the new base is different from the old one
        new_base = genome[rand() % 4];
      }
      printf("%c", new_base); // Print the error
    } else {
      printf("%c", genome[rand() % 4]); // Print the correct base
    }
  }
  printf("\n");

  return 0;
}