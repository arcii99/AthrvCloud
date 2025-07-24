//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* initialize variables */
    int governmentPreparedness, technologyAdvancement, militaryStrength, publicFear, spaceExploration;
    float invasionProbability;

    /* seed random number generator */
    srand(time(NULL));

    /* get input from user */
    printf("Please enter the level of government preparedness (0-10): ");
    scanf("%d", &governmentPreparedness);

    printf("Please enter the level of technology advancement (0-10): ");
    scanf("%d", &technologyAdvancement);
 
    printf("Please enter the level of military strength (0-10): ");
    scanf("%d", &militaryStrength);
 
    printf("Please enter the level of public fear (0-10): ");
    scanf("%d", &publicFear);
    
    printf("Please enter the level of space exploration (0-10): ");
    scanf("%d", &spaceExploration);

    /* calculate invasion probability */
    invasionProbability = ((float)governmentPreparedness + (float)technologyAdvancement +
                            (float)militaryStrength - (float)publicFear +
                            (float)spaceExploration) / 50;

    /* generate random number */
    float randomNum = (float)rand() / (float)RAND_MAX;

    /* compare random number to invasion probability */
    if (randomNum <= invasionProbability) {
        printf("\nALIEN INVASION IMMINENT! Probability of invasion: %.2f%%", invasionProbability * 100);
    } else {
        printf("\nPhew! No alien invasion in sight! Probability of invasion: %.2f%%", invasionProbability * 100);
    }

    return 0;
}