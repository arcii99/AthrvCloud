//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char* theories[] = {
        "The government created the apocalypse to thin the population", 
        "The survivors are actually living in a simulation", 
        "The aliens caused the apocalypse to prepare Earth for invasion",
        "The apocalypse was actually a mass extinction event caused by a rogue meteor",
        "The government purposely destroyed the world to reset and start anew",
        "The apocalypse was caused by a group of shadowy elites who wanted to consolidate power"
    };
    int num_theories = 6; // number of possible theories

    printf("Welcome to the Random Conspiracy Theory Generator\n\n");

    printf("Generating random theory...\n\n");
    int index = rand() % num_theories; // generate random index
    printf("Theory: %s\n\n", theories[index]);
    
    return 0;
}