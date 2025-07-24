//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* topics[] = {"Aliens", "Government Cover-Ups", "Illuminati", "9/11", "Area 51", "Chemtrails", "Flat Earth Society", "New World Order", "Big Pharma", "Reptilian Elite"};
    char* verbs[] = {"control", "manipulate", "brainwash", "spy on", "poison", "suppress", "experiment on", "fund", "flee from", "terrorize"};
    char* objects[] = {"us", "the media", "the environment", "our minds", "our bodies", "our food supply", "our governments", "the economy", "our DNA", "the truth"};

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int topicIndex = rand() % 10;
        int verbIndex = rand() % 10;
        int objectIndex = rand() % 10;

        printf("%d. The %s are using %s to %s %s.\n", i+1, topics[topicIndex], objects[objectIndex], verbs[verbIndex], objects[objectIndex]);
    }

    return 0;
}