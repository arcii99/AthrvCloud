//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 1000000 // Maximum length of genome
#define BASES "ATCG" // Possible nucleotides

int main() {
    char genome[MAX];
    int i, j, k;

    srand(time(NULL)); // Set seed for random function

    // Randomly generate genome sequence
    for(i = 0; i < MAX; i++) {
        genome[i] = BASES[rand() % 4];
    }

    // Print 100 nucleotides per line
    for(i = 0; i < MAX; i += 100) {
        for(j = i; j < i + 100 && j < MAX; j++) {
            printf("%c", genome[j]);
        }
        printf("\n");
    }

    // Find and print all possible sub-sequences of length 5
    printf("All possible sub-sequences of length 5:\n");
    for(i = 0; i < MAX - 4; i++) {
        for(j = i; j < i + 5; j++) {
            printf("%c", genome[j]);
        }
        printf("\n");
    }

    // Find and print all unique sub-sequences of length 10
    printf("All unique sub-sequences of length 10:\n");
    for(i = 0; i < MAX - 9; i++) {
        char subseq[11] = ""; // Initialize empty sub-sequence
        for(j = i; j < i + 10; j++) {
            subseq[j-i] = genome[j];
        }
        // Check if sub-sequence already exists
        int exists = 0;
        for(k = 0; k < i; k++) {
            if(strcmp(subseq, &genome[k]) == 0) {
                exists = 1;
                break;
            }
        }
        if(!exists) {
            printf("%s\n", subseq);
        }
    }

    return 0;
}