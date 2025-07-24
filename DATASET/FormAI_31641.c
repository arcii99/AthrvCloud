//FormAI DATASET v1.0 Category: Computer Biology ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("What do you want me to do?! I'm just a computer program!\n");
    printf("Fine, fine. Let's do some biology...\n");
    printf("We'll simulate the genetic mutation of a population of organisms.\n");
    printf("Let's start by creating a population of 1000 organisms...\n");
  
    int population = 1000;
    int genes[population][100];

    // Generate initial genes for the population
    for (int i = 0; i < population; i++) {
        for (int j = 0; j < 100; j++) {
            // Randomly assign gene values of 0 or 1
            genes[i][j] = rand() % 2;
        }
    }

    printf("Great, we've generated their initial genetic makeup...\n");
    printf("But wait, it's time for a mutation!\n");
    printf("Let's start mutating...\n");
    
    // Mutate genes of each organism
    for (int i = 0; i < population; i++) {
        for (int j = 0; j < 100; j++) {
            // Randomly mutate a gene with a 1% probability
            if (rand() % 100 == 0) {
                genes[i][j] = rand() % 2;
            }
        }
    }
    
    printf("Wow, that was quite a mutation!\n");
    printf("Let's see how the genes changed...\n");

    // Print mutated genes
    for (int i = 0; i < population; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%d ", genes[i][j]);
        }
        printf("\n");
    }
    
    printf("Phew, that was some intense biology.\n");
    printf("I'm glad that's over!\n");

    return 0;
}