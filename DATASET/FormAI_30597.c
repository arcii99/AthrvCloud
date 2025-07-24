//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed the random number generator
    srand(time(NULL));

    // define arrays of conspiracy theories and subjects
    char* theories[] = {
        "The moon landing was faked!",
        "Chemtrails are poisoning us!",
        "The government is hiding evidence of aliens!",
        "The Illuminati control everything!",
        "9/11 was an inside job!",
        "COVID-19 is a hoax!"
    };
    char* subjects[] = {
        "the government",
        "the military",
        "the medical industry",
        "big pharma",
        "technology companies",
        "the entertainment industry"
    };

    // randomly select a theory and subject to combine
    int theory_index = rand() % 6;
    int subject_index = rand() % 6;
    char* theory = theories[theory_index];
    char* subject = subjects[subject_index];

    // print the conspiracy theory
    printf("Did you know that %s is responsible for %s?\n", subject, theory);

    return 0;
}