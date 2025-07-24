//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define PERCENT_A 0.25
#define PERCENT_T 0.25
#define PERCENT_C 0.25
#define PERCENT_G 0.25

char generate_base() {
    float r = rand() / (float) RAND_MAX;
    if (r < PERCENT_A) {
        return 'A';
    } else if (r < PERCENT_A + PERCENT_T) {
        return 'T';
    } else if (r < PERCENT_A + PERCENT_T + PERCENT_C) {
        return 'C';
    } else {
        return 'G';
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Genome Sequencing Simulator!\n\n");
    char sequence[MAX_LENGTH];
    int length;

    do {
        printf("Enter the length of the sequence to generate (1-100): ");
        scanf("%d", &length);
    } while (length < 1 || length > 100);

    for (int i = 0; i < length; i++) {
        sequence[i] = generate_base();
        printf("%c", sequence[i]);
    }
    printf("\n");

    return 0;
}