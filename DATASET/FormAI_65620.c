//FormAI DATASET v1.0 Category: Random ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Happiness Randomizer!\n");
  printf("This program will bring some joy into your life by generating a random happy intention.\n");

  srand(time(NULL)); //seed the random number generator with the current time

  char *intentions[10] = { //an array of 10 happy intentions
    "Smile at a stranger today!",
    "Compliment someone on their outfit.",
    "Tell a loved one how much you appreciate them.",
    "Do a good deed for a friend or neighbor.",
    "Spend some time in nature.",
    "Dance to your favorite song.",
    "Try a new hobby.",
    "Take a warm bath and relax.",
    "Try a new restaurant or recipe.",
    "Watch a funny movie or TV show."
  };

  int index = rand() % 10; //generate a random number between 0 and 9

  printf("Your happy intention for today is: %s\n", intentions[index]);

  return 0;
}