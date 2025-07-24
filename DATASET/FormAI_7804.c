//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Array of conspiracy theories
    char* theories[] = {"The moon landing was faked", "9/11 was an inside job", "The government is run by lizard people", "The COVID-19 vaccine has a microchip in it", 
                        "The earth is flat", "Chemtrails are poisoning us", "Elvis is still alive", "The illuminati controls everything", "Aliens built the pyramids"};
    
    // Generate a random index to get a random conspiracy theory
    int index = rand() % 9;

    // Print the conspiracy theory
    printf("Did you know: %s?\n", theories[index]);

    return 0;
}