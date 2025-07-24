//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a function to generate random conspiracy theories
char* generate_conspiracy_theory() {
    
    // Create an array of conspiracy theories
    char* conspiracy_theories[] = {
        "The moon landing was faked by the government.",
        "Aliens are living among us in disguise.",
        "The Illuminati control the world's governments and economies.",
        "9/11 was an inside job orchestrated by the US government.",
        "COVID-19 is a hoax created by pharmaceutical companies to sell vaccines.",
        "The Loch Ness Monster is real but is being kept hidden by the government.",
        "The earth is flat and NASA is lying to us about its shape.",
        "The government is controlling the weather using advanced technology.",
        "The CIA killed JFK to prevent him from exposing deep government secrets.",
        "The music industry is controlled by the devil and is brainwashing our children."
    };
    
    // Choose a random conspiracy theory from the array
    int num_theories = sizeof(conspiracy_theories) / sizeof(conspiracy_theories[0]);
    int random_index = rand() % num_theories;
    
    return conspiracy_theories[random_index];
}

int main() {
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate and print a random conspiracy theory
    char* theory = generate_conspiracy_theory();
    printf("Did you know? %s\n", theory);
    
    return 0;
}