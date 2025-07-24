//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed for rand()

    // Conspiracy theories
    char *conspiracies[] = {
        "The moon landing was faked by the government.",
        "The Illuminati control the world's governments.",
        "Chemtrails are being sprayed by airplanes to poison the population.",
        "The government is hiding evidence of alien life from the public.",
        "9/11 was an inside job orchestrated by the government.",
        "The world is controlled by a secret cabal of bankers.",
        "The Holocaust never happened and is a fabrication.",
        "The government is hiding the cure for cancer to maintain profits.",
        "The food and water supply is being poisoned to control the population.",
        "The media is controlled by a small group of elites to manipulate public opinion."
    };

    // Generate random conspiracy theory
    int index = rand() % 10;
    printf("Did you know that %s\n", conspiracies[index]);

    return 0; // Success!
}