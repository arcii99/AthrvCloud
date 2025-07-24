//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    char* subjects[] = {"The government", "The Illuminati", "Aliens", "The Freemasons"};
    char* actions[] = {"is controlling the weather", "is hiding evidence of Bigfoot", "caused the moon landing to be fake"};
    char* reasons[] = {"to maintain power", "to distract the public from their true intentions"};

    int subject_index = rand() % 4;
    int action_index = rand() % 3;
    int reason_index = rand() % 2;

    printf("%s %s %s.\n", subjects[subject_index], actions[action_index], reasons[reason_index]);

    return 0;
}