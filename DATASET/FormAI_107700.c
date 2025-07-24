//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed for random number generator
  int rand_num = rand() % 4; // Generate random number between 0 and 3
  printf("Here's your random conspiracy theory:\n");

  switch(rand_num) {
    case 0:
      printf("The moon landing was faked.\n");
      break;

    case 1:
      printf("The government is hiding the existence of aliens.\n");
      break;

    case 2:
      printf("The Earth is flat and the government is covering it up.\n");
      break;

    default:
      printf("The Illuminati control the world.\n");
      break;
  }

  return 0;
}