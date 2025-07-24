//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int geneLength = 1000;
    char genes[geneLength];
    srand(time(NULL));
    
    printf("Simulating genome sequencing...\n");
    printf("Generating random genes...\n");
    
    // Generate random genes
    for (int i = 0; i < geneLength; i++) {
        int randNum = rand() % 4;
        
        if (randNum == 0) {
            genes[i] = 'A';
        } else if (randNum == 1) {
            genes[i] = 'C';
        } else if (randNum == 2) {
            genes[i] = 'G';
        } else {
            genes[i] = 'T';
        }
    }
    
    printf("Done generating random genes.\n\n");
    
    printf("Sequencing the genes...\n");
    
    // Simulate sequencing
    int errorRate = 10; // 10% error rate
    int numErrors = 0;
    char read[geneLength/5];
    int readIndex = 0;
    
    for (int i = 0; i < geneLength; i++) {
        int randNum = rand() % 100;
        
        if (randNum < errorRate) {
            // Generate error
            numErrors++;
            int randNum2 = rand() % 3;
            
            if (randNum2 == 0) {
                read[readIndex] = 'A';
            } else if (randNum2 == 1) {
                read[readIndex] = 'C';
            } else if (randNum2 == 2) {
                read[readIndex] = 'G';
            } else {
                read[readIndex] = 'T';
            }
        } else {
            // No error
            read[readIndex] = genes[i];
        }
        
        readIndex++;
        
        if (readIndex == geneLength/5) {
            // Done with one read
            printf("Read %d: ", readIndex);
            for (int j = 0; j < readIndex; j++) {
                printf("%c", read[j]);
            }
            printf("\n\n");
            readIndex = 0;
        }
    }
    
    printf("Done sequencing.\n\n");
    
    printf("Number of errors: %d\n", numErrors);
    
    return 0;
}