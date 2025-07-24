//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Create random number generator
    srand(time(NULL));

    // Declare arrays for conspiracy theories and nouns
    char* conspiracy_theories[] = {"The moon landing was faked by the government", 
                                   "9/11 was an inside job orchestrated by the CIA",
                                   "Fluoride in the water is a mind control experiment",
                                   "The Illuminati control the world's governments",
                                   "COVID-19 was created in a lab as a bioweapon"};
    char* nouns[] = {"aliens", "vaccines", "chemtrails", "Big Pharma", "the government"};

    // Generate random conspiracy theory and noun
    int rand_theory = rand() % 5;
    int rand_noun = rand() % 5;

    // Print out conspiracy theory with noun
    printf("Did you know that %s are actually controlled by %s? It's true!\n", 
           conspiracy_theories[rand_theory], nouns[rand_noun]);

    return 0;
}