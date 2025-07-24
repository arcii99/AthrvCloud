//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int sequence_length, i;

    printf("***Welcome to the C Genome Sequencing Simulator***\n\n");
    printf("Please enter the length of your desired sequence: ");
    scanf("%d", &sequence_length);

    printf("Your generated sequence is: ");
    for(i = 0; i < sequence_length; i++) {
        int random_index = rand() % 4;
        printf("%c", nucleotides[random_index]);
    }

    printf("\n\nThank you for using the C Genome Sequencing Simulator!");
    return 0;
}