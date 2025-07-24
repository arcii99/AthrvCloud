//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *conspiracy_theories[] = {"The moon landing was faked", "9/11 was an inside job", "COVID-19 was created in a laboratory"};

    char *culprits[] = {"the government", "aliens", "the Illuminati", "big pharma"};

    char *evidence[] = {"there are no stars visible in the moon landing photos", "building 7 of the World Trade Center collapsed too perfectly", "the virus's genetic structure appears to have been artificially modified"};

    char *explanations[] = {"to win the space race against the Soviets", "to give the US an excuse for war in the Middle East", "to create a world-wide health crisis and control the population"};

    srand(time(NULL));

    printf("Here is your personalized conspiracy theory:\n\n");

    printf("Did you know that %s conspired with %s to perpetrate %s?\n\n", culprits[rand() % 4], culprits[rand() % 4], conspiracy_theories[rand() % 3]);

    printf("And the evidence is clear - %s.\n\n", evidence[rand() % 3]);

    printf("Why would they do such a thing, you ask? The answer is simple: %s.\n\n", explanations[rand() % 3]);

    printf("Wake up and smell the coffee, sheeple!");

    return 0;
}