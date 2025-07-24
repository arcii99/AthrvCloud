//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // set the seed for the random number generator

    // arrays of words to use in our conspiracy theories
    char *nouns[] = {"government", "Illuminati", "aliens", "New World Order", "Bilderberg Group", "Deep State"};
    char *verbs[] = {"control", "manipulate", "brainwash", "influence", "dominate", "enslave"};
    char *adjectives[] = {"secret", "powerful", "malevolent", "sinister", "shadowy", "mysterious"};
    char *people[] = {"politicians", "CEOs", "media moguls", "military leaders", "bankers", "celebrities"};

    // randomly choose words from our arrays to create a conspiracy theory
    int nounIndex = rand() % 6;
    int verbIndex = rand() % 6;
    int adjectiveIndex = rand() % 6;
    int peopleIndex = rand() % 6;

    // print out the conspiracy theory
    printf("Did you know that the %s %s %s %s? It's all part of their plan to %s %s!\n", 
            adjectives[adjectiveIndex], nouns[nounIndex], people[peopleIndex], verbs[verbIndex],
            verbs[verbIndex], nouns[nounIndex]);

    return 0;
}