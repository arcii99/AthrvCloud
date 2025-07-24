//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a function to generate a random conspiracy theory
void conspiracyTheoryGenerator(void) {
    // Declare an array of conspiracy theories
    char *conspiracyTheories[] = {"The moon landing was faked!", 
                                  "The government controls the weather!", 
                                  "Aliens are living among us!", 
                                  "The Illuminati is controlling everything!", 
                                  "Vaccines are causing autism!", 
                                  "The Earth is actually flat!",
                                  // Add your own conspiracy theories here!
                                  };
    
    // Get the size of the array
    int numTheories = sizeof(conspiracyTheories)/sizeof(conspiracyTheories[0]);
    
    // Generate a random number within the range of the array size
    srand(time(NULL));
    int randomIndex = rand() % numTheories;
    
    // Print the conspiracy theory
    printf("Did you know? %s\n", conspiracyTheories[randomIndex]);
}

// Define the main function
int main(void) {
    // Generate 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        conspiracyTheoryGenerator();
    }
    
    return 0;
}