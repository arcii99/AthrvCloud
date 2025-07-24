//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int main()
{
    srand(time(NULL));  // to generate random values

    int invasionProbability = rand() % 100;
    int aliens = rand() % 10000;
    float invasionPower = (float)rand() / (float)RAND_MAX;   // to generate values between 0 and 1

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("Calculating the probability of an alien invasion...\n");
    printf("The probability is %d%%.\n\n", invasionProbability);

    printf("Calculating the number of aliens involved...\n");
    printf("The number of aliens is %d.\n\n", aliens);

    printf("Calculating the power of the invasion...\n");
    printf("The invasion power is %f.\n\n", invasionPower);

    printf("Based on these calculations, it is highly recommended to take action immediately!\n");
    printf("Please inform the nearest military base and evacuate the area immediately!\n");

    return 0;
}