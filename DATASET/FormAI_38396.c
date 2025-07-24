//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Array of conspiracy theories
  const char *theories[] = {
    "The moon landing was faked.",
    "Chemtrails are poisoning our air.",
    "The government is hiding evidence of alien life.",
    "The earth is flat.",
    "Bigfoot is real and the government is covering it up.",
    "The Illuminati controls world governments.",
    "The JFK assassination was an inside job.",
    "9/11 was an inside job.",
    "The government is using mind control on its citizens.",
    "Area 51 is hiding alien technology."
  };

  // Generate random index
  int index = rand() % 10;

  // Output conspiracy theory
  printf("Did you know:\n\n%s\n", theories[index]);

  return 0;
}