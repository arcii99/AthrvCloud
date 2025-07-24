//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(NULL));

    // Generate conspiracy theory
    char* theories[] = {"The moon landing was faked by the government!",
                        "Chemtrails are being used for mind control!",
                        "The Illuminati is controlling world governments!",
                        "The earth is flat and the globe is a lie!",
                        "Aliens are being kept in Area 51!",
                        "9/11 was an inside job!"};

    int theoryIndex = rand() % 6; // Get random index from theories array

    // Print retro-style output
    printf("**********************************************************************\n");
    printf("BREAKING NEWS: %s\n", theories[theoryIndex]);
    printf("**********************************************************************\n");
    printf("\n");

    // Generate more details to add to conspiracy theory
    char* evidence[] = {"Eyewitness accounts!",
                        "Top-secret documentation!",
                        "Whistleblower testimony!",
                        "Hidden camera footage!",
                        "Coded messages in popular media!",
                        "Symbols hidden in plain sight!"};

    char* motivations[] = {"To maintain power!",
                           "To manipulate the masses!",
                           "To advance a secret agenda!",
                           "To profit from human suffering!",
                           "To bring about the end of days!",
                           "To replace human beings with robots!"};

    char* consequences[] = {"The end of democracy!",
                            "The rise of a new world order!",
                            "The destruction of human civilization!",
                            "The subjugation of the human race!",
                            "The end of freedom as we know it!",
                            "The rise of the antichrist!"};

    int numberOfDetails = rand() % 3 + 1; // Get random number of details between 1 and 3

    // Print more retro-style output with details
    printf("Additional details:\n");
    for (int i = 0; i < numberOfDetails; i++) {
        int evidenceIndex = rand() % 6;
        int motivationsIndex = rand() % 6;
        int consequencesIndex = rand() % 6;

        printf("- %s\n", evidence[evidenceIndex]);
        printf("- %s\n", motivations[motivationsIndex]);
        printf("- %s\n", consequences[consequencesIndex]);
    }

    printf("\n");
    printf("**********************************************************************\n");
    printf("What do you think? Let us know in the comments below!\n");
    printf("**********************************************************************\n");

    return 0;
}