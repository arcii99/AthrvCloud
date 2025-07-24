//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_SIZE 1000

int main(void) {
    srand(time(NULL));
    
    char nucleotides[4] = {'A', 'C', 'G', 'T'};
    char sequence[SEQUENCE_SIZE];
    
    int i;
    
    printf("Welcome to the Genome Sequencing Simulator 2.0 - Surrealist Edition!\n\n");
    printf("Press any key to start sequencing...\n");
    getchar();
    
    printf("Sequencing in progress...\n");
    
    for (i = 0; i < SEQUENCE_SIZE; i++) {
        
        int random_index = rand() % 4;
        sequence[i] = nucleotides[random_index];
    }
    
    printf("\nSequencing complete. Here is your unique genome sequence:\n\n");
    
    for (i = 0; i < SEQUENCE_SIZE; i++) {
        
        printf("%c", sequence[i]);
        
        if (i % 10 == 9) {
            printf(" ");
        }
        if (i % 50 == 49) {
            printf("\n");
        }
        if (i % 100 == 99) {
            printf("\n\n");
        }
        if (i % 200 == 199) {
            printf("\n");
        }
    }

    printf("\n\nThank you for using the Genome Sequencing Simulator 2.0 - Surrealist Edition.\n");
    
    return 0;
}