//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator.
    srand(time(NULL));

    // Define the arrays to be used.
    char *subjects[] = {"The Government", "The Illuminati", "NASA", "The Freemasons", "Aliens"};
    char *actions[] = {"are hiding", "are controlling", "have secret knowledge of", "are manipulating", "have covered up"};
    char *objects[] = {"the cure for cancer", "the truth about JFK's assassination", "the existence of Bigfoot", "the location of Atlantis", "the meaning of life"};

    // Generate random conspiracy theories.
    for (int i = 0; i < 10; i++) {
        printf("%d. %s %s %s.\n", i+1, subjects[rand() % 5], actions[rand() % 5], objects[rand() % 5]);
    }

    return 0;
}