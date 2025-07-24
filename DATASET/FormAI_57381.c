//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* nouns[] = {"fluoride", "lizard people", "chemtrails", "HAARP", "vaccines", "Illuminati", "CIA", "NSA", "aliens", "Bilderberg Group"};
    char* verbs[] = {"controls", "manipulates", "terrifies", "brainwashes", "spreads", "infiltrates", "discredits", "suppresses", "monitors", "harasses"};
    char* adjectives[] = {"mind control", "fake news", "hidden agenda", "mass hysteria", "secret experiments", "conspiracy theory", "global warming hoax", "deep state", "new world order", "black ops"};

    srand(time(NULL)); // initialize random seed
    int noun_index = rand() % 10;
    int verb_index = rand() % 10;
    int adj_index = rand() % 10;

    printf("Did you know that %s %s our minds with %s?\n", nouns[noun_index], verbs[verb_index], adjectives[adj_index]);

    return 0;
}