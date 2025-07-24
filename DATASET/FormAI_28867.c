//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); //initializing random seed using current time

    int alien_fleet_size, invasion_prob;

    printf("Enter the estimated size of the Alien Fleet (in numbers): ");
    scanf("%d", &alien_fleet_size);

    //using a probabilistic model to calculate the probability of an alien invasion
    invasion_prob = (int) ((float)rand() / RAND_MAX * 100); 

    printf("The probability of an Alien Invasion is %d%%\n", invasion_prob);

    if (invasion_prob > 80) //if invasion probability is greater than 80%
        printf("It is highly likely that the Alien Fleet will invade Earth!!\n");
    else if (invasion_prob > 50) //if invasion probability is greater than 50%
        printf("There is a moderate probability that the Alien Fleet might invade Earth.\n");
    else //if invasion probability is less than or equal to 50%
        printf("There is a low probability that the Alien Fleet will invade Earth. So, no need to panic!\n");

    return 0;
}