//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length for a conspiracy theory
#define MAX_LENGTH 200

// Define a list of possible conspiracy theories
char* conspiracy_theories[] = {
  "The moon landing was faked",
  "Chemtrails are a government conspiracy",
  "9/11 was an inside job",
  "The Earth is flat",
  "The Illuminati controls the world",
  "Aliens have already made contact with us",
  "The government is hiding the cure for cancer",
  "Vaccines cause autism",
  "The government is spying on us through our electronic devices",
  "The Titanic never sank"
};
// Define the length of the list of conspiracy theories
int num_conspiracy_theories = sizeof(conspiracy_theories) / sizeof(char*);

// Define the maximum recursion depth
#define MAX_DEPTH 5

// Function to generate a random conspiracy theory
void generate_conspiracy_theory(int depth) {
  // Randomly select a conspiracy theory from the list
  int index = rand() % num_conspiracy_theories;
  char* theory = conspiracy_theories[index];

  // Check if we have exceeded the maximum depth of recursion
  if (depth >= MAX_DEPTH) {
    printf("%s...\n", theory);
  } else {
    // Generate a new conspiracy theory to append to the existing one
    char new_theory[MAX_LENGTH];
    sprintf(new_theory, "%s, %s", theory, theory);
    printf("%s\n", new_theory);
    
    // Recursively generate a new conspiracy theory with a deeper depth
    generate_conspiracy_theory(depth + 1);
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random conspiracy theory
  generate_conspiracy_theory(0);

  return 0;
}