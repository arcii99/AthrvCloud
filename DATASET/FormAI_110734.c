//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BASES 5000 // maximum number of DNA bases to simulate

int main() {
    srand(time(NULL)); // seed for rand()

    char bases[MAX_BASES + 1]; // array to store DNA bases
    int num_bases; // actual number of DNA bases to simulate

    printf("Enter number of DNA bases to simulate (maximum %d): ", MAX_BASES);
    scanf("%d", &num_bases);

    if (num_bases > MAX_BASES) {
        printf("Error: Maximum number of bases exceeded!\n");
        return 1; // exit program with error code
    }

    // simulate DNA bases randomly
    for (int i = 0; i < num_bases; i++) {
        int rand_num = rand() % 4; // generate random number from 0 to 3
        switch (rand_num) {
            case 0:
                bases[i] = 'A'; // adenine
                break;
            case 1:
                bases[i] = 'C'; // cytosine
                break;
            case 2:
                bases[i] = 'G'; // guanine
                break;
            case 3:
                bases[i] = 'T'; // thymine
                break;
        }
    }

    printf("DNA Sequencing Results:\n%s\n", bases);

    return 0; // exit program with success code
}