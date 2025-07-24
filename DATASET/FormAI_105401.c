//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for randomization
    
    char* subjects[] = {
        "The King",
        "The Queen",
        "The Archbishop",
        "The Baron",
        "The Sorcerer",
        "The Blacksmith",
        "The Knight",
        "The Farmer",
        "The Witch",
        "The Jester"
    };
    int numSubjects = sizeof(subjects) / sizeof(char*); // number of subjects
    
    char* actions[] = {
        "is secretly",
        "is actually",
        "is planning on",
        "has been caught",
        "is working with",
        "is controlling",
        "is manipulating",
        "has conspired with",
        "has betrayed",
        "is colluding with"
    };
    int numActions = sizeof(actions) / sizeof(char*); // number of actions
    
    char* objects[] = {
        "the dragons",
        "the demons",
        "the bandits",
        "the rebel forces",
        "the neighboring kingdom",
        "the undead army",
        "the mysterious cult",
        "the dark wizards",
        "the evil spirits",
        "the supernatural creatures"
    };
    int numObjects = sizeof(objects) / sizeof(char*); // number of objects
    
    char* reasons[] = {
        "to overthrow the kingdom",
        "to gain ultimate power",
        "to seek revenge",
        "to summon a greater evil",
        "to obtain the ancient artifacts",
        "to control the magical energy",
        "to access the forbidden knowledge",
        "to erase their shameful past",
        "to restore their lost honor",
        "to fulfill a dark prophecy"
    };
    int numReasons = sizeof(reasons) / sizeof(char*); // number of reasons
    
    char* locations[] = {
        "the hidden chamber",
        "the abandoned castle",
        "the cursed forest",
        "the secret laboratory",
        "the forbidden temple",
        "the underwater abyss",
        "the celestial realm",
        "the dark dimension",
        "the vast desert",
        "the frozen wasteland"
    };
    int numLocations = sizeof(locations) / sizeof(char*); // number of locations
    
    int i;
    for (i = 0; i < 10; i++) { // generate 10 random theories
        int subjectIndex = rand() % numSubjects; // choose a random subject
        int actionIndex = rand() % numActions; // choose a random action
        int objectIndex = rand() % numObjects; // choose a random object
        int reasonIndex = rand() % numReasons; // choose a random reason
        int locationIndex = rand() % numLocations; // choose a random location
        
        printf("%s %s %s %s in %s.\n", subjects[subjectIndex], actions[actionIndex], objects[objectIndex], reasons[reasonIndex], locations[locationIndex]);
    }
    
    return 0;
}