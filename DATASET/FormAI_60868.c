//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* conspiracies[10] = {"The government is hiding evidence of extraterrestrial life.",
                              "Vaccines are part of a larger plan for mind control.",
                              "The moon landing was faked to make the US seem more powerful.",
                              "The Illuminati controls the world's governments.",
                              "The earth is actually flat and every space organization is lying to us.",
                              "The Titanic was sunk on purpose to kill off some of the world's wealthiest people.",
                              "911 was an inside job orchestrated by the US government.",
                              "Chemtrails are being used to poison the population and control the weather.",
                              "The Denver airport is hiding a secret underground bunker for the wealthy elite.",
                              "The Loch Ness Monster is real and is being kept secret by the Scottish government."};
                              
    char* government_agencies[5] = {"FBI", "CIA", "NSA", "Homeland Security", "Department of Defense"};
    char* actions[5] = {"is watching", "is monitoring", "is controlling", "is manipulating", "is brainwashing"};
    
    int conspiracy_num = rand() % 10;
    int agency_num = rand() % 5;
    int action_num = rand() % 5;

    printf("Did you know that %s?\n", conspiracies[conspiracy_num]);
    printf("And do you know who is responsible for this cover-up?\n");
    printf("It's the %s, don't be fooled. They %s everything.\n", government_agencies[agency_num], actions[action_num]);
    
    return 0;
}