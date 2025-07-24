//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 1000

char nucleotides[] = {'A','C','G','T'};

void generate_random_genome(char genome[]) {
    /* Function to generate a random genome with length GENOME_SIZE */
    int i;
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = nucleotides[rand() % 4];
    }
    genome[i] = '\0';
}

void print_genome(char genome[]) {
    /* Function to print a genome to the console */
    printf("%s\n", genome);
}

int find_subsequence(char genome[], char subsequence[]) {
    /* Function to find a subsequence in a genome */
    int i,j,k;
    for(i=0;i<strlen(genome)-strlen(subsequence);i++){
        k=i;
        for(j=0;j<strlen(subsequence);j++){
            if(genome[k]==subsequence[j]){
                k++;
            }
            else{
                break;
            }
        }
        if(j==strlen(subsequence)){
            return i;
        }
    }
    return -1;
}

void generate_mutations(char genome[], int num_mutations) {
    /* Function to generate mutations in a genome */
    srand(time(NULL));
    int i;
    for (i = 0; i < num_mutations; i++) {
        int random_index = rand() % GENOME_SIZE;
        genome[random_index] = nucleotides[rand() % 4];
    }
}

int main() {
    char genome[GENOME_SIZE+1];
    generate_random_genome(genome);
    print_genome(genome);
    char subsequence[] = "GATTACA";
    int index = find_subsequence(genome, subsequence);
    if (index != -1) {
        printf("Found subsequence at index %d\n", index);
    } else {
        printf("Subsequence not found\n");
    }
    int num_mutations = 10;
    generate_mutations(genome, num_mutations);
    print_genome(genome);
    return 0;
}