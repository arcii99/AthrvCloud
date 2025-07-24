//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Allocate memory for two arrays of 10000 integers
    int* array1 = (int*) malloc (10000 * sizeof(int));
    int* array2 = (int*) malloc (10000 * sizeof(int));
    
    // Initialize the arrays
    for (int i=0; i<10000; i++) {
        array1[i] = i;
        array2[i] = i+1;
    }
    
    // Calculate the dot product of the arrays
    long dot_product = 0;
    for (int i=0; i<10000; i++) {
        dot_product += array1[i] * array2[i];
    }
    
    // Print the dot product
    printf("Dot Product: %ld\n", dot_product);
    
    // Free the memory
    free(array1);
    free(array2);
    
    return 0;
}