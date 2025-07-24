//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int invasionProbability = 0;
    int romanticFactor = 0;
    srand(time(NULL));
  
    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Enter your Romantic factor (1-10): ");
    scanf("%d", &romanticFactor);
  
    if (romanticFactor <= 0 || romanticFactor > 10) 
    {
        printf("Oops! Invalid Romantic Factor.\n");
        return 1;
    }
  
    invasionProbability = rand() % (11 - romanticFactor);
  
    if (invasionProbability < 5)
    {
        printf("Congratulations! Your romantic factor of %d has managed to keep the aliens at bay.\n", romanticFactor);
    }
    else
    {
        printf("Oh no! The aliens have invaded. Your romantic factor of %d was not strong enough to prevent the invasion.\n", romanticFactor);
    }
  
    return 0;
}