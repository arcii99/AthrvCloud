//FormAI DATASET v1.0 Category: Benchmarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int main() {
    int i, j, temp;
    int data[ARRAY_SIZE];

    printf("Generating random data...\n");
    srand(time(NULL));

    for(i = 0; i < ARRAY_SIZE; i++) {
        data[i] = rand();
    }

    printf("Sorting array...\n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        for(j = 0; j < ARRAY_SIZE - 1; j++) {
            if(data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("Sorting complete!\n");
    return 0;
}