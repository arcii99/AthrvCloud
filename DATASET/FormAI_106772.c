//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* subjects[] = {"The government", "The Illuminati", "Big Brother", "The Freemasons", "The New World Order"};
char* verbs[] = {"controls", "watches", "manipulates", "influences", "brainwashes"};
char* objects[] = {"our thoughts", "the media", "the internet", "the weather", "our dreams"};
char* endings[] = {"to achieve their own agenda", "for their own gain", "to keep us in the dark", "to maintain power", "to enslave humanity"};

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int subjectIndex = rand() % 5;
        int verbIndex = rand() % 5;
        int objectIndex = rand() % 5;
        int endingIndex = rand() % 5;
        printf("%s %s %s %s.\n", subjects[subjectIndex], verbs[verbIndex], objects[objectIndex], endings[endingIndex]);
    }
    return 0;
}