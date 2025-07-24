//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define number of conspiracy theories and maximum length
#define NUM_THEORIES 10
#define MAX_LENGTH 100

// Define arrays of conspiracy theories and possible keywords
char theories[NUM_THEORIES][MAX_LENGTH] = {
    "The moon landing was fake",
    "The government is hiding the cure for cancer",
    "The Illuminati is controlling everything",
    "9/11 was an inside job",
    "The Earth is flat",
    "Aliens are among us",
    "The CIA killed JFK",
    "Chemtrails are poisoning us",
    "The world is run by reptilian overlords",
    "Vaccines cause autism"
};

char keywords[5][MAX_LENGTH] = {
    "secret",
    "hidden",
    "cover-up",
    "classified",
    "conspiracy"
};

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate a random theory
    int index = rand() % NUM_THEORIES;
    char* theory = theories[index];
    
    // Add some flavor text
    printf("Generating a conspiracy theory...\n\n");
    printf("You know, I've heard some strange things lately. Just the other day, someone told me something %s.\n", keywords[rand() % 5]);
    printf("It made me think of this theory I heard about: %s.\n", theory);
    
    // Generate some evidence for the theory
    printf("\nAnd get this: I found some evidence to support it. Check this out:\n");
    for (int i = 0; i < 3; i++) {
        char* evidence = (char*) malloc(MAX_LENGTH * sizeof(char));
        sprintf(evidence, "- %s is connected to %s", theory, keywords[rand() % 5]);
        printf("%s\n", evidence);
        free(evidence);
    }
    
    // Generate a conclusion
    printf("\nSo there you have it. It all makes sense now. The %s is real and we need to do something about it.\n", theory);
    
    return 0;
}