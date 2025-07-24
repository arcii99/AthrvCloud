//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // declare arrays for conspiracy theories
    char *group[] = {"The Government", "The Illuminati", "The Deep State", "Big Pharma", "The Freemasons", "The Reptilians"};
    char *action[] = {"is controlling", "is manipulating", "is planning", "is spreading", "is hiding", "is brainwashing"};
    char *object[] = {"our thoughts", "the weather", "the economy", "the media", "the internet", "aliens"};

    // generate random conspiracy theory
    int group_index = rand() % 6;
    int action_index = rand() % 6;
    int object_index = rand() % 6;

    // print theory
    printf("%s %s %s.", group[group_index], action[action_index], object[object_index]);

    return 0;
}