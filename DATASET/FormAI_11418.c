//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *subjects[] = {"Chemtrails", "Area 51", "Bigfoot", "Illuminati", "Moon landing", "Reptilians", "Time travel", "COVID-19 vaccine", "Flat Earth", "HAARP"};
    char *verbs[] = {"caused", "was faked by", "was controlled by", "was invented by", "was manipulated by", "is being secretly tested by", "was propagated by", "is a cover-up by", "was created by", "was planned by"};
    char *objects[] = {"the government", "aliens", "the secret society", "the New World Order", "the deep state", "the Freemasons", "the elites", "the CIA", "the NSA", "the FBI"};

    srand(time(NULL));  // Initialize random number generator with current time
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    printf("Press enter to generate a new theory or enter 'q' to quit.\n\n");
    
    char input = getchar();
    while (input != 'q') {
        int sub_index = rand() % 10;  // Choose a random subject
        int verb_index = rand() % 10;  // Choose a random verb
        int obj_index = rand() % 10;  // Choose a random object
        
        printf("%s %s %s.\n\n", subjects[sub_index], verbs[verb_index], objects[obj_index]);  // Print the conspiracy theory
        
        input = getchar();  // Wait for user to enter input
    }
    
    return 0;
}