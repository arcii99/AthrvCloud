//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() { 
    srand(time(NULL));
    char* subjects[] = {"The government", "The Illuminati", "Aliens", "Big Pharma", "The Rothschilds", "The Deep State", "The CIA", "The Freemasons", "The New World Order", "The Reptilians"};
    char* verbs[] = {"is controlling", "is manipulating", "is brainwashing", "is experimenting on", "is surveilling", "is covering up", "is infiltrating", "is poisoning", "is sacrificing", "is collaborating with"};
    char* objects[] = {"our minds", "the weather", "the economy", "the media", "our food and water", "our DNA", "the education system", "the healthcare system", "the entertainment industry", "the technology industry"};
    char* outcomes[] = {"to enslave humanity", "to depopulate the world", "to create a one-world government", "to establish a totalitarian state", "to usher in the Antichrist", "to exterminate dissidents", "to extract resources from the planet", "to perpetuate their power and wealth"};

    printf("\nWelcome to the Random Conspiracy Theory Generator!\n\n");
    printf("Do you want to know who's behind a certain phenomenon? Press Enter to continue.\n\n");
    getchar();

    printf("The answer is...\n\n");

    int subject_idx = rand() % 10;
    int verb_idx = rand() % 10;
    int object_idx = rand() % 10;
    int outcome_idx = rand() % 8;

    printf("%s %s %s %s!\n\n", subjects[subject_idx], verbs[verb_idx], objects[object_idx], outcomes[outcome_idx]);

    printf("Don't believe it? That's the first sign of being brainwashed!\n");

    return 0; 
}