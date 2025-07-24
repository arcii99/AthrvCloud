//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function prototypes
int randNum(int max);
void generateConspiracy();

int main()
{
    //Seed the random number generator
    srand(time(NULL));

    //Generate 5 random conspiracy theories
    for (int i = 1; i <= 5; i++)
    {
        printf("%d. ", i);
        generateConspiracy();
        printf("\n");
    }

    return 0;
}

//Function to generate a random number up to a specified maximum
int randNum(int max)
{
    return rand() % max;
}

//Function to generate a random conspiracy theory
void generateConspiracy()
{
    //Arrays for the different parts of the conspiracy theory
    char *places[] = {"the government", "the Illuminati", "NASA", "the pharmaceutical industry", "the media"};
    char *actions[] = {"is hiding", "is controlling", "is manipulating", "is suppressing", "is brainwashing"};
    char *targets[] = {"the truth about aliens", "the cure for cancer", "the shape of the Earth", "the dangers of vaccines", "the existence of Bigfoot"};

    //Generate random indexes for each array
    int placeIndex = randNum(5);
    int actionIndex = randNum(5);
    int targetIndex = randNum(5);

    //Print the conspiracy theory
    printf("The %s %s %s.", places[placeIndex], actions[actionIndex], targets[targetIndex]);
}