//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    char* subjects[] = {"The government", "Aliens", "The Illuminati", "Big Pharma", "The Freemasons", "The Jewish cabal", "The reptilian elite"};
    char* actions[] = {"is controlling the weather", "is monitoring our thoughts", "caused the pandemic", "is hiding the cure for cancer", "is planning a massive world war", "is manipulating the stock market", "is creating genetically modified humans"};
    char* consequences[] = {"to establish a New World Order", "to enslave humanity", "to depopulate the planet", "to create a global dictatorship", "to profit off of our suffering"};

    for (int i = 0; i < 5; i++) { // generate 5 random conspiracy theories
        int subj_idx = rand() % 7; // choose a random index for the subject array
        int act_idx = rand() % 7; // choose a random index for the action array
        int consq_idx = rand() % 5; // choose a random index for the consequence array

        printf("%s %s %s.\n", subjects[subj_idx], actions[act_idx], consequences[consq_idx]); // print out the conspiracy theory
    }

    return 0;
}