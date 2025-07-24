//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *theories[] = {
    "The government is hiding evidence of alien life.",
    "The moon landing was faked by NASA.",
    "Vaccines are a way for the government to control the population.",
    "The Earth is flat and the government is hiding the truth from us.",
    "The Illuminati controls the world's leaders.",
    "Chemtrails are being used for mind control.",
    "The Bermuda Triangle is a portal to another dimension.",
    "The Earth's core is a hollow space and aliens live inside."
};

int main() {
    srand(time(NULL));  // seed random number generator with time
    
    int num_theories = sizeof(theories) / sizeof(theories[0]);  // calculate number of theories
    int chosen_theory = rand() % num_theories;  // generate random number to choose theory
    
    printf("Random Conspiracy Theory Generator\n\n");
    printf("Your theory for today is:\n\n%s\n", theories[chosen_theory]);
    
    return 0;
}