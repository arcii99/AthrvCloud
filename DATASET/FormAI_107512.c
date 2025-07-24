//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char* conspiracies[] = {"The moon landing was faked!", "The government is controlling our minds with chemtrails!", "The Earth is flat and NASA is lying to us!"};
    char* locations[] = {"Area 51", "the Bermuda Triangle", "the Denver International Airport"};
    char* entities[] = {"the Illuminati", "the New World Order", "the lizard people"};
    char* actions[] = {"are using HAARP to control the weather.", "are putting fluoride in our water to pacify us.", "are planning a global depopulation event."};
    
    srand(time(NULL));
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    
    printf("Press enter to generate a conspiracy theory...\n");
    getchar();
    
    // Generate random indices for the different arrays
    int conspiracy_index = rand() % 3;
    int location_index = rand() % 3;
    int entity_index = rand() % 3;
    int action_index = rand() % 3;
    
    // Combine the selected strings into a full conspiracy theory
    char conspiracy[100];
    strcpy(conspiracy, conspiracies[conspiracy_index]);
    strcat(conspiracy, " ");
    strcat(conspiracy, "Taking place in ");
    strcat(conspiracy, locations[location_index]);
    strcat(conspiracy, ", ");
    strcat(conspiracy, entities[entity_index]);
    strcat(conspiracy, " ");
    strcat(conspiracy, actions[action_index]);
    
    printf("Here's your conspiracy theory:\n\n");
    printf("%s\n", conspiracy);
    
    return 0;
}