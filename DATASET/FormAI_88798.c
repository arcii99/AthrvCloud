//FormAI DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize the random number generator
  
  int x = 0, y = 0; // initial position of the robot
  int min_val = -5, max_val = 5; // range of movement
  
  printf("Starting position: (%d, %d)\n\n", x, y);
  
  for (int i = 0; i < 50; i++) { // perform 50 steps
    int random_x = rand() % (max_val - min_val + 1) + min_val; // generate a random horizontal movement
    int random_y = rand() % (max_val - min_val + 1) + min_val; // generate a random vertical movement
    
    x += random_x; // update horizontal position
    y += random_y; // update vertical position
    
    printf("Step %d: Moved to position (%d, %d)\n", i+1, x, y);
  }
  
  printf("\nFinal position: (%d, %d)\n", x, y);
  
  return 0;
}