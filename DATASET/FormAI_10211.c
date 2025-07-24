//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {
    "The government",
    "Global elite",
    "Aliens",
    "Illuminati",
    "Corporations",
    "The media",
    "The military",
    "The education system",
    "The medical industry",
    "Religious institutions",
    "The scientific community"
};

char *verbs[] = {
    "is controlling",
    "is manipulating",
    "is hiding",
    "is suppressing",
    "is brainwashing",
    "is experimenting on",
    "is monitoring",
    "is infiltrating",
    "is sabotaging",
    "is creating"
};

char *objects[] = {
    "our minds",
    "the weather",
    "the economy",
    "the food supply",
    "the internet",
    "the entertainment industry",
    "the energy industry",
    "the education system",
    "the medical industry",
    "the military",
    "the scientific community"
};

char *modifiers[] = {
    "with mind control",
    "with secret technology",
    "with chemtrails",
    "with subliminal messages",
    "with propaganda",
    "with genetic modification",
    "with precision strikes",
    "with blackmail",
    "with viruses",
    "with nanobots",
    "with aliens",
    "using interdimensional portals",
    "by manipulating time",
    "using a secret language"
};

char *evidences[] = {
    "I heard it from a reliable source",
    "It's on the internet, so it must be true",
    "I saw it in a dream",
    "It just makes logical sense",
    "I have insider information",
    "It's been confirmed by multiple sources, but they're all being silenced",
    "The signs are all around us",
    "It's in plain sight, but most people are too blind to see it"
};

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("%s %s %s %s.\n", 
               subjects[rand() % (sizeof(subjects) / sizeof(char*))],
               verbs[rand() % (sizeof(verbs) / sizeof(char*))],
               objects[rand() % (sizeof(objects) / sizeof(char*))],
               modifiers[rand() % (sizeof(modifiers) / sizeof(char*))]);
        printf("%s.\n\n", evidences[rand() % (sizeof(evidences) / sizeof(char*))]);
    }
    return 0;
}