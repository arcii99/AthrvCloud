//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    char *subjects[] = {"The Government", "The Illuminati", "The Reptilians", "The Freemasons", "The Deep State"};
    char *actions[] = {"controls", "manipulates", "planned", "created", "invented"};
    char *objects[] = {"the moon landing", "9/11", "the coronavirus", "the Bermuda Triangle", "Bigfoot"};

    int numTheories = 10;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    for(int i = 0; i < numTheories; i++)
    {
        printf("Theory %d: %s %s %s.\n", i+1, subjects[rand() % 5], actions[rand() % 5], objects[rand() % 5]);
    }

    printf("Do not believe everything you read on the internet. Stay critical!\n");

    return 0;
}