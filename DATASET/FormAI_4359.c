//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main(){

    // Allocate memory for an array of integers
    int *numbers = (int*) malloc(5 * sizeof(int));
    if(numbers == NULL){
        printf("Memory allocation unsuccessful\n");
        exit(0);
    }
    
    printf("Size of numbers before reallocation: %d\n", sizeof(numbers));
    
    // Reallocate memory to increase the size of the array
    numbers = (int*) realloc(numbers, 10 * sizeof(int));
    if(numbers == NULL){
        printf("Memory reallocation unsuccessful\n");
        exit(0);
    }
    
    printf("Size of numbers after reallocation: %d\n", sizeof(numbers));
    
    // Set values for the first 5 elements of the array
    for(int i=0; i<5; i++){
        numbers[i] = i+1;
    }
    
    // Print the elements of the array
    printf("The elements of the array: ");
    for(int i=0; i<5; i++){
        printf("%d ", numbers[i]);
    }
    
    // Free the memory
    free(numbers);
    
    return 0;
}