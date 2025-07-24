//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));  // seed the random generator with current time

    // arrays for random words/phrases
    char* industries[] = {"pharmaceutical", "energy", "tech", "food", "media", "finance"};
    int numIndustries = 6;

    char* actions[] = {"suppressing", "manipulating", "withholding", "creating", "controlling", "spreading"};
    int numActions = 6;

    char* targets[] = {"the government", "the population", "the environment", "the economy", "the education system", "the justice system"};
    int numTargets = 6;

    // generate random conspiracy theory
    printf("Did you know that the %s industry has been %s information about %s?\n", industries[rand() % numIndustries], actions[rand() % numActions], targets[rand() % numTargets]);

    return 0;
}