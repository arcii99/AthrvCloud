//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    char* subjects[] = {"The government", "The Illuminati", "Big Pharma", "Aliens", "Time Travelers"};
    char* actions[] = {"are controlling", "are manipulating", "are brainwashing", "are hiding evidence of", "are secretly funding"};
    char* targets[] = {"the weather", "our minds", "the stock market", "crypto-currency", "the moon landing"};

    int num_theories = 10;

    for(int i = 0; i < num_theories; i++) {
        int subj_index = rand() % 5;
        int act_index = rand() % 5;
        int targ_index = rand() % 5;

        printf("%s %s %s.\n", subjects[subj_index], actions[act_index], targets[targ_index]);
    }

    return 0;
}