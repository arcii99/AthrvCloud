//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define THRESHOLD 0.6

void init(int array[SIZE][SIZE]); 
void printArray(int array[SIZE][SIZE]);
int isPercolated(int array[SIZE][SIZE]);

int main() {
    int array[SIZE][SIZE]; 
    int percolated; 

    init(array);
    printf("Initial state:\n");
    printArray(array);

    percolated = isPercolated(array);
    if (percolated) {
        printf("The system has already percolated.\n");
    } else {
        printf("The system has not percolated yet.\n");
        printf("Start percolating...\n\n");

        /* Randomly change the values in the array */
        srand(time(NULL)); 
        int i, j; 
        while (1) {
            i = rand() % SIZE;
            j = rand() % SIZE;
            if ((float)rand() / RAND_MAX < THRESHOLD) {
                array[i][j] = 1; 
            }

            if (isPercolated(array)) {
                printf("The system has percolated. Final state:\n");
                printArray(array);
                break;
            }
        }
    }

    return 0;
}

void init(int array[SIZE][SIZE]) {
    /* Initialize the array with 0s */
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            array[i][j] = 0;
        }
    }

    /* Initialize the top row with 1s */
    for (i = 0; i < SIZE; i++) {
        array[0][i] = 1;
    }
}

void printArray(int array[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isPercolated(int array[SIZE][SIZE]) {
    int top[SIZE] = {0}; 
    int bottom[SIZE] = {0}; 
    int i, j;

    /* Check if there is any 1 in the top row */
    for (i = 0; i < SIZE; i++) {
        if (array[0][i] == 1) {
            top[i] = 1; 
        }
    }

    /* Check if there is any 1 in the bottom row */
    for (i = 0; i < SIZE; i++) {
        if (array[SIZE-1][i] == 1) {
            bottom[i] = 1; 
        }
    }

    /* Check if top and bottom are connected */
    for (i = 0; i < SIZE; i++) {
        if (top[i] == 1) {
            for (j = 0; j < SIZE; j++) {
                if (bottom[j] == 1 && array[SIZE-1][j] == 1) {
                    return 1; 
                }
            }
        }
    }

    return 0; 
}