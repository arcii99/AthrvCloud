//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main()
{
    int sequence[N];
    int base_count[4] = {0, 0, 0, 0};
    int i, j, random_base;
    float frequency[4];

    // Generating random bases for the sequence
    srand(time(NULL));

    for(i=0; i<N; i++)
    {
        random_base = rand() % 4;
        sequence[i] = random_base;

        base_count[random_base]++;
    }

    // Calculating frequency of each base
    for(i=0; i<4; i++)
    {
        frequency[i] = (float) base_count[i] / N;
    }

    // Outputting the results
    printf("Sequence:\n");

    for(i=0; i<N; i++)
    {
        switch(sequence[i])
        {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
    }

    printf("\n\n");

    printf("Base count:\n");
    printf("A: %d\n", base_count[0]);
    printf("C: %d\n", base_count[1]);
    printf("G: %d\n", base_count[2]);
    printf("T: %d\n", base_count[3]);

    printf("\n");

    printf("Frequency:\n");
    printf("A: %f\n", frequency[0]);
    printf("C: %f\n", frequency[1]);
    printf("G: %f\n", frequency[2]);
    printf("T: %f\n", frequency[3]);

    return 0;
}