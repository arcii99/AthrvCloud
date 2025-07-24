//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Initializing random seed based on current time

    char* subjects[] = {"Aliens", "Illuminati", "Big Pharma", "Government", "Reptilian Elite", "New World Order"};
    char* actions[] = {"are controlling", "are manipulating", "are conspiring against", "are brainwashing", "are surveilling"};
    char* objects[] = {"the masses", "the economy", "the health sector", "the media", "the education system"};

    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    int numActions = sizeof(actions) / sizeof(actions[0]);
    int numObjects = sizeof(objects) / sizeof(objects[0]);

    int numTheories = 10; // Number of conspiracy theories to generate

    printf("Here are %d random conspiracy theories:\n\n", numTheories);

    for (int i = 1; i <= numTheories; i++) {
        // Generate random indexes to select from each array
        int subjIndex = rand() % numSubjects;
        int actIndex = rand() % numActions;
        int objIndex = rand() % numObjects;

        printf("%d. %s %s %s.\n", i, subjects[subjIndex], actions[actIndex], objects[objIndex]);
    }

    return 0;
}