//FormAI DATASET v1.0 Category: Computer Biology ; Style: brave
#include<stdio.h>

//Defining struct for DNA sequence
struct DNA {
    char base[1000];
    int len;
};

//Function to compare two DNA sequences
int compare(char* s1, char* s2, int n) {
    int count = 0, i;
    for(i=0; i<n; i++) {
        if(s1[i] != s2[i])
            count++;
    }
    return count;
}

//Function to count the number of mutations in two DNA sequences
void count_mutations(struct DNA d1, struct DNA d2) {
    if(d1.len != d2.len) {
        printf("Cannot compare sequences of different lengths.\n");
        return;
    }
    int mutations = compare(d1.base, d2.base, d1.len);
    printf("Number of mutations between the sequences: %d\n", mutations);
}

int main() {
    struct DNA dna1, dna2;
    printf("Enter the first DNA sequence: ");
    scanf("%s", dna1.base);
    dna1.len = strlen(dna1.base);
    printf("Enter the second DNA sequence: ");
    scanf("%s", dna2.base);
    dna2.len = strlen(dna2.base);
    count_mutations(dna1, dna2);
    return 0;
}