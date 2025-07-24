//FormAI DATASET v1.0 Category: Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLUES 5
#define MAX_SUSPECTS 5

typedef struct {
    char name[20];
    int clue_count;
    char clues[MAX_CLUES][100];
} suspect;

typedef struct {
    char description[100];
    int priority;
} clue;

suspect suspects[MAX_SUSPECTS];
clue all_clues[MAX_CLUES+1] = {
    {"Footprints going towards the crime scene", 1},
    {"Bloody knife found at the crime scene", 2},
    {"Hair strands found at the crime scene", 3},
    {"A witness saw a suspicious looking individual near the crime scene", 4},
    {"A note found in the victim's pocket", 5}
};

// function to generate a random number between min and max 
int rand_range(int min, int max) {
    int range = max - min + 1;
    return rand() % range + min;
}

// initialize suspects 
void initialize_suspects() {
    strcpy(suspects[0].name, "John");
    suspects[0].clue_count = 3;
    strcpy(suspects[0].clues[0], "I was at home watching TV when the crime happened.");
    strcpy(suspects[0].clues[1], "I have no idea who could have done this.");
    strcpy(suspects[0].clues[2], "I don't have any connection to the victim.");

    strcpy(suspects[1].name, "Mary");
    suspects[1].clue_count = 2;
    strcpy(suspects[1].clues[0], "I was out shopping at the time of the crime.");
    strcpy(suspects[1].clues[1], "I heard some screaming coming from the alley but didn't investigate.");

    strcpy(suspects[2].name, "James");
    suspects[2].clue_count = 4;
    strcpy(suspects[2].clues[0], "I was walking my dog near the crime scene.");
    strcpy(suspects[2].clues[1], "I didn't see anyone around the crime scene.");
    strcpy(suspects[2].clues[2], "I have no idea how a knife could have gotten into my pocket.");
    strcpy(suspects[2].clues[3], "I don't know the victim personally.");

    strcpy(suspects[3].name, "Sarah");
    suspects[3].clue_count = 1;
    strcpy(suspects[3].clues[0], "I don't want to get involved in this.");

    strcpy(suspects[4].name, "Michael");
    suspects[4].clue_count = 0;
}

int main() {
    srand(time(0)); // seed random number generator
    initialize_suspects();

    printf("Welcome to the crime investigation!\n");
    printf("You have the following clues to start with:\n");
    for(int i=0; i<MAX_CLUES; i++) {
        printf("%d. %s\n", i+1, all_clues[i].description);
    }

    int remaining_clues = MAX_CLUES;
    int remaining_suspects = MAX_SUSPECTS;

    while(remaining_clues > 0 && remaining_suspects > 0) {
        int clue_index = rand_range(0, remaining_clues-1);
        clue current_clue = all_clues[clue_index];
        printf("\nYou have found a new clue: %s\n", current_clue.description);
        for(int i=0; i<MAX_SUSPECTS; i++) {
            if(suspects[i].clue_count == MAX_CLUES)
                continue;
            if(strstr(suspects[i].name, "Mr.") == NULL) {
                // add clue to this suspect
                strcpy(suspects[i].clues[suspects[i].clue_count], current_clue.description);
                suspects[i].clue_count++;
            }
        }
        remaining_clues--;
        printf("You have %d clues remaining.\n", remaining_clues);

        int suspect_index = rand_range(0, remaining_suspects-1);
        suspect current_suspect = suspects[suspect_index];
        char question[100];
        printf("\nYou are interviewing %s. What is your question? ", current_suspect.name);
        fgets(question, sizeof(question), stdin);
        printf("Their answer is: %s\n", current_suspect.clues[rand_range(0, current_suspect.clue_count-1)]);

        if(current_suspect.clue_count == MAX_CLUES) {
            printf("You have solved the case! The culprit is %s.\n", current_suspect.name);
            return 0;
        } else {
            printf("You still have %d suspects remaining to interview.\n", remaining_suspects-1);
            for(int i=suspect_index; i<remaining_suspects-1; i++) {
                suspects[i] = suspects[i+1];
            }
            remaining_suspects--;
        }
    }

    printf("You have not found enough clues to solve the case. Try again!\n");
    return 0;
}