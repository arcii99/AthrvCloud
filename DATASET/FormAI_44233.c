//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASES "ATCG"

int main(void) {
    srand(time(NULL));
    char genome[100];
    
    for (int i = 0; i < 100; i++) {
        genome[i] = BASES[rand() % 4];
    }
    printf("Original Genome: %s\n\n", genome);
    
    // Simulate Insertion
    int insertPos = rand() % (100 - 20 + 1) + 20;
    int insertSize = rand() % 10 + 1;
    char insert[insertSize];
    for (int i = 0; i < insertSize; i++) {
        insert[i] = BASES[rand() % 4];
    }
    printf("***Performing Insertion at Position %d with %d bp***\n", insertPos, insertSize);
    for (int i = 99; i >= insertPos; i--) {
        genome[i + insertSize] = genome[i];
    }
    for (int i = 0; i < insertSize; i++) {
        genome[insertPos + i] = insert[i];
    }
    printf("New Genome with Insertion: %s\n\n", genome);
    
    // Simulate Deletion
    int deletePos = rand() % (100 - 20 + 1) + 20;
    int deleteSize = rand() % 10 + 1;
    printf("***Performing Deletion at Position %d with %d bp***\n", deletePos, deleteSize);
    for (int i = deletePos + deleteSize; i < 100; i++) {
        genome[i - deleteSize] = genome[i];
    }
    printf("New Genome with Deletion: %s\n\n", genome);
    
    return 0;
}