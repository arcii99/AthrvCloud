//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 1000000

int main() {
    int *arr = malloc(sizeof(int) * ARRAY_SIZE); // allocate memory for array dynamically
    if(arr == NULL) {
        printf("Error allocating memory\n");
        return -1;
    }
    
    // initialize array
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = i;
    }
    
    // print sum of elements in odd positions
    int sum = 0;
    for(int i=1; i<ARRAY_SIZE; i+=2) {
        sum += arr[i];
    }
    printf("Sum of elements in odd positions: %d\n", sum);
    
    free(arr); // free the allocated memory
    return 0;
}