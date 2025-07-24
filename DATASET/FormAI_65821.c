//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char Bases[4] = {'A', 'C', 'G', 'T'};
    printf("Enter length of sequence: ");
    int length;
    scanf("%d", &length);
    char* sequence = malloc(length * sizeof(char));
    for(int i=0; i<length; i++) {
        sequence[i] = Bases[rand() % 4];
    }
    printf("Sequence: ");
    for(int i=0; i<length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
    free(sequence);
    return 0;
}