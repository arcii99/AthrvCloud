//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *subjects[] = {"The government", "Big Pharma", "The Illuminati", "Aliens", "Time Travelers"};
    char *verbs[] = {"are manipulating", "are brainwashing", "are controlling", "are spying on", "are suppressing"};
    char *objects[] = {"the population", "our dreams", "our technology", "our climate", "our food supply"};

    int i;
    srand(time(NULL)); // Initialize random seed

    printf("Here's your random conspiracy theory:\n");

    for (i = 0; i < 5; i++)
    {
        // Select a random subject, verb, and object and print them out
        printf("%s ", subjects[rand() % 5]);
        printf("%s ", verbs[rand() % 5]);
        printf("%s.\n", objects[rand() % 5]);
    }

    return 0;
}