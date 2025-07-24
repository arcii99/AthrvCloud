//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int humans, aliens;
    float invasion_prob;

    srand(time(0)); //seeding the random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of humans in the area: ");
    scanf("%d", &humans);

    aliens = rand() % (humans + 1); //generating a random number of aliens between 0 and the number of humans in the area

    if(aliens == 0)
    {
        printf("There are no aliens in the area. Phew, that was close!\n");
    }
    else
    {
        invasion_prob = ((float)aliens / humans) * 100; //calculating the invasion probability as a percentage
        printf("Uh oh, looks like there are %d aliens in the area.\n", aliens);
        printf("The probability of an alien invasion is: %.2f%%\n", invasion_prob);
    }

    return 0;
}