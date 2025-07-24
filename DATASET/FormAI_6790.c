//FormAI DATASET v1.0 Category: Computer Biology ; Style: surprised
#include <stdio.h>

int main() {

    printf("Oh wow, I can't believe I just created a C program for Biology! \n");
    printf("Let's simulate a bacterial colony growth algorithm...\n\n");

    int numCells = 1;
    int growthFactor = 2;
    int hoursToDouble = 1;
    int totalHours = 24;

    printf("Number of cells at t=0: %d \n", numCells);

    for(int i = 1; i <= totalHours; i++) {
        numCells *= growthFactor;
        printf("Number of cells at t=%d: %d\n", i, numCells);

        int numBacteria = numCells * 10000;
        float volume = numBacteria * 0.000001;
        printf("Number of bacteria at t=%d: %d\n", i, numBacteria);
        printf("Volume of bacteria at t=%d: %f ml\n", i, volume);

        if (numCells >= 1000000) {
            printf("\nOh no, the bacterial colony has reached a million cells!\n");
            printf("Time to start considering antibiotics...\n");
            break;
        }

        if (i % hoursToDouble == 0) {
            growthFactor *= 2;
            printf("\nThe bacterial colony has doubled in size!\n");
            printf("Growth factor increased to %d\n", growthFactor);
        }
    }

    printf("\nSimulation complete. Goodbye!\n");

    return 0;
}