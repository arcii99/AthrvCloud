//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // sets seed for random number generator

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    char* subjects[] = {"The government", "The Illuminati", "The lizard people", "The Freemasons", "The New World Order"};
    char* actions[] = {"is controlling", "is manipulating", "is hiding", "is sabotaging", "is brainwashing"};
    char* targets[] = {"the media", "the weather", "our minds", "our DNA", "the economy"};

    // generates a random conspiracy theory
    printf("%s %s %s!", subjects[rand() % 5], actions[rand() % 5], targets[rand() % 5]);

    return 0;
}