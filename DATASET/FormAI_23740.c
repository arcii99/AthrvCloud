//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASES "ACGT"

int main(){
    srand(time(NULL)); // initializes random seed with current time
    
    // generate a random DNA sequence of length 50
    char dna[51]; // leave one extra space for null character
    int i;
    for(i=0; i<50; i++){
        dna[i] = BASES[rand()%4]; // pick a random base from A, C, G, T
    }
    dna[50] = '\0'; // add null character at the end
    
    printf("Generated DNA sequence: %s\n", dna);
    
    // simulate genome sequencing by introducing errors and obtaining reads
    int num_reads = 10;
    int read_len = 10;
    
    char reads[num_reads][read_len+1]; // leave extra space for null character
    for(i=0; i<num_reads; i++){
        int start_pos = rand()%(50-read_len+1); // pick a random starting position within the DNA sequence
        int j;
        for(j=0; j<read_len; j++){
            if(rand()%10 == 0){ // introduce an error with 10% probability
                reads[i][j] = BASES[rand()%3 + (dna[start_pos+j]-'A'+1)%4]; // pick a random base that is not the original base
            } else {
                reads[i][j] = dna[start_pos+j];
            }
        }
        reads[i][read_len] = '\0'; // add null character at the end
    }
    
    printf("\nSimulated sequencing reads:\n");
    for(i=0; i<num_reads; i++){
        printf("%d: %s\n", i+1, reads[i]);
    }
    
    return 0;
}