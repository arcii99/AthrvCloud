//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LENGTH 10

int main()
{
    srand(time(NULL));

    char *genome = (char *) malloc((DNA_LENGTH + 1) * sizeof(char));
    if (genome == NULL)
    {
        printf("Failed to allocate memory\n");
        exit(1);
    }

    printf("Generating random genome...\n");

    for (int i = 0; i < DNA_LENGTH; i++)
    {
        char base;
        int r = rand() % 4;
        switch (r)
        {
            case 0: base = 'A'; break;
            case 1: base = 'C'; break;
            case 2: base = 'G'; break;
            case 3: base = 'T'; break;
        }
        genome[i] = base;
    }
    genome[DNA_LENGTH] = '\0';

    printf("Genome generated: %s\n", genome);

    free(genome);

    return 0;
}