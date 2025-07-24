//FormAI DATASET v1.0 Category: Computer Biology ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Gene {
    char sequence[21];
    int length;
    int index;
} Gene;

void generateRandomSequence(char *sequence, int length) {
    char bases[] = {'A', 'T', 'C', 'G'};
    for(int i=0; i<length; i++) {
        sequence[i] = bases[rand() % 4];
    }
    sequence[length] = '\0';
}

void sortGenes(Gene *genes, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(genes[j].length < genes[i].length) {
                Gene tmp = genes[i];
                genes[i] = genes[j];
                genes[j] = tmp;
            }
        }
    }
}

void printGenes(Gene *genes, int size) {
    for(int i=0; i<size; i++) {
        printf("%d: %s\n", genes[i].index, genes[i].sequence);
    }
}

void saveToFile(char *filename, Gene *genes, int size) {
    FILE *fp = fopen(filename, "w");
    for(int i=0; i<size; i++) {
        fprintf(fp, "%s\n", genes[i].sequence);
    }
    fclose(fp);
}

int main() {
    srand(time(NULL));
    int numGenes = 10;
    Gene genes[numGenes];
    for(int i=0; i<numGenes; i++) {
        generateRandomSequence(genes[i].sequence, rand() % 20 + 1);
        genes[i].length = strlen(genes[i].sequence);
        genes[i].index = i+1;
    }
    printf("Unsorted genes:\n");
    printGenes(genes, numGenes);
    sortGenes(genes, numGenes);
    printf("Sorted genes:\n");
    printGenes(genes, numGenes);
    saveToFile("genes.txt", genes, numGenes);
    return 0;
}