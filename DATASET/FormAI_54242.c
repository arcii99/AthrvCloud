//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    char* nouns[] = {"government", "aliens", "illuminati", "freemasons", "deep state", "big corporations"};
    char* adjectives[] = {"secret", "dangerous", "sinister", "unknown", "hidden", "mysterious"};
    char* verbs[] = {"controlling", "manipulating", "brainwashing", "spying on", "influencing", "suppressing"};

    int num_nouns = sizeof(nouns) / sizeof(*nouns);
    int num_adj = sizeof(adjectives) / sizeof(*adjectives);
    int num_verbs = sizeof(verbs) / sizeof(*verbs);

    // Generate random conspiracy theory
    printf("Did you know that the %s %s are %s the world?\n", adjectives[rand() % num_adj], nouns[rand() % num_nouns], verbs[rand() % num_verbs]);
    printf("It's true! %s have been working behind the scenes to %s the masses for years.\n", nouns[rand() % num_nouns], verbs[rand() % num_verbs]);
    printf("But don't worry, there are ways to protect yourself from their %s agenda. Stay vigilant and %s.\n", adjectives[rand() % num_adj], verbs[rand() % num_verbs]);

    return 0;
}