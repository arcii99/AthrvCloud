//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {
    "The government",
    "The Illuminati",
    "Big Pharma",
    "The Deep State",
    "Aliens",
    "The Freemasons",
    "The New World Order",
};

char *actions[] = {
    "is controlling",
    "is manipulating",
    "is poisoning",
    "is brainwashing",
    "is spying on",
    "is infecting",
    "is altering",
};

char *objects[] = {
    "our thoughts",
    "our weather",
    "our water supply",
    "our food supply",
    "our DNA",
    "our beliefs",
    "our emotions",
};

char *outcomes[] = {
    "to enslave us",
    "to weaken us",
    "to make us sick",
    "to make us obedient",
    "to take away our free will",
    "to prepare for an invasion",
    "to create a one-world government",
};

void generate_conspiracy_theory()
{
    // Set random seed based on time
    srand(time(NULL));
    
    // Generate random indices for each array
    int subject_index = rand() % 7;
    int action_index = rand() % 7;
    int object_index = rand() % 7;
    int outcome_index = rand() % 7;
    
    // Print out the conspiracy theory
    printf("%s %s %s %s.\n", subjects[subject_index], actions[action_index], objects[object_index], outcomes[outcome_index]);
}

int main()
{
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    
    // Generate 10 conspiracy theories
    for (int i = 0; i < 10; i++) {
        generate_conspiracy_theory();
    }
    
    return 0;
}