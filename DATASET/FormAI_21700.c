//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");

    srand(time(NULL));

    int militaryStrength = rand() % 101;
    int technologicalAdvancement = rand() % 101;
    int globalUnity = rand() % 101;

    int totalScore = militaryStrength + technologicalAdvancement + globalUnity;
    int invasionProbability = (totalScore / 3);

    printf("\nMILITARY STRENGTH: %d\n", militaryStrength);
    printf("TECHNOLOGICAL ADVANCEMENT: %d\n", technologicalAdvancement);
    printf("GLOBAL UNITY: %d\n\n", globalUnity);

    printf("TOTAL SCORE: %d\n", totalScore);
    printf("INVASION PROBABILITY: %d%%\n", invasionProbability);

    if (invasionProbability < 25) {
        printf("\nThe probability of an alien invasion is low.\n");
    }
    else if (invasionProbability >= 25 && invasionProbability < 50) {
        printf("\nThere is a moderate probability of an alien invasion.\n");
    }
    else if (invasionProbability >= 50 && invasionProbability < 75) {
        printf("\nThere is a high probability of an alien invasion.\n");
    }
    else {
        printf("\nThe probability of an alien invasion is extremely high.\n");
    }

    return 0;
}