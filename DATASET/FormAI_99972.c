//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *subjects[] = {"The government", "The Illuminati", "Big Tech", "The Freemasons", "The NWO", "The aliens", "The lizard people", "The deep state"};
    char *verbs[] = {"is planning", "is controlling", "is funding", "is manipulating", "is brainwashing", "is hiding", "is creating", "is orchestrating"};
    char *objects[] = {"the weather", "the economy", "the elections", "the media", "the education system", "the healthcare system", "the entertainment industry", "the technology industry"};

    srand(time(NULL));

    printf("RANDOM CONSPIRACY THEORY GENERATOR\n\n");

    for (int i = 0; i < 10; i++) {
        int rand_sub = rand() % 8;
        int rand_verb = rand() % 8;
        int rand_obj = rand() % 8;

        printf("%d. %s %s %s.\n", i+1, subjects[rand_sub], verbs[rand_verb], objects[rand_obj]);
    }

    return 0;
}