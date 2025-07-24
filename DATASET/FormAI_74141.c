//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: high level of detail
// C Random Conspiracy Theory Generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Initialize random seed
  srand(time(NULL));
  
  // Array of conspiracy theories
  char theories[5][100] = {"The moon landing was faked by the government.", 
                           "Aliens are already living among us.", 
                           "The Illuminati is secretly controlling world events.", 
                           "The government is hiding the cure for cancer.", 
                           "Birds are actually drones controlled by the government."};
  
  // Generate random conspiracy theory and print
  int random_num = rand() % 5;
  printf("Did you know? ");
  printf(theories[random_num]);
  
  return 0;
}