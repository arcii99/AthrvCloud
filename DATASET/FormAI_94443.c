//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *subjects[] = {"The government", "The Illuminati", "The aliens", "Big Pharma", "The reptilians", "The Freemasons", "The New World Order"};
char *verbs[] = {"created", "manipulated", "secretly controls", "is collaborating with", "funded", "brainwashed", "planned"};
char *objects[] = {"9/11", "the moon landing", "the JFK assassination", "the COVID-19 pandemic", "Bigfoot sightings", "the Loch Ness Monster", "crop circles"};

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    
    char input[50];
    while (strcasecmp(input, "exit") != 0) { // Loop until user enters "exit"
        printf("\nPress enter for a random conspiracy theory, or type 'exit' to quit.\n");
        fgets(input, 50, stdin);
        
        int subject_index = rand() % 7; // Generate random index for each array
        int verb_index = rand() % 7;
        int object_index = rand() % 7;
        
        printf("\n%s %s %s.\n", subjects[subject_index], verbs[verb_index], objects[object_index]);
    }
    
    printf("\nGoodbye!\n");
    
    return 0;
}