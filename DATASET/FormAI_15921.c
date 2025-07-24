//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {"The Government", "Aliens", "The Illuminati", "Big Pharma", "The Freemasons", "The New World Order", "The Reptilian Elite", "The Deep State", "The Vatican"};
char *verbs[] = {"is controlling", "is manipulating", "is experimenting on", "is brainwashing", "is hiding information about", "is responsible for", "is secretly funding", "is behind the scenes of", "is covering up"};
char *objects[] = {"our minds and thoughts", "the weather", "the stock market", "the media", "the internet", "our health", "the education system", "the energy industry", "the food industry"};

void generateConspiracyTheory()
{
    srand(time(0));
    int subjectIndex = rand() % 9;
    int verbIndex = rand() % 9;
    int objectIndex = rand() % 9;

    printf("%s %s %s.\n", subjects[subjectIndex], verbs[verbIndex], objects[objectIndex]);
}

int main()
{
    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    char choice = 'y';
    while (choice == 'y')
    {
        generateConspiracyTheory();
        printf("Do you want to generate another conspiracy theory? (y/n) ");
        scanf(" %c", &choice);
    }

    printf("Thanks for using the Random Conspiracy Theory Generator!\n");

    return 0;
}