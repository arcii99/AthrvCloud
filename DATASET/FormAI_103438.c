//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); // seed for the random number generator

    int earthDefenders = rand()%1000000+1; // generate a random number for the number of earth defenders
    int alienShips = rand()%5000+1; // generate a random number for the number of alien ships

    float earthStrength = 567.89; // assigned earth strength
    float alienStrength = 1234.56; // assigned alien strength

    float earthProb = (earthDefenders*earthStrength)/(alienShips*alienStrength); //calculate earth probability
    float alienProb = 1-earthProb; //calculate alien probability

    printf("ALERT! Alien Invasion Probability Calculator Activated!\n");
    printf("Calculating probability of Earth's chance of survival...\n\n");

    printf("Number of Earth Defenders : %d\n",earthDefenders);
    printf("Estimated Alien Ships : %d\n\n",alienShips);

    printf("Assumed Earth Strength : %.2f\n",earthStrength);
    printf("Assumed Alien Strength : %.2f\n\n",alienStrength);

    printf("The Probability of Earth's chance of Survival is : %.2f %%\n",earthProb*100);
    printf("The Probability of an Alien Invasion is : %.2f %%\n",alienProb*100);

    printf("\n\nRECOMMENDED ACTION:\n");
    if(earthProb>0.5)
        printf("We have a good chance of survival. Suggest to prepare the defense.\n");
    else
        printf("ALERT! High chance of Alien Invasion! Suggest to evacuate the planet immediately!!\n");

    return 0;
}