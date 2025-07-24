//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define GENOME_SIZE 1000

typedef struct gene_node{
    char base;
    int position;
    struct gene_node* next;
} gene_node_t;

uint32_t crc_table[256] = {0};
uint32_t crc_polynomial = 0xEDB88320;

// Function to generate CRC Table 
void generate_crc_table(){
    for(int i=0; i<256; i++){
        uint32_t crc = i;
        for(int j=0; j<8; j++){
            if(crc & 1){
                crc = (crc >> 1) ^ crc_polynomial;
            }else{
                crc >>= 1;
            }
        }
        crc_table[i] = crc;
    }
}

uint32_t crc32(gene_node_t* gene){
    uint32_t crc = 0xffffffff;
    while(gene != NULL){
        crc = crc_table[(crc ^ gene->base) & 0xff] ^ (crc >> 8);
        gene = gene->next;
    }
    return crc ^ 0xffffffff;
}

void print_gene(gene_node_t* gene){
    while(gene != NULL){
        printf("%c", gene->base);
        gene = gene->next;
    }
    printf("\n");
}

gene_node_t* create_gene_base(){
    gene_node_t* start = NULL;
    for(int i=0; i<GENOME_SIZE; i++){
        gene_node_t* node = (gene_node_t*)malloc(sizeof(gene_node_t));
        node->base = "ACGT"[rand()%4];
        node->position = i;
        node->next = start;
        start = node;
    }
    return start;
}

gene_node_t* create_mutant_gene(gene_node_t* parent_gene, double mutation_rate){
    gene_node_t* mutant_gene = NULL;
    while(parent_gene != NULL){
        gene_node_t* node = (gene_node_t*)malloc(sizeof(gene_node_t));
        node->position = parent_gene->position;
        if((double)rand()/RAND_MAX < mutation_rate){
            node->base = "ACGT"[rand()%4];
        }else{
            node->base = parent_gene->base;
        }
        node->next = mutant_gene;
        mutant_gene = node;
        parent_gene = parent_gene->next;
    }
    return mutant_gene;
}

int main(){
    generate_crc_table();
    srand(time(NULL));
    gene_node_t* parent_gene = create_gene_base();
    printf("Parent Gene:\n");
    print_gene(parent_gene);
    uint32_t crc32_parent = crc32(parent_gene);
    printf("CRC32 of Parent Gene:  0x%08x\n", crc32_parent);

    int num_mutations = 20;
    printf("Mutated Genes:\n");
    for(int i=1; i<=num_mutations; i++){
        double mutation_rate = (double)i/num_mutations;
        gene_node_t* mutant_gene = create_mutant_gene(parent_gene, mutation_rate);
        printf("Mutation Rate %2d%%:\n", (int)(mutation_rate*100));
        print_gene(mutant_gene);
        uint32_t crc32_mutant = crc32(mutant_gene);
        printf("CRC32 of Mutant Gene:  0x%08x\n", crc32_mutant);
        free(mutant_gene);
    }

    free(parent_gene);
    return 0;
}