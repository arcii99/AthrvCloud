//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 10000000;
    int *arr = (int*) malloc(size * sizeof(int));
    int i;
    
    // Generate random numbers
    printf("Generating random numbers...\n");
    for(i=0; i<size; i++) {
        arr[i] = rand() % 100;
    }
    
    // Find the sum of all even numbers
    printf("Finding the sum of all even numbers...\n");
    int sum = 0;
    for(i=0; i<size; i++) {
        if(arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    
    printf("The sum of all even numbers is %d.\n", sum);
    
    free(arr);
    
    return 0;
}