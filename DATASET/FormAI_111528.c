//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random seed

    char subjects[5][20] = {"Government", "Aliens", "Illuminati", "Corporations", "Elites"};
    char verbs[5][20] = {"control", "manipulate", "brainwash", "monitor", "influence"};
    char objects[5][20] = {"population", "media", "weather", "technology", "fate"};

    int num_theories = 10; //number of conspiracy theories to generate

    printf("Here are some random conspiracy theories:\n");

    for(int i=0; i<num_theories; i++) {
        int subj_index = rand() % 5;
        int verb_index = rand() % 5;
        int obj_index = rand() % 5;

        printf("- %s %s the %s.\n", subjects[subj_index], verbs[verb_index], objects[obj_index]);
    }

    return 0;
}