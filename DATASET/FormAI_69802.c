//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *conspiracy_theories[] = { // Array of conspiracy theories
  "The government is hiding the cure for cancer", 
  "Aliens are real and the government is lying to us", 
  "The moon landing was faked", 
  "The Illuminati controls the world", 
  "9/11 was an inside job", 
  "Bigfoot is real and the government is covering it up", 
  "The Earth is flat", 
  "The Loch Ness Monster is a government experiment"
};

int main(void) {
  srand(time(NULL)); // Initialize random number generator

  printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

  while (1) {
    printf("Press enter to generate a new conspiracy theory, or 'q' to quit...\n");
    char input = getchar();
    if (input == 'q') break;
    getchar(); // Clear the newline from input buffer

    int index = rand() % sizeof(conspiracy_theories) / sizeof(conspiracy_theories[0]); // Generate random index from array
    printf("\n%s\n\n", conspiracy_theories[index]); // Print out randomly generated conspiracy theory
  }

  printf("Thanks for using the Random Conspiracy Theory Generator!\n");

  return 0;
}