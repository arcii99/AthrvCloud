//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define arrays of possible conspiracy theories
    char *conspiracy1[] = {"The moon landing was faked by the government", 
                           "Chemtrails are being used to control the population", 
                           "COVID-19 was invented in a lab as a bioweapon"};
    char *conspiracy2[] = {"to distract the public from the truth about aliens", 
                           "to cover up the existence of Bigfoot", 
                           "to hide the fact that the Earth is actually flat"};

    // Generate random indices for each array
    int index1 = rand() % 3;
    int index2 = rand() % 3;

    // Print the conspiracy theory
    printf("Did you know that %s %s?\n", conspiracy1[index1], conspiracy2[index2]);

    return 0;
}