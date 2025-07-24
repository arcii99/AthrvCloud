//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    char* topics[] = {"government", "aliens", "big pharma", "technology", "religion"};
    char* verbs[] = {"is controlled by", "is in cahoots with", "is a front for", "is secretly run by", "is manipulated by"};
    char* entities[] = {"the Illuminati", "the lizard people", "the New World Order", "the Freemasons", "the shadow government"};

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    int i;
    for (i = 0; i < 5; i++) {
        int topicIndex = rand() % 5;
        int verbIndex = rand() % 5;
        int entityIndex = rand() % 5;
        printf("%s %s %s.\n", topics[topicIndex], verbs[verbIndex], entities[entityIndex]);
    }

    printf("\nDon't forget to wear your tin foil hat!\n");

    return 0;
}