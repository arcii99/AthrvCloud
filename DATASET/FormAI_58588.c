//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // initialize random seed

    char* nouns[] = {"government", "aliens", "Illuminati", "Big Pharma", "Masons", "reptilians", "New World Order"};
    char* adjectives[] = {"secret", "hidden", "covert", "mysterious", "suspicious", "deceptive"};
    char* verbs[] = {"manipulating", "controlling", "influencing", "brainwashing", "planning"};

    int noun_index = rand() % 7;
    int adj_index = rand() % 6;
    int verb_index = rand() % 5;

    printf("Did you know that the %s %s %s our minds?\n", adjectives[adj_index], nouns[noun_index], verbs[verb_index]);

    return 0;
}