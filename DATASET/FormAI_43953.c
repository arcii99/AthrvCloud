//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int probability;
   srand(time(NULL));
   probability = rand() % 101;
   printf("The probability of an alien invasion today is: %d%%\n", probability);
   return 0;
}