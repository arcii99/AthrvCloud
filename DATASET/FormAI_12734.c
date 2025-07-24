//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

// Function to compare integers (for quicksort algorithm)
int compare(const void *a, const void *b) {
    const int *x = (const int *) a;
    const int *y = (const int *) b;
    return *x - *y;
}

int main() {
    int array[ARRAY_SIZE];
    
    // Populate array with random integers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }
    
    // Sort array using quicksort algorithm
    qsort(array, ARRAY_SIZE, sizeof(int), compare);
    
    // Print sorted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}