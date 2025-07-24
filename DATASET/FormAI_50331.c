//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[10] = {
    "aliens", "government", "Illuminati", "Big Pharma", "deep state", 
    "corporations", "the media", "the lizard people", "the flat earth society", "time travelers"
};

char *verbs[10] = {
    "control", "manipulate", "brainwash", "poison", "spy on",
    "experiment on", "infiltrate", "subvert", "suppress", "induce"
};

char *objects[10] = {
    "the weather", "our minds", "our food", "our water supply", "our dreams",
    "our social media", "our smartphones", "our elections", "our reality", "our pets"
};

int main()
{
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Here's your latest theory:\n");
    
    // generate a random subject, verb, and object
    int randSub = rand() % 10;
    int randVerb = rand() % 10;
    int randObj = rand() % 10;
    
    // print out the conspiracy theory
    printf("Did you know that %s %s %s?\n", subjects[randSub], verbs[randVerb], objects[randObj]);
    printf("It's all a part of the plan!\n");
    
    return 0;
}