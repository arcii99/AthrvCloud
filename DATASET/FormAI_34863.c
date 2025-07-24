//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a given range
int randomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));

    // Define some arrays containing conspiracy theory components
    char *subjects[] = {
        "The Government",
        "The Illuminati",
        "Aliens",
        "Big Pharma",
        "The CIA",
    };

    char *verbs[] = {
        "controls",
        "manipulates",
        "is hiding",
        "is behind",
        "is plotting",
    };

    char *objects[] = {
        "the weather",
        "the economy",
        "the media",
        "our minds",
        "the truth",
    };

    char *evidences[] = {
        "I saw it on Facebook",
        "It's obvious from the way things are",
        "My friend's cousin knows a guy who works for them",
        "They never told us the full story",
        "It just feels right",
    };

    // Generate some random numbers to select components from the arrays
    int s = randomInRange(0, 4);
    int v = randomInRange(0, 4);
    int o = randomInRange(0, 4);
    int e = randomInRange(0, 4);

    // Print out the conspiracy theory statement
    printf("%s %s %s %s!\n", subjects[s], verbs[v], objects[o], evidences[e]);

    return 0;
}