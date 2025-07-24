//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100000
#define C_LEN 200

int main(){
    char genome[GENOME_LENGTH];
    char c[C_LEN] = {0};

    // Randomly generate genome sequence
    srand(time(NULL));
    for(int i=0; i<GENOME_LENGTH; i++){
        int r = rand() % 4;
        switch(r){
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
        }
    }

    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Your task is to find and isolate the sequence 'CTGGCAAT' from the genome.\n");

    // Medieval-style simulation of genome sequencing
    int i = 0;
    while(i < GENOME_LENGTH - C_LEN + 1){
        int j = 0;
        while(j < C_LEN){
            printf("Reading character '%c'...\n", genome[i+j]);
            if(genome[i+j] != c[j]){
                printf("No match! Moving on to next sequence...\n\n");
                i++;
                break;
            }
            j++;
        }
        if(j == C_LEN){
            printf("\n\nHail, noble scientist! Thou hast found the sequence 'CTGGCAAT'!\n");
            break;
        }
    }

    printf("\n\nThanks for using the Genome Sequencing Simulator. Have a nice day!\n");

    return 0;
}