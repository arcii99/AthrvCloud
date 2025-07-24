//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Number of base pairs

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    char bases[N]; // Array to store the sequence
    int i;
    
    // Generate a random sequence
    for(i = 0; i < N; i++) {
        int r = rand() % 4; // Generate a random number between 0 and 3
        if(r == 0) {
            bases[i] = 'A';
        } else if(r == 1) {
            bases[i] = 'C';
        } else if(r == 2) {
            bases[i] = 'G';
        } else {
            bases[i] = 'T';
        }
    }
    
    // Print the sequence
    printf("Sequence:\n");
    for(i = 0; i < N; i++) {
        printf("%c", bases[i]);
        if((i + 1) % 10 == 0) { // Print a new line every 10 base pairs
            printf("\n");
        }
    }
    printf("\n");
    
    // Simulate sequencing by adding errors
    char reads[N][3]; // Array to store the reads
    int j, k;
    int errors[N][3]; // Array to store the number of errors in each read
    for(i = 0; i < N; i++) {
        for(j = 0; j < 3; j++) {
            int r = rand() % 100; // Generate a random number between 0 and 99
            if(r < 10) { // 10% chance of an error
                // Generate a random base that is different from the original base
                char error_base;
                do {
                    int error = rand() % 4;
                    if(error == 0) {
                        error_base = 'A';
                    } else if(error == 1) {
                        error_base = 'C';
                    } else if(error == 2) {
                        error_base = 'G';
                    } else {
                        error_base = 'T';
                    }
                } while(error_base == bases[i]);
                
                reads[i][j] = error_base;
                errors[i][j] = 1;
            } else {
                reads[i][j] = bases[i];
                errors[i][j] = 0;
            }
        }
    }
    
    // Print the reads and the number of errors in each read
    printf("Reads:\n");
    for(k = 0; k < 3; k++) {
        printf("Read %d:\n", k + 1);
        for(i = 0; i < N; i++) {
            printf("%c", reads[i][k]);
            if((i + 1) % 10 == 0) { // Print a new line every 10 base pairs
                printf("\n");
            }
        }
        printf("\n");
        
        printf("Errors:\n");
        for(i = 0; i < N; i++) {
            printf("%d", errors[i][k]);
            if((i + 1) % 10 == 0) { // Print a new line every 10 base pairs
                printf("\n");
            }
        }
        printf("\n");
    }
    
    return 0;
}