//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    // the genome is represented as an array of integers
    int genome[10];
    
    // randomly generate the genome sequence
    for(int i = 0; i < 10; i++) {
        genome[i] = rand() % 4; // each element can be one of four letters (A, C, G, or T)
    }
    
    // print out the genome sequence
    printf("GENOME SEQUENCE:\n");
    for(int i = 0; i < 10; i++) {
        switch(genome[i]) {
            case 0:
                printf("A ");
                break;
            case 1:
                printf("C ");
                break;
            case 2:
                printf("G ");
                break;
            case 3:
                printf("T ");
                break;
        }
    }
    printf("\n\n");
    
    // randomly simulate mutations
    int num_mutations = rand() % 3 + 1; // generate between 1 and 3 mutations
    for(int i = 0; i < num_mutations; i++) {
        int index = rand() % 10; // randomly choose a position to mutate
        int prev = genome[index]; // store the previous value (will be used in the switch statement)
        genome[index] = rand() % 4; // randomly choose a new value for that position
        
        // print out the mutated genome sequence
        printf("MUTATION #%d:\n", i+1);
        for(int j = 0; j < 10; j++) {
            if(j == index) {
                // highlight the position that was mutated
                switch(prev) {
                    case 0:
                        printf("\033[1;31mA\033[0m ");
                        break;
                    case 1:
                        printf("\033[1;31mC\033[0m ");
                        break;
                    case 2:
                        printf("\033[1;31mG\033[0m ");
                        break;
                    case 3:
                        printf("\033[1;31mT\033[0m ");
                        break;
                }
            } else {
                switch(genome[j]) {
                    case 0:
                        printf("A ");
                        break;
                    case 1:
                        printf("C ");
                        break;
                    case 2:
                        printf("G ");
                        break;
                    case 3:
                        printf("T ");
                        break;
                }
            }
        }
        printf("\n\n");
    }
    
    return 0;
}