//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random number generator

    char* subjects[] = {"The government", "Aliens", "The Illuminati", "Big Pharma", "The Freemasons", "Time Travelers", "Elon Musk", "The Rothschilds", "The Reptilians", "Artificial Intelligence"};
    char* verbs[] = {"are controlling", "are manipulating", "are experimenting on", "are brainwashing", "are harvesting", "are covering up", "are infiltrating", "are surveilling", "are sacrificing", "are cloning"};
    char* objects[] = {"the weather", "our dreams", "our thoughts", "our DNA", "our food supply", "our elections", "our entertainment", "our education", "our health", "our future"};

    int subject_index = rand() % 10;
    int verb_index = rand() % 10;
    int object_index = rand() % 10;

    printf("Did you know that %s %s %s?\n", subjects[subject_index], verbs[verb_index], objects[object_index]);

    return 0;
}