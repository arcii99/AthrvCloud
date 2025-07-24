//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    char base[4] = {'A', 'T', 'C', 'G'};
    char sequence[1000];
    int i, length;

    printf("Welcome to the Genome Sequencing Simulator!\n\n");

    printf("Enter the length of the sequence you would like to generate: ");
    scanf("%d", &length);

    printf("\nGenerating genome sequence...\n\n");

    for(i=0; i<length; i++){
        sequence[i] = base[rand()%4];
    }

    printf("Genome sequence generated!\n\n");

    printf("The generated genome sequence of length %d is: ", length);

    for(i=0; i<length; i++){
        printf("%c", sequence[i]);
        if((i+1)%50 == 0) printf("\n");
    }

    printf("\n\n");

    return 0;
}