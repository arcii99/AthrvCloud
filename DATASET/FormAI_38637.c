//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Array of possible fortunes
  char *fortunes[] = {"A bright future awaits you.", 
                      "You will have a successful career.",
                      "A long-awaited opportunity will come your way.",
                      "Unexpected money will come to you.",
                      "A romantic relationship will flourish."};

  // Seed the random number generator with system time
  srand(time(NULL));

  // Generate a random index to select a fortune from the array
  int random_index = rand() % 5;

  // Print the fortune to the user
  printf("Your fortune for today is: %s\n", fortunes[random_index]);
  
  return 0;
}