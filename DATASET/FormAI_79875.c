//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed the random number generator with the current time
    srand(time(NULL));

    // define arrays of potential conspiracy theories
    char *people[] = { "the Illuminati", "the reptilian overlords", "the Freemasons", "the Deep State", "the New World Order" };
    char *events[] = { "9/11", "the moon landing", "JFK's assassination", "the COVID-19 pandemic" };
    char *reasons[] = { "to control the population", "to establish a one-world government", "to hide the truth about alien life", "to gain ultimate power" };

    // randomly select elements from each array and combine them into a conspiracy theory
    char *conspiracy = calloc(100, sizeof(char)); // allocate memory for the theory
    int index = rand() % 5; // randomly select an element from the people array
    snprintf(conspiracy, 100, "Did you know %s orchestrated ", people[index]);
    index = rand() % 4; // randomly select an element from the events array
    snprintf(conspiracy + strlen(conspiracy), 100 - strlen(conspiracy), "%s ", events[index]);
    index = rand() % 4; // randomly select an element from the reasons array
    snprintf(conspiracy + strlen(conspiracy), 100 - strlen(conspiracy), "%s?", reasons[index]);

    // output the conspiracy theory
    printf("%s\n", conspiracy);

    // free memory
    free(conspiracy);

    return 0;
}