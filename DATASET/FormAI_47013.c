//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *subjects[] = {
    "The Moon",
    "The Government",
    "The Illuminati",
    "Aliens",
    "Elites",
    "Big Pharma",
    "The New World Order",
    "The Deep State",
    "The Vatican",
    "Mars",
    "The CIA",
    "Area 51",
    "Ancient Civilizations",
    "The Rothschilds",
    "Reptilian Overlords",
    "The Freemasons"
};

char *verbs[] = {
    "are controlling",
    "are manipulating",
    "are orchestrating",
    "are brainwashing",
    "are conspiring with",
    "are collaborating with",
    "are working with",
    "have infiltrated"
};

char *objects[] = {
    "our minds",
    "the media",
    "our education system",
    "the economy",
    "the weather",
    "the medical industry",
    "world events",
    "the future",
    "the past",
    "the space program",
    "human evolution"
};

int main() {
    srand(time(NULL)); // Initialize random seed

    printf("Random conspiracy theory generator:\n\n");

    // Generate and print 10 conspiracy theories
    for (int i = 0; i < 10; i++) {
        int subjectIndex = rand() % (sizeof(subjects) / sizeof(subjects[0]));
        int verbIndex = rand() % (sizeof(verbs) / sizeof(verbs[0]));
        int objectIndex = rand() % (sizeof(objects) / sizeof(objects[0]));

        printf("%d. %s %s %s.\n", i+1, subjects[subjectIndex], verbs[verbIndex], objects[objectIndex]);
    }

    return 0;
}