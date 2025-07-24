//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define ERR_RATE 0.01

int main()
{
    char sequence[SEQUENCE_LENGTH];
    int i, j;
    double rnd;
    int qscore;

    // Generate random DNA sequence
    srand(time(NULL));
    for (i=0; i<SEQUENCE_LENGTH; i++) {
        rnd = (double)rand() / RAND_MAX;
        if (rnd < 0.25)
            sequence[i] = 'A';
        else if (rnd < 0.5)
            sequence[i] = 'C';
        else if (rnd < 0.75)
            sequence[i] = 'G';
        else
            sequence[i] = 'T';
    }

    // Simulate sequencing and calculate quality scores
    printf("@Sequence_ID\n");
    for (i=0; i<SEQUENCE_LENGTH; i++) {
        rnd = (double)rand() / RAND_MAX;
        if (rnd < ERR_RATE) {
            // sequencing error occurred
            qscore = 1;
            rnd = (double)rand() / RAND_MAX;
            if (rnd < 0.25)
                sequence[i] = 'A';
            else if (rnd < 0.5)
                sequence[i] = 'C';
            else if (rnd < 0.75)
                sequence[i] = 'G';
            else
                sequence[i] = 'T';
        } else {
            // no error occurred
            qscore = 40;
        }
        printf("%c\n+\n%c\n", sequence[i], qscore);
    }

    return 0;
}