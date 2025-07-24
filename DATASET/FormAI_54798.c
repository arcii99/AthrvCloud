//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,prob;
    int max_prob = 0;
    int max_prob_i = 0, max_prob_j = 0;
    int invasion_prob[10][10];

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");

    srand(time(0));

    //Generate random probability values for each location
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            prob = rand() % 101;
            invasion_prob[i][j] = prob;
            printf("%d ", invasion_prob[i][j]);
        }
        printf("\n");
    }

    //Calculate maximum probability and its location
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(invasion_prob[i][j] > max_prob)
            {
                max_prob = invasion_prob[i][j];
                max_prob_i = i;
                max_prob_j = j;
            }
        }
    }

    printf("\nMaximum Invasion Probability: %d at location (%d,%d)\n", max_prob, max_prob_i, max_prob_j);
    printf("ATTENTION: ALIEN INVASION IMMINENT AT (%d,%d)\n", max_prob_i, max_prob_j);

    return 0;
}