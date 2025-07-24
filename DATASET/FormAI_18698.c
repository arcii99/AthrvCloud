//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Genome Sequencing Simulator!\n");
    printf("Enter the length of the genome sequence you want to create:\n");
    int length;
    scanf("%d", &length);
    
    char* sequence = (char*) malloc(sizeof(char) * length);

    printf("Generating genome sequence...\n");
    for (int i = 0; i < length; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
    
    printf("Done!\n");
    printf("Here is your genome sequence:\n%s\n", sequence);
    
    free(sequence);
    
    printf("Thanks for using the C Genome Sequencing Simulator!\n");
    return 0;
}