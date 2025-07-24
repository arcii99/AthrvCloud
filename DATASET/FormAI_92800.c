//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define arrays of conspiracy theories
    char *theories[] = {
        "The moon landing was faked by the government.",
        "Chemtrails are being used to control our minds.",
        "The earth is flat and NASA is lying to us.",
        "The Illuminati is controlling world affairs.",
        "9/11 was an inside job."
    };

    char *evidence[] = {
        "There are no stars in the moon landing photos.",
        "The government has been spraying chemicals from planes for years.",
        "The horizon always appears flat, even at high altitudes.",
        "Many world leaders are known to be part of the Illuminati.",
        "The buildings collapsed in a controlled demolition pattern."
    };

    char *suspects[] = {
        "The government",
        "The Illuminati",
        "The New World Order",
        "Aliens"
    };

    // Generate a random theory, evidence, and suspect
    int theory_index = rand() % 5;
    int evidence_index = rand() % 5;
    int suspect_index = rand() % 4;

    // Print the random conspiracy theory
    printf("Did you know that %s? ", theories[theory_index]);

    // Print the evidence for the conspiracy theory
    printf("%s ", evidence[evidence_index]);

    // Print the suspect of the conspiracy theory
    printf("This is all part of a plan by %s!", suspects[suspect_index]);

    return 0;
}