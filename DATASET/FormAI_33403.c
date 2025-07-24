//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // set seed for random number generator 
    int sequence_length = 100; // length of genetic sequence to be generated 
    char sequence[sequence_length]; // array to store genetic sequence 
    int i;

    printf("Generating genetic sequence...\n");

    for (int i = 0; i < sequence_length; i++) {
        int random_number = rand() % 4; // generate random number between 0 and 3 (inclusive)
        char base;
        switch (random_number) {
            case 0:
                base = 'A';
                break;
            case 1:
                base = 'C';
                break;
            case 2:
                base = 'G';
                break;
            case 3:
                base = 'T';
                break;
        }
        sequence[i] = base;
    }

    printf("Genetic sequence generated: %s", sequence);
    
    return 0;
}