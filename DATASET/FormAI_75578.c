//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQ_LENGTH 100 // length of the genome sequence to be generated
#define A_PROBABILITY 0.25 // probability of nucleotide A
#define T_PROBABILITY 0.25 // probability of nucleotide T
#define C_PROBABILITY 0.25 // probability of nucleotide C
#define G_PROBABILITY 0.25 // probability of nucleotide G

// function to generate a random nucleotide based on probabilities
char generate_nucleotide() {
    double r = ((double) rand() / (RAND_MAX));
    if (r < A_PROBABILITY) {
        return 'A';
    } else if (r < A_PROBABILITY + T_PROBABILITY) {
        return 'T';
    } else if (r < A_PROBABILITY + T_PROBABILITY + C_PROBABILITY) {
        return 'C';
    } else {
        return 'G';
    }
}

int main() {
    srand((unsigned int) time(NULL)); // seed the random number generator with the current time
    
    // generate genome sequence
    char genome[SEQ_LENGTH];
    for (int i=0; i<SEQ_LENGTH; i++) {
        genome[i] = generate_nucleotide();
    }
    
    // calculate statistics
    int a_count = 0, t_count = 0, c_count = 0, g_count = 0;
    for (int i=0; i<SEQ_LENGTH; i++) {
        switch (genome[i]) {
            case 'A':
                a_count++;
                break;
            case 'T':
                t_count++;
                break;
            case 'C':
                c_count++;
                break;
            case 'G':
                g_count++;
                break;
            default:
                printf("Error: Invalid nucleotide found in genome\n");
                return 1;
        }
    }
    double a_probability = (double) a_count / SEQ_LENGTH;
    double t_probability = (double) t_count / SEQ_LENGTH;
    double c_probability = (double) c_count / SEQ_LENGTH;
    double g_probability = (double) g_count / SEQ_LENGTH;
    
    // print results
    printf("Generated genome sequence: ");
    for (int i=0; i<SEQ_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    printf("Nucleotide frequencies:\n");
    printf("A: %d (%.2f%%)\n", a_count, a_probability*100);
    printf("T: %d (%.2f%%)\n", t_count, t_probability*100);
    printf("C: %d (%.2f%%)\n", c_count, c_probability*100);
    printf("G: %d (%.2f%%)\n", g_count, g_probability*100);
    
    return 0;
}