//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    char genome[51] = "";
    
    int i;
    for(i = 0; i < 50; i++) {
        int base = rand() % 4 + 1;
        
        if(base == 1) {
            genome[i] = 'A';
        } else if(base == 2) {
            genome[i] = 'C';
        } else if(base == 3) {
            genome[i] = 'G';
        } else {
            genome[i] = 'T';
        }
    }
    
    genome[50] = '\0';
    
    printf("Welcome to the Surrealist Genome Sequencing Simulator!\n");
    printf("We have generated a completely random genome for you to analyze:\n\n%s\n", genome);
    printf("Please note that this genome may or may not have any actual meaning in the real world...\n");
    
    int num_A = 0;
    int num_C = 0;
    int num_G = 0;
    int num_T = 0;
    
    for(i = 0; i < 50; i++) {
        if(genome[i] == 'A') {
            num_A++;
        } else if(genome[i] == 'C') {
            num_C++;
        } else if(genome[i] == 'G') {
            num_G++;
        } else {
            num_T++;
        }
    }
    
    printf("\nHere are the base counts for this genome:\n");
    printf("A: %d\n", num_A);
    printf("C: %d\n", num_C);
    printf("G: %d\n", num_G);
    printf("T: %d\n", num_T);
    
    printf("\nThank you for using the Surrealist Genome Sequencing Simulator! We hope you enjoyed your experience.\n");
    
    return 0;
}