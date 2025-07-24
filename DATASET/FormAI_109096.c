//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with current time
    char* nouns[] = {"aliens", "government", "Illuminati", "Big Pharma", "world leaders", "the CIA"}; // array of nouns for conspiracy theory
    char* verbs[] = {"control", "manipulate", "brainwash", "experiment on", "dominate", "enslave"}; // array of verbs for conspiracy theory
    char* adjs[] = {"secret", "shadowy", "hidden", "covert", "mysterious", "sinister"}; // array of adjectives for conspiracy theory
    char* endings[] = {"to take over the world.", "to suppress the truth.", "for their own gain.", "to destroy humanity.", "to create a new world order."}; // array of endings for conspiracy theory
    int nounIdx, verbIdx, adjIdx, endingIdx; // random index variables for each array

    for (int i = 0; i < 10; i++) // generate 10 conspiracy theories
    {
        nounIdx = rand() % 6; // randomly select index for noun array
        verbIdx = rand() % 6; // randomly select index for verb array
        adjIdx = rand() % 6; // randomly select index for adjective array
        endingIdx = rand() % 5; // randomly select index for ending array

        printf("%d. Did you know that the %s are trying to %s the world? They have a %s plan %s\n", i+1, nouns[nounIdx], verbs[verbIdx], adjs[adjIdx], endings[endingIdx]);
    }

    return 0;
}