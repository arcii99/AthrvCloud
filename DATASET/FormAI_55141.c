//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100 // Maximum length of a generated conspiracy theory
#define NUM_KEYWORDS 5 // Number of keywords used in the generator
#define NUM_PHRASES 10 // Number of phrases used in the generator

char* keywords[NUM_KEYWORDS] = {"government", "aliens", "illuminati", "mind control", "big pharma"};
char* phrases[NUM_PHRASES] = {"is hiding the truth about", "is working with", "is controlled by", "is using", "is behind"};

char* generate_conspiracy_theory() {
    srand(time(NULL)); // Initialize random seed
    
    char* conspiracy = malloc(sizeof(char) * MAX_CONSPIRACY_LENGTH); // Allocate memory for generated conspiracy theory
    int index = rand() % NUM_KEYWORDS; // Randomly select a keyword
    int phraseIndex = rand() % NUM_PHRASES; // Randomly select a phrase
    
    sprintf(conspiracy, "The %s %s ", keywords[index], phrases[phraseIndex]); // Construct the beginning of the conspiracy theory
    
    // Add random words after the beginning
    while (strlen(conspiracy) < MAX_CONSPIRACY_LENGTH - 1) {
        if (rand() % 2 == 0) {
            strcat(conspiracy, "and "); // Add the word "and"
        }
        index = rand() % NUM_KEYWORDS; // Randomly select a new keyword
        strcat(conspiracy, keywords[index]); // Append the keyword to the conspiracy theory
        if (strlen(conspiracy) >= MAX_CONSPIRACY_LENGTH - 1) {
            return conspiracy; // If the conspiracy theory has reached its maximum length, return it
        }
        phraseIndex = rand() % NUM_PHRASES; // Randomly select a new phrase
        strcat(conspiracy, " "); // Append a space
        strcat(conspiracy, phrases[phraseIndex]); // Append the phrase to the conspiracy theory
        if (strlen(conspiracy) >= MAX_CONSPIRACY_LENGTH - 1) {
            return conspiracy; // If the conspiracy theory has reached its maximum length, return it
        }
    }
    return conspiracy;
}

int main() {
    for (int i = 0; i < 10; i++) {
        char* conspiracy = generate_conspiracy_theory();
        printf("%s\n", conspiracy);
        free(conspiracy);
    }
    return 0;
}