//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Initialize random number generator
  srand(time(NULL));

  // Define arrays of conspiracy theories
  char *consp1[] = {"The Moon landings were faked by the government.", 
                    "The world is run by reptilian overlords.", 
                    "Global warming is a hoax created by the Chinese."};
  char *consp2[] = {"Aliens built the pyramids.",
                    "The Illuminati control all major world events.",
                    "Chemtrails are used to control the population."};
  char *consp3[] = {"The government is hiding the cure for cancer.",
                    "9/11 was an inside job.",
                    "The earth is flat."};

  // Generate random conspiracy theory generator
  int rand1 = rand() % 3; // generate random number between 0 and 2
  int rand2 = rand() % 3;
  int rand3 = rand() % 3;

  // Print out the conspiracy theory
  printf("Here is your random conspiracy theory:\n");
  printf("%s %s %s\n", consp1[rand1], consp2[rand2], consp3[rand3]);

  return 0;
}