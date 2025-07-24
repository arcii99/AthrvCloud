//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>

#define MAX_LEN 100  // maximum length of genome sequence

int main() {
    char nucleotides[] = "ACGT";  // possible nucleotides in DNA
    int probabilities[] = {25, 25, 25, 25};  // probability of occurrence of each nucleotide
    char genome_seq[MAX_LEN];  // array to store genome sequence
    
    int seq_length;
    printf("Enter the length of the genome sequence you want to generate (max %d): ", MAX_LEN);
    scanf("%d", &seq_length);
    
    // generate genome sequence
    for(int i = 0; i < seq_length; i++) {
        // randomly select a nucleotide based on probabilities
        int rand_num = rand() % 100;  // generate a random number between 0 and 99
        if(rand_num < probabilities[0]) {
            genome_seq[i] = nucleotides[0];
        } else if(rand_num < probabilities[0] + probabilities[1]) {
            genome_seq[i] = nucleotides[1];
        } else if(rand_num < probabilities[0] + probabilities[1] + probabilities[2]) {
            genome_seq[i] = nucleotides[2];
        } else {
            genome_seq[i] = nucleotides[3];
        }
    }
    
    // print the generated genome sequence
    printf("Generated genome sequence: %s\n", genome_seq);
    
    return 0;
}