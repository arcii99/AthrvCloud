//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {"The Government", "Aliens", "The Illuminati", "Big Pharma", "The New World Order"};
char *verbs[] = {"is controlling", "is manipulating", "is secretly funding", "is experimenting on", "is brainwashing"};
char *nouns[] = {"the weather", "our minds", "the media", "politics", "technology"};

int main() {
    srand(time(NULL));
    int rand1 = rand() % 5;
    int rand2 = rand() % 5;
    int rand3 = rand() % 5;
    printf("According to my sources, %s %s %s.\n", subjects[rand1], verbs[rand2], nouns[rand3]);
    return 0;
}