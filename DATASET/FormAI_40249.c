//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int nucleotide;
    int strand;
} DNA;

int main(){
    srand(time(NULL));
    int length = rand() % 100 + 1; // Generate DNA sequence length between 1 to 100
    DNA dna[length];

    // Initializing random nucleotides and strands in the DNA sequence
    for(int i = 0; i < length; i++){
        dna[i].nucleotide = rand() % 4; // 0 = A, 1 = C, 2 = G, 3 = T
        dna[i].strand = rand() % 2; // 0 = positive strand, 1 = negative strand
    }

    // Printing the generated DNA sequence
    printf("Generated DNA sequence:\n");
    for(int i = 0; i < length; i++){
        printf("%c", dna[i].nucleotide == 0 ? 'A' : dna[i].nucleotide == 1 ? 'C' : dna[i].nucleotide == 2 ? 'G' : 'T');
    }
    printf("\n");

    // Decentralized genome sequencing simulation
    printf("\nDecentralized genome sequencing:\n");

    int chunks = rand() % length + 1; // Randomly generate number of chunks to divide the DNA sequence into
    int chunkSize = length / chunks; // Calculate chunk size
    int remaining = length % chunks; // Calculate remaining DNA nucleotides after dividing the sequence into chunks

    for(int i = 0; i < chunks; i++){
        int chunkStart = i * chunkSize; // Calculate the starting index of the chunk
        int chunkEnd = chunkStart + chunkSize - 1; // Calculate the ending index of the chunk

        if(i == chunks - 1){ // If this is the last chunk, include the remaining nucleotides
            chunkEnd += remaining;
        }

        printf("Worker %d is sequencing nucleotides %d to %d\n", i+1, chunkStart+1, chunkEnd+1);

        // Simulated sequencing process
        for(int j = chunkStart; j <= chunkEnd; j++){
            if(dna[j].nucleotide == 0){ // A -> T on negative strand
                if(dna[j].strand == 1){
                    dna[j].nucleotide = 3;
                }
            }

            else if(dna[j].nucleotide == 1){ // C -> G on positive strand
                if(dna[j].strand == 0){
                    dna[j].nucleotide = 2;
                }
            }

            else if(dna[j].nucleotide == 2){ // G -> C on negative strand
                if(dna[j].strand == 1){
                    dna[j].nucleotide = 1;
                }
            }

            else if(dna[j].nucleotide == 3){ // T -> A on positive strand
                if(dna[j].strand == 0){
                    dna[j].nucleotide = 0;
                }
            }
        }
    }

    // Printing the assembled DNA sequence
    printf("\nAssembled DNA sequence:\n");
    for(int i = 0; i < length; i++){
        printf("%c", dna[i].nucleotide == 0 ? 'A' : dna[i].nucleotide == 1 ? 'C' : dna[i].nucleotide == 2 ? 'G' : 'T');
    }
    printf("\n");

    return 0;
}