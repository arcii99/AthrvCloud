//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random generator with the current time

    char *subjects[] = {"the government", "aliens", "big pharma", "the illuminati", "secret societies", "the lizard people"};
    char *actions[] = {"are controlling", "are manipulating", "are experimenting on", "are brainwashing", "are spying on", "are enslaving"};
    char *objects[] = {"us", "our minds", "our bodies", "our DNA", "our thoughts", "our souls"};

    int subject_index = rand() % 6; // choose a random index for each array
    int action_index = rand() % 6;
    int object_index = rand() % 6;

    printf("Did you know that %s %s %s?\n", subjects[subject_index], actions[action_index], objects[object_index]); // print out the random conspiracy theory

    return 0;
}