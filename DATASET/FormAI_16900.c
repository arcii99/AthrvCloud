//FormAI DATASET v1.0 Category: Computer Biology ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DNA {
    char gene[10];
    int length;
    double gc_content;
};

int main() {
    struct DNA dna1, dna2;
    double total_gc_content;
    
    printf("Enter gene sequence for DNA 1: ");
    scanf("%s", dna1.gene);
    dna1.length = strlen(dna1.gene);
    
    printf("Enter gene sequence for DNA 2: ");
    scanf("%s", dna2.gene);
    dna2.length = strlen(dna2.gene);
    
    total_gc_content = ((double) count_gc(dna1.gene, dna1.length) + 
                        (double) count_gc(dna2.gene, dna2.length)) / 2.0;
    
    printf("Average GC content for DNA 1 and DNA 2: %.2lf %%\n", total_gc_content);
    
    return 0;
}

int count_gc(char *gene, int length) {
    int i, gc_count = 0;
    
    for (i = 0; i < length; i++) {
        if (gene[i] == 'G' || gene[i] == 'C') {
            gc_count++;
        }
    }
    
    return gc_count;
}