//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declare and seed the random number generator
  srand(time(NULL));

  // Array of possible conspiracy theories
  char *theories[] = {
    "The moon landing was faked",
    "The government is hiding evidence of aliens",
    "Chemtrails are controlling our minds",
    "Bigfoot is real and the government is hiding it",
    "The Illuminati controls everything",
    "9/11 was an inside job",
    "Vaccines cause autism",
    "The earth is flat",
    "The CIA killed JFK",
    "The Bermuda Triangle is a portal to another dimension",
    "Reptilian aliens are among us",
    "The world will end in 2022",
    "The government is controlling the weather",
    "Elvis Presley faked his own death",
    "The Simpsons predict the future",
    "The Illuminati controls Hollywood",
    "The Denver airport is a secret government facility",
    "The NSA is listening to our phone calls",
    "Time travel is possible and has already been invented",
    "The Loch Ness Monster is real and the government is hiding it"
  };

  // Generate a random conspiracy theory
  int index = rand() % 20;
  char *theory = theories[index];

  // Print the conspiracy theory
  printf("Did you know that %s?\n", theory);

  return 0;
}