//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator with current time
  
  char* subjects[] = {"The government", "Aliens", "The illuminati", "Big Pharma", "The lizard people", "The deep state"};
  char* verbs[] = {"is controlling", "is secretly plotting", "has created", "is manipulating", "is covering up", "is brainwashing"};
  char* objects[] = {"the media", "the weather", "our minds", "the stock market", "the election", "the food supply"};

  printf("Welcome to the Random Conspiracy Theory Generator!\n");
  printf("Press enter to generate a new conspiracy theory or type 'q' to quit:");

  char input;
  while ((input = getchar()) != 'q') {
    printf("Did you know that %s %s %s?\n", subjects[rand() % 6], verbs[rand() % 6], objects[rand() % 6]);
    printf("Press enter to generate a new conspiracy theory or type 'q' to quit:");
    while (getchar() != '\n'); // ignore any other input until enter key is pressed
  }
  return 0;
}