//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    char* keywords[] = {"government", "aliens", "Illuminati", "Big Pharma", "NWO", "chemtrails", "Mandela Effect", "Flat Earth", "vaccines", "5G", "COVID-19"};
    char* phrases[] = {"are hiding information from us", "have been brainwashing us for years", "are controlling the world", "are working with extraterrestrial beings", "are behind the pandemic"};

    int keywordIndex = rand() % (sizeof(keywords) / sizeof(keywords[0]));
    int phraseIndex = rand() % (sizeof(phrases) / sizeof(phrases[0]));

    printf("Did you know that the %s %s?\n", keywords[keywordIndex], phrases[phraseIndex]);

    return 0;
}