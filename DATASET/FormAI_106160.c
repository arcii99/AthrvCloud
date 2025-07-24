//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandomConspiracy();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    for(int i=0; i<10; i++) {
        printRandomConspiracy();
    }

    return 0;
}

void printRandomConspiracy() {
    // List of conspiracy theories
    char *conspiracies[] = {
        "The moon landing was fake",
        "The earth is flat",
        "The government is hiding aliens",
        "The Illuminati controls everything",
        "Chemtrails are causing global warming",
        "9/11 was an inside job"
    };
    int numConspiracies = sizeof(conspiracies) / sizeof(char*);

    // List of ways the conspiracy is being hidden
    char *hidingMethods[] = {
        "by the government",
        "by the media",
        "by powerful elites",
        "through mind control",
        "by hiding evidence",
        "through secret societies"
    };
    int numHidingMethods = sizeof(hidingMethods) / sizeof(char*);

    // List of possible culprits
    char *culprits[] = {
        "the New World Order",
        "the Deep State",
        "the Bilderberg Group",
        "the Freemasons",
        "the Rothschilds",
        "the Vatican"
    };
    int numCulprits = sizeof(culprits) / sizeof(char*);

    int conspiracyIndex = rand() % numConspiracies;
    int hidingMethodIndex = rand() % numHidingMethods;
    int culpritIndex = rand() % numCulprits;

    printf("%s is being hidden %s %s.\n", conspiracies[conspiracyIndex], hidingMethods[hidingMethodIndex], culprits[culpritIndex]);
}