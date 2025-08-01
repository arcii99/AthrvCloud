//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the length of the random conspiracy theory generated by the program
#define MAX_LENGTH 100

int main() {

    // create an array of conspiracy theories
    char* theories[]= {
        "The moon landing was faked",
        "9/11 was an inside job",
        "The government is controlling our minds through the media",
        "Aliens are already among us",
        "The Illuminati controls the world",
        "The JFK assassination was a government cover-up",
        "Climate change is a hoax",
        "The earth is flat",
        "The COVID-19 pandemic was intentionally created",
        "Vaccines are used to control population"
    };

    // get the number of theories in the array
    int num_theories = sizeof(theories)/sizeof(char*);

    // generate a random index for the conspiracy theory array
    srand(time(NULL));
    int index = rand() % num_theories;

    // randomly generate a length for the conspiracy theory 
    int length = (rand() % MAX_LENGTH) + 1;

    // create an array to store the randomly generated conspiracy theory string
    char* conspiracy_theory = malloc(length * sizeof(char));

    // randomly generate a conspiracy theory string by concatenating random words from the theories array
    for(int i=0; i<length; i++){
        int j = rand() % strlen(theories[index]);
        conspiracy_theory[i] = theories[index][j];
    }

    // print the randomly generated conspiracy theory
    printf("Random Conspiracy Theory: %s\n", conspiracy_theory);

    // free the allocated memory
    free(conspiracy_theory);
    
    return 0;
}