//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_CHROMOSOME_LENGTH 10000

int get_rand_base(){
    int num_bases = 4;
    int base = rand() % num_bases;
    switch(base){
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
        default: return 'N';
    }
}

void generate_random_genome(char* genome, int length){
    for(int i = 0; i < length; i++){
        genome[i] = get_rand_base();
    }
}

int rand_int(int low, int high){
    return rand() % (high - low + 1) + low;
}

void insert_mutation(char* genome, int length, double mutation_rate){
    for(int i = 0; i < length; i++){
        double rand_num = (double)rand() / RAND_MAX;
        if(rand_num < mutation_rate){
            int new_base = get_rand_base();
            genome[i] = new_base;
        }
    }
}

void print_fasta_format(char* genome, int length){
    printf(">Genome\n");
    for(int i = 0; i < length; i++){
        printf("%c", genome[i]);
        if((i+1) % 70 == 0 || i == length - 1) printf("\n");
    }
}

void print_statistics(char* genome, int length){
    int num_A = 0, num_C = 0, num_G = 0, num_T = 0, num_N = 0;
    for(int i = 0; i < length; i++){
        switch(genome[i]){
            case 'A': num_A++; break;
            case 'C': num_C++; break;
            case 'G': num_G++; break;
            case 'T': num_T++; break;
            default: num_N++; break;
        }
    }
    printf("Statistics\n");
    printf("Num A's: %d\n", num_A);
    printf("Num C's: %d\n", num_C);
    printf("Num G's: %d\n", num_G);
    printf("Num T's: %d\n", num_T);
    printf("Num N's: %d\n", num_N);
    printf("Total Length: %d\n", length);
}

int main(){
    srand(time(NULL));
    char genome[MAX_CHROMOSOME_LENGTH] = {'\0'};
    int genome_length = rand_int(5000, MAX_CHROMOSOME_LENGTH);

    // Step 1: Generate Random Genome
    generate_random_genome(genome, genome_length);

    // Step 2: Insert mutations
    double mutation_rate = 0.01;
    insert_mutation(genome, genome_length, mutation_rate);

    // Step 3: Print Genome
    print_fasta_format(genome, genome_length);

    // Step 4: Print Statistics
    print_statistics(genome, genome_length);

    return 0;
}