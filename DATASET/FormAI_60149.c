//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *nouns[] = {"aliens", "illuminati", "government", "big pharma", "zombies", "ghosts", "vampires", "robots", "time travelers", "elves", "unicorns", "dragons", "butterflies"};
char *adjectives[] = {"conspiring", "manipulating", "controlling", "brainwashing", "infiltrating", "spying on", "experimenting on", "mind-reading", "shape-shifting"};

int main() {
    srand(time(NULL)); // seed the random generator
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Here is your new theory:\n");

    // Generate random nouns and adjectives
    int noun_index = rand() % 13;
    int adj_index = rand() % 9;
    printf("%s are %s\n", nouns[noun_index], adjectives[adj_index]);

    // Generate random sub-theories
    int num_sub_theories = rand() % 5 + 3;
    printf("Sub-theories:\n");
    for (int i = 0; i < num_sub_theories; i++) {
        int sub_noun_index = rand() % 13;
        int sub_adj_index = rand() % 9;
        printf("%d) %s are secretly %s %s\n", i+1, nouns[noun_index], adjectives[sub_adj_index], nouns[sub_noun_index]);
    }

    // Generate random evidence
    int num_evidence = rand() % 6 + 3;
    printf("Evidence:\n");
    for (int i = 0; i < num_evidence; i++) {
        int evidence_index = rand() % 5;
        switch (evidence_index) {
            case 0:
                printf("- There are no photos of %s\n", nouns[noun_index]);
                break;
            case 1:
                printf("- %s %s always appear when %s happens\n", adjectives[adj_index], nouns[noun_index], nouns[(noun_index+1)%13]);
                break;
            case 2:
                printf("- The government denies the existence of %s, which is proof that they are real\n", nouns[noun_index]);
                break;
            case 3:
                printf("- There are hidden messages about %s in popular media\n", nouns[noun_index]);
                break;
            case 4:
                printf("- %s sightings have increased in recent years, indicating a %s takeover\n", nouns[noun_index], nouns[(noun_index+1)%13]);
                break;
        }
    }

    printf("The truth is out there!\n");
    return 0;
}