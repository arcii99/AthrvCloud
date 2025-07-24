//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(int seconds) { // this function is to simulate waiting for a certain time
    clock_t end_wait;
    end_wait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_wait) {}
}

int main() {
    int genome[100];
    int i;

    srand(time(NULL)); // initialize random seed

    printf("Simulating genome sequencing process...\n\n");

    printf("Starting sequencing machine...\n\n");

    wait(3);

    for(i=0; i<100; i++) { // generate random genome sequence
        genome[i] = rand() % 4;
    }

    printf("Genome sequence: ");

    for(i=0; i<100; i++) { // display genome sequence
        printf("%d", genome[i]);
    }

    printf("\n\nAnalyzing genome sequence...\n\n");

    wait(5);

    printf("Possible genetic disorders detected: none.\n");

    printf("\nGenome sequencing process complete.\n");

    return 0;
}