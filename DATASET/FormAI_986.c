//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {
    "The government",
    "Aliens",
    "The illuminati",
    "The lizard people",
    "The deep state",
    "Big Pharma",
    "The CIA",
    "The New World Order",
    "The Freemasons",
    "The Bilderberg Group",
    "The Rothschilds",
    "The Trilateral Commission",
    "The Vatican",
    "The NSA"
};

char *verbs[] = {
    "is controlling",
    "is manipulating",
    "is brainwashing",
    "is experimenting on",
    "is spying on",
    "is hiding information about",
    "is creating a global crisis with",
    "is using technology to control",
    "is funding",
    "is behind the creation of"
};

char *objects[] = {
    "the weather",
    "our food and water",
    "the media",
    "our brains",
    "the economy",
    "the military",
    "our emotions",
    "the education system",
    "the entertainment industry",
    "the internet"
};

char *evidence[] = {
    "Proof can be found in leaked documents",
    "Scientists have found evidence to support this theory",
    "Whistleblowers have come forward with information",
    "The information is hidden in plain sight",
    "There are too many coincidences to ignore",
    "Celebrities have hinted at the truth",
    "Alternative media outlets have reported on this",
    "There is a pattern of behavior that supports this theory"
};

void generate_conspiracy_theory() {
    int num_subjects = sizeof(subjects) / sizeof(char*);
    int num_verbs = sizeof(verbs) / sizeof(char*);
    int num_objects = sizeof(objects) / sizeof(char*);
    int num_evidence = sizeof(evidence) / sizeof(char*);

    printf("%s %s %s. %s.\n", subjects[rand() % num_subjects], verbs[rand() % num_verbs], objects[rand() % num_objects], evidence[rand() % num_evidence]);
}

int main() {
    srand(time(NULL));
    printf("--RANDOM CONSPIRACY THEORY GENERATOR--\n\n");

    for (int i = 0; i < 10; i++) {
        generate_conspiracy_theory();
    }

    return 0;
}