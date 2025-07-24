//FormAI DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define THRESHOLD 120

int main(void) {

    // initialize random seed
    srand(time(NULL));

    int data[SIZE];
    int i;
    int above_threshold = 0;

    // generate random data set
    for(i = 0; i < SIZE; i++)
        data[i] = rand() % 200;

    // count number of values above threshold
    for(i = 0; i < SIZE; i++){
        if(data[i] > THRESHOLD)
            above_threshold++;
    }

    // print results
    printf("Data set: ");
    for(i = 0; i < SIZE; i++)
        printf("%d ", data[i]);
    printf("\n");

    printf("Number of values above threshold (%d): %d\n", THRESHOLD, above_threshold);

    return 0;
}