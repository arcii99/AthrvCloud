//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_SIZE 100

char generate_random_base() {
    char bases[] = {'A', 'C', 'G', 'T'};
    int random_index = rand() % 4;
    return bases[random_index];
}

void generate_random_genome(char *genome) {
    for (int i = 0; i < MAX_GENOME_SIZE; i++) {
        genome[i] = generate_random_base();
    }
}

void print_genome(char *genome) {
    for (int i = 0; i < MAX_GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
}

int count_base(char *genome, char base) {
    int count = 0;
    for (int i = 0; i < MAX_GENOME_SIZE; i++) {
        if (genome[i] == base) {
            count++;
        }
    }
    return count;
}

void simulate_genome_sequencing() {
    char genome[MAX_GENOME_SIZE];
    generate_random_genome(genome);
    
    printf("Original genome: ");
    print_genome(genome);
    printf("\n");
    
    int read_length = 10;
    int num_reads = MAX_GENOME_SIZE / read_length;
    char reads[num_reads][read_length + 1];
    
    for (int i = 0; i < num_reads; i++) {
        for (int j = 0; j < read_length; j++) {
            reads[i][j] = genome[i * read_length + j];
        }
        reads[i][read_length] = '\0';
    }
    
    printf("Number of reads: %d\n", num_reads);
    
    char bases[] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < 4; i++) {
        int count = count_base(genome, bases[i]);
        printf("%c count in genome: %d\n", bases[i], count);
        
        int total_count = 0;
        for (int j = 0; j < num_reads; j++) {
            int read_count = count_base(reads[j], bases[i]);
            total_count += read_count;
        }
        printf("%c count in reads: %d\n", bases[i], total_count);
    }
}

int main() {
    srand(time(0));
    simulate_genome_sequencing();
    return 0;
}