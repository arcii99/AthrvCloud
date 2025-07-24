//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alienProbability, invasion;
    srand(time(0));
  
    // Generate a random number between 0 and 100 to calculate alien invasion probability
    alienProbability = rand() % 101; 

    printf("Alien Invasion Probability Calculator\n\n");
    printf("Alien invasion probability is: %d%%\n", alienProbability);
  
    if (alienProbability >= 50) {
        invasion = 1;
        printf("\nThe probability of an alien invasion is high.\n");
    } else {
        invasion = 0;
        printf("\nThe probability of an alien invasion is low.\n");
    }

    printf("\n");

    return 0;
}