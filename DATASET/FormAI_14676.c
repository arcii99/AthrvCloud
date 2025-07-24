//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char *subjects[] = {"The government", "Big corporations", "Aliens", "The Illuminati", "The Freemasons", "The deep state"};
    char *verbs[] = {"is controlling", "is manipulating", "is brainwashing", "is covering up", "is experimenting on", "is surveilling"};
    char *objects[] = {"the weather", "our minds", "the economy", "social media", "the food supply", "the news"};

    // Generate random conspiracy theory
    int subjectIndex = rand() % 6;
    int verbIndex = rand() % 6;
    int objectIndex = rand() % 6;

    printf("%s %s %s.\n", subjects[subjectIndex], verbs[verbIndex], objects[objectIndex]);

    return 0;
}