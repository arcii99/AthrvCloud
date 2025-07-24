//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random number generator

  printf("Welcome to the Funny System Administrator!\n");
  printf("Let's play a game:\n");
  printf("How many times should I press delete on the root directory?\n");
  int num_deletes = rand() % 1000000 + 1; // generate a random number of deletes between 1 and 1,000,000
  printf("I'm feeling lucky, let's go for %d deletes.\n", num_deletes);

  printf("Deleting... ");
  for (int i = 0; i < num_deletes; i++) {
    printf("%d ", i);
    // simulate deleting files by generating random numbers and throwing them away
    unsigned char trash_data[1024]; // a buffer for some trash data
    for (int j = 0; j < 1024; j++) {
      trash_data[j] = rand() % 256; // generate random byte
    }
  }
  printf("\nDone deleting! Hope you made a backup!\n");

  // now let's generate a random password for the root user
  printf("\nNow let's change the root password...\n");
  printf("Here's your new password: ");
  for (int i = 0; i < 12; i++) {
    printf("%c", (rand() % 94) + 33); // generate random ASCII character between ! and ~
  }
  printf("\nDon't worry, I wrote it down on a sticky note for you!\n");

  return 0;
}